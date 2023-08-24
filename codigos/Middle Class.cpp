#include <bits/stdc++.h>

using namespace std;
long long int t,n,x,puntos,resta,cont;
long long int arre[100002];

int leer() {
    ///Limpiar variables
    cont=0;
    puntos=0;
    cin >> n >> x;
    for(int i=1; i<=n; i++) {
        cin >> arre[i];
        if(arre[i]>=x) {
            puntos+=(arre[i]-x);
        }
    }
    sort(arre+1,arre+n+1);
    for(int i=n; i>0; i--) {
        ///Restamos x-arre[i] para saber cuantos le faltan
        resta=x-arre[i];
        ///Si la resta es positiva, hay algo que hacer
        if(resta<=0) {
            cont++;
        } else {
            ///Resta positiva, usamos los puntos
            if(puntos>=resta) {
                cont++;
                puntos-=resta;
            } else {
                ///Es el primero que no se puede, retornamos directamente
                return cont;
            }
        }
    }
    return cont;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    for(int i=1; i<=t; i++) {
        cout << leer() << "\n";
    }
    return 0;
}
