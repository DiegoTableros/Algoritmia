#include <bits/stdc++.h>

using namespace std;
int n,t,mini,a,b,ini,fin;
string cadena;
map <pair<int,int>,int> mapa;
pair <int,int> aux;
map <pair<int,int>,int>::iterator ite;

void buscar() {
    ///Actualizamos el máximo
    mini=n+1;
    ///Metemos la coordenada (0,0) con posicion 0
    aux=make_pair(0,0);
    ///El MAP recibe un pair para meter datos, uno con la llave y otro con el valor
    mapa.insert(make_pair(aux,0));
    ///Creamos nuestras coordenadas actuales para ir moviendonos
    int posx=0,posy=0;
    ///Recorremos toda la cadena siguiendo las instrucciones
    for(int i=0; i<n; i++) {
        ///Nos movemos de acuerdo a la letra
        if(cadena[i]=='L') {
            posx--;
        } else if(cadena[i]=='R') {
            posx++;
        } else if(cadena[i]=='U') {
            posy++;
        } else {
            posy--;
        }
        ///Ahora vemos si hemos pasado por estas coordenadas
        aux=make_pair(posx,posy);
        ite=mapa.find(aux);
        fin=i+1;
        if(ite==mapa.end()) {
            ///No lo encontró, primera vez que pasamos
            ///Guardamos en el MAP toda la info
            mapa.insert(make_pair(aux,fin));
        } else {
            ///Lo encontró, ya pasamos por aquí alguna vez, visitado
            ///El inicio es el mapeado del que encontramos
            ini=ite->second;
            ///El final es la posicion actual
            ///Si la longitud de la cadena actual es menor que la guardada
            if((fin-ini)<mini) {
                mini=fin-ini;
                ///Guardamos los indices
                a=ini+1;
                b=fin;
            }
            ///Por ultimo, actualizamos el contenido del map con nuestro indice actual
            mapa[aux]=fin;
        }
    }
    ///Retornamos la respuesta
    if(mini!=n+1) {
        cout << a << " " << b << "\n";
     } else {
        cout << -1 << "\n";
     }
     return;
}


void leer() {
    cin >> t;
    for(int x=1; x<=t; x++) {
        cin >> n;
        cin >> cadena;
        buscar();
        mapa.clear();
        cadena.clear();
    }
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    leer();
    return 0;
}
