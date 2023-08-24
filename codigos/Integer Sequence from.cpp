#include <bits/stdc++.h>
using namespace std;
int t,grado,d,k;
int polinomio[22];

void leer() {
    cin >> grado;
    for(int i=0; i<=grado; i++) {
        cin >> polinomio[i];
    }
    cin >> d >> k;
    int numero=0,n=1;
    while(numero<k) {
        numero+=(n*d);
        n++;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    for(int z=1; z<=t; z++) {
        leer();
    }
    return 0;
}
