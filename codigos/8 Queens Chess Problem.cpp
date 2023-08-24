#include <bits/stdc++.h>

using namespace std;
int fila[10];
int fil,col,t,cont;

bool valido(int f, int c) {
    /**Checamos que en las columnas anteriores
    nadie esté en nuestra fila ni en la diagonal*/
    for(int j=c-1; j>0; j--) {
        if(fila[j]==f || (abs(f-fila[j])==abs(c-j))) {
            return false;
        }
    }
    return true;
}

bool comprueba() {
    ///Comprobamos si cumple la restriccion
    for(int j=1; j<=8; j++) {
        if(fila[j]==fil && j==col) {
            return true;
        }
    }
    return false;
}

void imprime() {
    cont++;
    cout << " " << cont << "      ";
    for(int i=1; i<=8; i++) {
        cout << fila[i] << " ";
    }
    cout << "\n";
}

void reina(int columna) {
    ///Estamos en esta columna, nos recorremos en las filas
    for(int i=1; i<=8; i++) {
        ///Si es valido estar aqui con respecto al pasado ...
        if(valido(i,columna)) {
            ///Nos guardamos y avanzamos a la siguiente columna
            if(columna!=8) {
                fila[columna]=i;
                reina(columna+1);
            } else {
                fila[columna]=i;
                ///Estamos en la columna final, checamos si todo fue valido
                if(comprueba()) {
                    imprime();
                }
            }
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    for(int x=1; x<=t; x++) {
        cin >> fil >> col;
        cout << "SOLN       COLUMN\n";
        cout << " #      1 2 3 4 5 6 7 8\n\n";
        reina(1);
        memset(fila,0,sizeof(fila));
        cont=0;
        if(x!=t){
            cout << "\n";
        }
    }
    return 0;
}
