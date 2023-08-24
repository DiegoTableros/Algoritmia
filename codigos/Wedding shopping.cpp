/*
dp(i, dinero)=	CASOS BASE
				-infty	si	dinero<0
				0		si	dinero>=0 && i==n

                MEMORIZADO
                Si memo[i][dinero] ya esta lleno, devuelves eso para no tener que hacerlo
                esta tabla es de tamaño memo[n][dinero maximo]

                CASO GENERAL
                Tienes que generar tantas ramas como elementos en el arreglo actual
                y de lo que te retornen sacas el maximo

                for(x=0, x=elemento final del arreglo i)
                respuesta=max( respuesta, dp(i+1,dinero-g[i][x])+g[i][x] )

                MEMORIZADO
                Guardas en memo[i][dinero] la respuesta
                return respuesta
*/
#include <bits/stdc++.h>
using namespace std;
int m, c, n, k;
int mem[201][21];
vector <int> g[20];
pair <int,int> estado;

int dp(int i, int M) {
  	int res=INT_MIN;
	if(M<0) {
    	return INT_MIN;
    }
  	if(M>=0 && i==m) {
    	return 0;
    }
  	if(mem[i][M]!=0) {
    	return mem[i][M];
    }
  	for(int j=0; j<g[i].size(); j++) {
    	res=max(res,dp(i+1,M-g[i][j])+g[i][j]);
    }
  	mem[i][M]=res;
  	return res;
}

int main() {
  	ios_base::sync_with_stdio(0); cin.tie(0);
  	cin >> n;
  	for(int i=0; i<n; i++) {
    	cin >> m >> c;
      	for(int j=0; j<c; j++) {
        	cin >> k;
         	for(int s=0; s<k; s++) {
             	int aux;
              	cin >> aux;
              	g[j].push_back(aux);
            }
        }
      	int res=dp(0,m);
      	if(res>=0) {
			cout << res << "\n";
        }else {
        	cout << "no solution\n";
        }
      	memset(mem,0,sizeof(mem));
      	for(int l=0; l<c; l++) {
         	g[l].clear();
        }
    }
	return 0;
}
