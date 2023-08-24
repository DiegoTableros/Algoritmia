#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int dinero[1002];

void leer() {
	cin >> n;
  	for(int i=0; i<=n; i++) {
    	cin >> s;
    	s.erase(s.begin(),s.begin()+s.find('.')+1);
    	dinero[i]=stoi(s);
    }
    int cont=0;
    int act=dinero[0];
    for(int i=1; i<=n; i++) {
        act+=dinero[i];
        if(act>=100) {
            act-=100;
        }
        if(act>0) {
            cont++;
        }
    }
    cout << cont;
}

int main() {
  	ios_base::sync_with_stdio(0); cin.tie(0);
  	leer();
  	return 0;
}
