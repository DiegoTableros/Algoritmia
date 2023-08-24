#include <bits/stdc++.h>
using namespace std;
/*
 * Inicialmente llamamos a merge(1,n)
 * merge(ini,fin)
 *      si (fin-ini+1)>2
 *           merge(ini,fin/2)
 * 			 merge(fin/2+1,fin)
 * 	         meter los elementos del arreglo [ini,fin/2] a una cola
 * 	         meter los elementos del arreglo [fin/2+1,fin] a una pila
 * 			 ir comparando los topes (cual es menor) mientras haya elementos en ambas
 * 			     el menor ponerlo en su posicion en el arreglo y eliminarlo
 *           vacia lo que quede en la todavia tenga elementos
 * 		     retorna
 * 	    sino
 * 			 ubicar el caso trivial
 * 			 x=arre[ini], y=arre[fin]
 * 			 arre[ini]=min(x,y)
 * 			 arre[fin]=max(x,y)
 *           retorna
*/

int n;
int num[65538];

void merge(int ini, int fin) {
	if((fin-ini+1)>2){
      	int mitad=(ini+fin)/2;
    	merge(ini,mitad);
      	merge(mitad+1,fin);
      	stack <int> palo;
      	queue <int> colon;
      	for(int i=ini; i<=mitad; i++){
        	colon.push(num[i]);
        }
      	for(int i=mitad+1; i<=fin; i++) {
        	palo.push(num[i]);
        }
      	int i=ini;
      	while(!colon.empty() && !palo.empty()){
        	if(colon.front()>=palo.top()){
              num[i]=palo.top();
              palo.pop();
            }else{
              num[i]=colon.front();
              colon.pop();
            }
          	i++;
        }
      	while(!colon.empty()) {
        	num[i]=colon.front();
          	colon.pop();
          	i++;
        }
      	while(!palo.empty()) {
        	num[i]=palo.top();
          	palo.pop();
          	i++;
        }
    } else {
    	int x,y;
  		x=num[ini];
  		y=num[fin];
      	num[ini]=min(x,y);
      	num[fin]=max(x,y);
      	return;
    }
}

int main() {
  	ios_base::sync_with_stdio(0); cin.tie(0);
  	cin >> n;
  	for(int i=1; i<=n; i++){
		cin >> num[i];
    }
  	if(n>1){
    	merge(1,n);
    }
  	for(int i=1; i<=n; i++) {
    	cout << num[i] << " ";
    }
  	return 0;
}
