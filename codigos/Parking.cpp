#include <bits/stdc++.h>

using namespace std;
int t,n;

int park() {
    cin >> n;
    int aux,L_izq=1000000,L_der=-1000000;
    for(int i=1; i<=n; i++) {
        cin >> aux;
        if(aux<L_izq) {
            L_izq=aux;
        }
        if(aux>L_der) {
            L_der=aux;
        }
    }
    return (L_der-L_izq)*2;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    for(int x=1; x<=t; x++) {
        ///Resolvemos cada caso
        cout << park() << "\n";
    }
    return 0;
}
