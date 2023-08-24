#include <bits/stdc++.h>
using namespace std;
int arre[100002];
int n;

int leer() {
	cin >> n;
  	for(int i=1; i<=n; i++) {
    	cin >> arre[i];
    }
  	int ini=1,fin=1,maximo=0,longitud;
  	///Vamos a calcular la secuencia
  	while(fin<=n) {
      	///Estiramos fin lo mas que podamos
    	while(arre[fin]<=arre[fin+1] && fin+1<=n) {
        	fin++;
        }
      	///En este punto ya se estiró fin, calculamos longitud
      	longitud=fin-ini+1;
      	///Actualizamos el máximo si es necesario
      	if(longitud>maximo) {
        	maximo=longitud;
        }
      	///Finalmente, movemos ambos "ini" y "fin" a "fin+1"
      	ini=fin+1;
      	fin=fin+1;
    }
  	///Retornamos maximo
  	return maximo;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  	cout << leer();
  	return 0;
}
