#include <bits/stdc++.h>

using namespace std;
int n,aux,ultimo;
map <int,int> perros;
map <int,int>::iterator it;
struct p {
    int perro;
    int cont;
    bool operator <(p x) const {
        if(cont<x.cont) {
            return true;
        }
        if(cont==x.cont) {
            if(x.perro>perro) {
                return true;
            }
        }
        return false;
    }
};
vector <p> cubeta;

void leer() {
    cin >> n;
    ///Leemos cada perro y lo insertamos al multiset
    for(int i=1; i<=n; i++) {
        cin >> aux;
        perros[aux]++;
    }
    for(it=perros.begin(); it!=perros.end(); it++) {
        ///Vamos añadiendo al vector los datos
        p nuevo;
        nuevo.perro=it->first;
        nuevo.cont=it->second;
        cubeta.push_back(nuevo);
    }
    ///Finalmente, con el operador ya sobrecargado aplicamos sort en el vector
    sort(cubeta.begin(),cubeta.end());
    ///Imprimimos
    for(int i=cubeta.size()-1; i>=0; i--) {
        cout << cubeta[i].perro << "\n";
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    leer();
    return 0;
}
