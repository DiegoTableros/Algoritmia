#include <bits/stdc++.h>
using namespace std;
int n,mod,aux,b;
string np;
int arre[1003];

void suma(int sum) {
  	arre[np.size()]+=sum;
	for(int i=np.size(); i>0; i--) {
      	if(arre[i]>=10) {
        	arre[i]=arre[i]%10;
          	arre[i-1]+=1;
        }
    }
}

void leer() {
	cin >> np;
  	for(int i=np.size()-1; i>=0; i--) {
      	char aux=np[i];
      	switch(aux) {
        	case '1': arre[i+1]=1; break;
          	case '2': arre[i+1]=2; break;
          	case '3': arre[i+1]=3; break;
          	case '4': arre[i+1]=4; break;
          	case '5': arre[i+1]=5; break;
          	case '6': arre[i+1]=6; break;
          	case '7': arre[i+1]=7; break;
          	case '8': arre[i+1]=8; break;
          	case '9': arre[i+1]=9; break;
          	case '0': arre[i+1]=0; break;
        }
    }
  	///Despues de esto el numero ya está en arre[1002] desde 1 hasta el tamaño
}

int modulocho(){
  	aux=0;
  	for(int i=np.size(); i>=1; i--) {
    	if(i==np.size()) {
        	aux+=arre[i];
        } else if(i==np.size()-1) {
        	aux+=arre[i]*10;
        } else {
          	aux+=arre[i]*100;
          	break;
        }
    }
  	return aux%8;
}

void imprimir() {
  	///Por si quedo un 1 en la posicion 0
  	if(arre[0]!=0) {
    	cout << arre[0];
    }
	for(int i=1; i<=np.size(); i++) {
    	cout << arre[i];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    leer();
  	b=modulocho();
  	switch(b){
      case 0: suma(0); break;
      case 1: suma(4); break;
      case 2: suma(3); break;
      case 3: suma(2); break;
      case 4: suma(1); break;
      case 5: suma(0); break;
      case 6: suma(2); break;
      case 7: suma(1); break;
    }
  	imprimir();
	return 0;
}
