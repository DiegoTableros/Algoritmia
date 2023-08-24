/*
	LLRL

    	IZQ	DER	CENTRO
    	0/1	1/0	1/1
	L	0/1 1/1 1/2
    L	0/1 1/2 1/3
    R	1/3 1/2	2/5
    L	1/3 2/5 3/8 <<<<
*/
#include <bits/stdc++.h>
using namespace std;
int n;
string cadena;

void proceso(){
  	pair<long long int,long long int> IZQ,DER,CEN;
  	IZQ=make_pair(0,1);
  	DER=make_pair(1,0);
  	CEN=make_pair(1,1);
	for(int j=0;j<cadena.size();j++){
    	if(cadena[j]=='L'){
        DER=CEN;
        CEN.first=IZQ.first+DER.first;
        CEN.second=IZQ.second+DER.second;
        }
      	if(cadena[j]=='R'){
        IZQ=CEN;
        CEN.first=IZQ.first+DER.first;
        CEN.second=IZQ.second+DER.second;
        }
    }
  	cout << CEN.first << "/" << CEN.second << "\n";
}

void leer() {
	cin >> n;
  	for(int i=1; i<=n; i++) {
    	cin >> cadena;
      	proceso();
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
	leer();
    return 0;
}
