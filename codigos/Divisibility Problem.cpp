#include <bits/stdc++.h>
using namespace std;

long long int t,n,n_tri,k,pos1B,pos2B;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  	cin >> t;
  	for(int x=1; x<=t; x++) {
    	cin >> n >> k;
      	///Sacamos el numero triangular mas proximo
      	n_tri=(sqrt(1.0+(8.0*k))/2.0)-0.5;
      	///Sacamos la posicion de la primera B
      	if((n_tri*(n_tri+1))/2==k) {
        	pos1B=n_tri+1;
        } else {
      		pos1B=n_tri+2;
        }
        if(pos1B>n) {
        	pos1B=n;
        }
      	///Sacamos la posicion de la segunda B
      	pos2B=k-((n_tri*(n_tri+1))/2);
      	if(pos2B==0) {
        	pos2B=pos1B-1;
        }
      	///Caso K=1
      	if(k==1) {
        	pos1B=2;
          	pos2B=1;
        }
      	for(int i=n; i>0; i--) {
        	if(i==pos1B || i==pos2B) {
            	cout << "b";
            } else {
              	cout << "a";
            }
        }
      	cout << "\n";
    }
  	return 0;
}
