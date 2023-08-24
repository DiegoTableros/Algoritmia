/*
   1  2  3  4  5		   1  2  3  4  5
   _____________		   _____________
1| 2  5  4  8  3		1| 1  1  1  1  1
2| 9  10 11 5  1		2| 1  1  1  0  0
3| 12 8  4  2  5		3| 0  0  0  0  0
4| 2  2  5  4  1		4| 0  0  0  0  0
5| 6  8  2  4  2		5| 0  0  0  0  0

*(0,2,1,1)
*(2,3,1,2)
(6,3,2,1)
*(2,4,1,3)
(6,4,2,2)
**(5,5,1,4)
(8,5,2,3)
(8,3,1,5)
*/
#include <bits/stdc++.h>
using namespace std;
int t,n,m;
long long int matriz[102][102];
typedef long long int lli;
typedef pair<lli,lli> ii;
typedef pair<ii,ii> iiii;
bool visit[102][102];

void busqueda() {
  	priority_queue <iiii> cola;
	iiii act,aux;
  	cola.push(make_pair(make_pair(0,matriz[1][1]),make_pair(1,1)));
  	visit[1][1]=1;
    while(!cola.empty()) {
    	act=cola.top();
      	cola.pop();
      	///Revertimos los cambios
      	act.first.first*=-1;

      	lli num=act.first.second;
      	///Chequeo de respuesta
      	if(act.second.first==n && act.second.second==m) {
        	cout << act.first.first << "\n";
          	return;
        }
      	///Mov1: A la derecha
      	aux=act;
      	aux.second.second++;
      	if(aux.second.first<=n && aux.second.second<=m && !visit[aux.second.first][aux.second.second]) {
            visit[aux.second.first][aux.second.second]=1;
          	if(num==matriz[aux.second.first][aux.second.second]-1) {
            	///Caso en donde no se hace nada
              	aux.first.second=num+1;
            } else if(num<matriz[aux.second.first][aux.second.second]){
            	///Nosotros somos menores, le restamos a el y nos quedamos con su numero
              	aux.first.second=num+1;
              	aux.first.first+=abs(matriz[aux.second.first][aux.second.second]-num-1);
            } else {
              	///Nosotros somos mayores o iguales, nos restamos
              	aux.first.second=matriz[aux.second.first][aux.second.second];
              	aux.first.first+=abs(num-matriz[aux.second.first][aux.second.second]+1);
            }
          	///Aplicamos el cambio
          	aux.first.first*=-1;
          	cola.push(aux);
        }

      	///Mov2: Hacia abajo
      	aux=act;
      	aux.second.first++;
      	if(aux.second.first<=n && aux.second.second<=m && !visit[aux.second.first][aux.second.second]) {
            visit[aux.second.first][aux.second.second]=1;
          	if(num==matriz[aux.second.first][aux.second.second]-1) {
            	///Caso en donde no se hace nada
              	aux.first.second=matriz[aux.second.first][aux.second.second];
            } else if(num<matriz[aux.second.first][aux.second.second]){
            	///Nosotros somos menores, le restamos a el y nos quedamos con su numero
              	aux.first.second=num+1;
              	aux.first.first+=(matriz[aux.second.first][aux.second.second]-num-1);
            } else {
              	///Nosotros somos mayores o iguales, nos restamos
              	aux.first.second=matriz[aux.second.first][aux.second.second];
              	aux.first.first+=num-matriz[aux.second.first][aux.second.second]+1;
            }
          	aux.first.first*=-1;
          	cola.push(aux);
        }
    }
}

void altura_minima(){
	cin >> n >> m;
	for(int a=1;a<=n;a++){
    	for(int b=1;b<=m;b++){
      		cin >> matriz[a][b];
    	}
  	}
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
  	for(int z=1;z<=t;z++){
    	altura_minima();
      	busqueda();
      	memset(visit,0,sizeof(visit));
    }
    return 0;
}
