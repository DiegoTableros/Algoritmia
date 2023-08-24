#include <bits/stdc++.h>
using namespace std;

short N,D;
struct carta{
	short precio;
  	short valor;
};
///Este arreglo guarda los datos de las cartas
carta arre[502];
///MEMORIZADO
///En la primera dimension va el maximo valor de i
///En la segunda dimension va el maximo valor de d
short memorizado[502][10002];

///Programando la func. mat.
short arbol(short i, short d) {
  	///CASOS BASE
	if(i>N && d>=0) {
    	return 0;
    }
  	if(d==0) {
    	return 0;
    }
  	if(d<0) {
    	return SHRT_MIN;
    }
  	///Checamos SI YA LO HABIAMOS CALCULADO
  	if(memorizado[i][d]!=0) {
      	///Retornamos el calculo
    	return memorizado[i][d];
    }
  	short Comprar=arbol(i+1,d-arre[i].precio)+arre[i].valor;
  	short NoComprar=arbol(i+1,d);
  	/*int res=max(Comprar, NoComprar);
  	return res;*/
  	memorizado[i][d]=max(Comprar,NoComprar);
  	return memorizado[i][d];
}

void leer() {
	cin >> D >> N;
  	for(short i=1; i<=N; i++) {
    	cin >> arre[i].precio;
      	cin >> arre[i].valor;
    }
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	leer();
  	///Ahora imprimos lo que devuelva el arbol
  	cout << arbol(1,D);
  	/*
  	 *PRIMER PASO: ARBOL DE BUSQUEDA
     *SEGUNDO PASO: FUNCION MATEMATICA
     *TERCER PASO: FUNCION RECURSIVA (TLE)
     *CUARTO PASO: MEMORIZADO (RTE)
     *QUINTO PASO: OPTIMIZAR MEMORIZADO (AC)
     *SEXTO PASO: BOTTOM-UP (AC con menos tiempo)
     (como la func.recur. llena la tabla, analizar como lo hace
     y despues hacerlo con puras iteraciones (FOR))
  	*/
  	return 0;
}
