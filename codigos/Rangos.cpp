/*
 * Casos:
 *
 *
 *                    ini                                     fin
 *   [---------------------------------------]
 *             x                                   y
 *             4   5   6   7   8   9  10  11  12   13  14  15  16
 *            +1  +2  +3  +4  +5  +6  +7  +8  +9  +10
 *                     ^(ini-x)                    ^(y-x+1)
 * -------------> ini>x && fin<y
 *
 *
 *  [-----]
 *     ++++++
 * --------------> ini<x && fin>=x && fin<y
 *
 *       [-----]
 *     +++++
 * --------------> ini>x && ini<=y && fin>y
 */
#include <bits/stdc++.h>
using namespace std;
#define MOD 10000
pair<int,int> act[1002];
int n,a,p;

int sumatoria(int N) {
	long long int res;
  	res=N*(N+1);
  	res/=2;
  	///Sacamos modulo antes de regresar
  	res%=MOD;
  	return (int)res;
}

int pregunta(int ini, int fin) {
  	int suma=0;
	for(int i=1; i<=a; i++){
    	int x=act[i].first,y=act[i].second;
    	if(ini<=x && fin>=y){
      		suma+=sumatoria(y-x+1);
          	suma%=MOD;
      	}else if(ini>x && fin<y){
        	suma+=sumatoria(y-fin);
          	suma%=MOD;
        	suma-=sumatoria(ini-x);
          	suma%=MOD;
        }else if(ini<x && fin>=x && fin<y){
            suma+=sumatoria(fin-x+1);
          	suma%=MOD;
        } else if(ini>x && ini<=y && fin>y) {
        	suma+=sumatoria(y-x+1);
          	suma%=MOD;
          	suma-=sumatoria(ini-x);
          	suma%=MOD;
        }
    }
  	return suma%=MOD;
}

void leer(){
  	int x,y;
	cin >> n >> a >> p;
  	for(int i=1; i<=a; i++) {
    	cin >> act[i].first >> act[i].second;
    }
  	for(int i=1; i<=p; i++) {
		cin >> x >> y;
      	cout << pregunta(x,y) << "\n";
    }
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
	leer();
  	return 0;
}
