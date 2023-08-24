#include <bits/stdc++.h>
using namespace std;
char numero[102];
vector <long long int> vec;
long long int n,num,res;

void leer() {
	cin >> n;
	cin.getline(numero,100);
  	for(int i=1; i<=n; i++) {
    	cin.getline(numero,100);
      	///Si el numero que leimos tiene menos de 8 cifras, es candidato
      	if(strlen(numero)<=8) {
        	///Volvemos numero al string
          	num=atoi(numero);
          	///Ahora lo ponemos en el vector si no es negativo
          	if(num>=0) {
                //cout << "Numero valido: " << num << "\n";
            	vec.push_back(num);
            }
        }
    }
  	///Ordenamos los numeros validos
  	sort(vec.begin(),vec.end());
  	///Ahora vamos buscando
  	res=0;
  	for(int i=0; i<vec.size(); i++) {
    	if(res!=vec[i]) {
        	cout << res;
          	return;
        } else {
          	res++;
        }
    }
  	cout << res;
  	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  	leer();
  	return 0;
}
