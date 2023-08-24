#include <bits/stdc++.h>

using namespace std;
long long int n,k,aux;
multiset <long long int> MULTISET;
long long int res;

void leer() {
    cin >> n;
    while(n!=0) {
        res=0;
        for(int i=1; i<=n; i++) {
            ///Leemos los datos de cada dia
            cin >> k;
            for(int j=1; j<=k; j++) {
                ///Leemos las facturas del dia
                cin >> aux;
                ///Las metemos al multiset
                MULTISET.insert(aux);
            }
            ///Ya finalizo el dia, sumamos el premio
            multiset<long long int>::iterator it=MULTISET.end();
            it--;
            long long int mayor=*it;
            long long int menor=*MULTISET.begin();
            res+=mayor-menor;
            MULTISET.erase(MULTISET.begin());
            MULTISET.erase(it);
        }
        cout << res << "\n";
        MULTISET.clear();
        cin >> n;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    leer();
    return 0;
}
