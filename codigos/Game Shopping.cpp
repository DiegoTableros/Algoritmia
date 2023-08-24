#include <bits/stdc++.h>

using namespace std;
int billete[1002];
int juego[1002];
int n,m;

void leer() {
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        cin >> juego[i];
    }
    for(int i=1; i<=m; i++) {
        cin >> billete[i];
    }
    int i=1,j=1,cont=0;
    while(i<=n && j<=m) {
        ///Vemos si puedo comprar el juego actual
        if(juego[i]<=billete[j]) {
            ///Se puede comprar, siguiente juego y siguiente billete
            cont++;
            i++;
            j++;
        } else {
            ///No puedo comprar este juego con este billete
            i++;
        }
    }
    ///Me quede sin billetes o sin juegos, termino
    cout << cont;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    leer();
    return 0;
}
