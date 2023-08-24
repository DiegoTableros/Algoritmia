#include <bits/stdc++.h>
using namespace std;
long long int n,tam,L,R;
long long int arre[1000002];
long long int a1[1000002];
long long int a2[1000002];
string c;

long long int tamano() {
    char letra=c[c.size()-1];
    long long int multi=1;
    if(letra=='G') {
        multi=1024;
    } else if(letra=='T') {
        multi=1024*1024;
    }
    c.pop_back();
    int num=stoi(c,nullptr);
    multi=multi*num;
    return multi;
}

int main() {
  	ios_base::sync_with_stdio(0); cin.tie(0);
  	cin >> n >> c;
  	tam=tamano();
  	R=0;
  	for(int i=1; i<=n; i++) {
        cin >> arre[i];
        a1[i]=arre[i]+a1[i-1];
  	}
  	int ini=0,fin=1;
  	R=n;
  	while(fin<=n) {
        if((a1[fin]-a1[ini])<tam)
  	}
  	///Imprimimos R
  	cout << R << " ";
    L=-1;
    for(int i=R+1; i<=n; i++) {
        if((a1[i]-a1[i-R])>tam) {
            L=i-R;
            break;
        }
    }
    cout << L << "\n";
  	return 0;
}
