#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>

using namespace std;

long long int visit[1002][1002];
long long int coef[1002][1002];
long long int n, coeficiente,expa,expb;

long long int cb(int n, int k){
	if (k==0){
	    return 1;
	}
    if(n==0) {
        return 0;
    }
    if(coef[n][k]!=0 || coef[k][n]!=0) {
        return coef[n][k];
    }
    if(visit[n][k]!=0) {
        return visit[n][k];
    }
    coef[n][k]=visit[n][k]=cb(n-1,k)+cb(n-1,k-1);
	return visit[n][k];
}

int main(){
  	cout << "El teorema del Binomio, (a+b)^n con n natural\n";
  	cout << "Digite n: ";
  	//n=66;
    cin>>n;
  	for(int k=0; k<=n; k++) {
      	coeficiente=cb(n,k);
      	if(coeficiente!=1) {
        	cout << coeficiente;
        }
      	expa=n-k;
      	if(expa==1) {
          	cout << " a ";
        } else if(expa!=0){
            cout << " a^" << expa << " ";
        }
      	expb=k;
      	if (expb==1){
          cout << " b ";
        } else if(expb!=0) {
          	cout << " b^" << expb << " ";
        }
      	if(k!=n) {
        	cout << " + ";
        }
        cout << "\n";
    }
  	return 0;
}
