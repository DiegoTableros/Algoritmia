#include <bits/stdc++.h>
using namespace std;

int n,k,m,precio,pago_final;
char letra;
int pago[302];
string linea;

void leer() {
    cin >> k;
    for(int i=1; i<=k; i++) {
        ///Leemos la letra
        cin >> letra;
        ///Leemos cuanto pagan por esta letra
        cin >> precio;
        ///Guardamos en la posicion ASCII de la letra su pago
        pago[letra]=precio;
    }
    ///Inicializamos el pago final en cero
    pago_final=0;
    ///Leemos el numero de lineas del articulo
    cin >> m;
    ///Truco para leer el "Enter" que queda volando, para que no nos afecte
    getline(cin,linea);
    for(int j=1; j<=m; j++) {
        ///Con esta funcion ya leimos toda la linea y se guardo en el String "linea"
        getline(cin, linea);
        ///Recorremos el arreglo de pagos
        for(int i=0; i<=255; i++) {
            char letra_actual=i;
            ///Contamos cuantas veces aparece la letra actual en el string con esta funcion
            int apariciones=count(linea.begin(), linea.end(), letra_actual);
            ///Sumamos lo siguiente: el numero de veces que aparece por su pago
            pago_final=pago_final+(apariciones*pago[i]);
        }
        linea.clear();
    }
    ///Esta ultima impresion es para que tenga dos decimales
    cout << setprecision(2) << fixed << (pago_final/100.0) << "$\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ///Leemos el numero de articulos
    cin >> n;
    ///Trabajamos cada articulo
    for(int x=1; x<=n; x++) {
        leer();
    }
    return 0;
}
