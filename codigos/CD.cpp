#include <bits/stdc++.h>

using namespace std;
int n,m;
///No podemos usar cubeta porque los numeros van a un billon
set <long long int> SET;
long long int aux;

void leer() {
    cin >> n >> m;
    while(n!=0 && m!=0) {
        for(int i=1; i<=n; i++) {
            cin >> aux;
            SET.insert(aux);
        }
        int res=0;
        ///Ahora vamos a checar los repetidos
        set <long long int>::iterator it;
        for(int i=1; i<=m; i++) {
            cin >> aux;
            it=SET.find(aux);
            if(it!=SET.end()) {
                ///Hay una copia
                res++;
                SET.erase(it);
            }
        }
        SET.clear();
        cout << res << "\n";
        cin >> n >> m;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    leer();
    return 0;
}
