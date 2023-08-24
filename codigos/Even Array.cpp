#include <bits/stdc++.h>
using namespace std;
int t,n;
int arre[42];

int leer() {
    cin >> n;
    int pares=0,impares=0,pares_fuera=0;
    for(int i=0; i<n; i++) {
        cin >> arre[i];
        if(arre[i]%2==0) {
            pares++;
            if(i%2==1) {
                pares_fuera++;
            }
        } else {
            impares++;
        }
    }
    if(n%2==0) {
        if(pares!=(n/2) || impares!=(n/2)) {
            return -1;
        }
    } else {
        if(pares!=((n/2)+1) || impares!=(n/2)) {
            return -1;
        }
    }
    return pares_fuera;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    for(int x=1; x<=t; x++) {
        cout << leer() << "\n";
    }
    return 0;
}
