#include <bits/stdc++.h>
using namespace std;
string cadena;
char letra;
int i,n;
bool visit[300];

int pretty() {
  	int letras=0;
	for(; i<cadena.size() && cadena[i]>='a'; i++) {
    	if(visit[(int)cadena[i]]==0) {
        	visit[(int)cadena[i]]=1;
          	letras++;
        }
    }
  	return letras;
}

void leer() {
  	int maximo=0;
  	int aux;
  	cin >> n;
	cin >> cadena;
	for(i=0; i<cadena.size(); i++) {
      	letra=cadena[i];
    	if(letra>='a') {
        	aux=pretty();
          	if(maximo<aux) {
            	maximo=aux;
            }
          	memset(visit,0,sizeof(visit));
        }
    }
  	cout << maximo;
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
  	leer();
  	return 0;
}
