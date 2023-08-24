#include <bits/stdc++.h>
using namespace std;
long long int arre[100002];
long long int n,cap,cont;

void leer() {
	cin >> n >> cap;
  	for(int i=1; i<=n; i++) {
    	cin >> arre[i];
    }
  	sort(arre+1,arre+n+1);
  	long long int ini=1,fin=n;
  	while(ini<=fin) {
      	if(ini==fin){
          	ini++;
          	fin--;
        	cont++;
        } else {
    		if(arre[ini]+arre[fin]<=cap) {
        		ini++;
          		fin--;
          		cont++;
        	} else {
        		fin--;
          		cont++;
        	}
        }
    }
  	cout << cont;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
	leer();
  	return 0;
}
