#include <bits/stdc++.h>
using namespace std;
int n,aux;
multiset <int> pot;
multiset <int>::iterator it;

bool leer() {
	cin >> n;

	for(int i=1; i<=n; i++) {
        cin >> aux;
        ///Buscamos si ya hay otro
        while((it=pot.find(aux))!=pot.end()) {
            ///Encontró uno igual, borramos
            pot.erase(it);
            ///Aumentamos en uno para meter
            aux++;
        }
        ///Metemos aux
        pot.insert(aux);
	}
  	if(pot.size()>2 || n==1) {
    	return false;
    }
  	return true;
}

int main() {
  	ios_base::sync_with_stdio(0); cin.tie(0);
  	if(leer()) {
    	cout << "Y";
    } else {
    	cout << "N";
    }
  	return 0;
}
