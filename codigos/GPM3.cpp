#include <iostream>
#include <string>
using namespace std;
string s;
int numeros[12];
bool eliminados[1002];

int con(char x){
  	switch (x) {
        case '1':return 1;break;
        case '2':return 2;break;
        case '3':return 3;break;
        case '4':return 4;break;
        case '5':return 5;break;
        case '6':return 6;break;
        case '7':return 7;break;
        case '8':return 8;break;
        case '9':return 9;break;
        case '0':return 0;break;
        default: break;
    }

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> s;
	for(int i=1; i<=9; i++) {
     cin >> numeros[i];
    }
  	for(int j=1; j<=9; j++) {
     	int izq=0,der=s.size()-1;
      	if(numeros[j]==0) {
        	continue;
        }
      	while(con(s[izq])!=j && izq<s.size()) {
        	izq++;
        }
      	while(con(s[der])!=j && der>=0) {
        	der--;
        }
      	///Elminamos cantidad de veces
      	while(numeros[j]>0) {
        	if(con(s[izq])>=con(s[izq+1])) {
            	eliminados[der]=1;
              	der--;
              	while(con(s[der])!=j && der>=0) {
        			der--;
        		}
            } else {
            	eliminados[izq]=1;
              	izq++;
              	while(con(s[izq])!=j && izq<s.size()) {
        			izq++;
        		}
            }
          	numeros[j]--;
        }
    }
	for(int i=0; i<s.size(); i++) {
    	if(eliminados[i]==0) {
        	cout << s[i];
        }
    }
    cout << "\n";
    return 0;
}

