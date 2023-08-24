#include <bits/stdc++.h>
using namespace std;
string cadena;
stack <int> inicios;
stack <char> pila;
char letra;

void volteo(int fin) {
	///Si ya encontró un cierre ')' concuerda con el inicio mas reciente
  	int ini=inicios.top();
  	inicios.pop();
  	///Volteamos en el rango (ini,fin)
  	for(int x=ini+1; x<fin; x++) {
    	///Vamos metiendo a la pila
      	pila.push(cadena[x]);
    }
  	///Vaciamos la pila en orden
  	for(int x=ini+1; x<fin; x++) {
    	cadena[x]=pila.top();
      	pila.pop();
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
  	getline(cin,cadena);
  	for(int i=0; i<cadena.size(); i++) {
    	if(cadena[i]=='(') {
        	inicios.push(i);
        }
      	if(cadena[i]==')') {
        	volteo(i);
          	///Despues de esto ya se actualio el pedazo
        }
    }
  	///Imprimimos sin los parentesis que queden
  	for(int i=0; i<cadena.size(); i++) {
    	if(cadena[i]!='(' && cadena[i]!=')') {
        	cout << cadena[i];
        }
    }
  	return 0;
}
