#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
vi aux;
vector <vi> lista;
int n,p;
queue <int> cola;
vector <int> generacion;

void leer() {
    cin >> n;
    lista.resize(n+1);
    generacion.resize(n+1);
    for(int i=0; i<=n; i++) {
        lista.push_back(aux);
        cin >> p;
        if(p==i) {
            cola.push(i);
            generacion[i]=1;
        } else {
            lista[p].push_back(i);
        }
    }
    while(!cola.empty()) {
        int act=cola.front();
        cola.pop();
        for(int i=0; i<lista[act].size(); i++) {
            int aux=lista[act][i];
            generacion[aux]=generacion[act]+1;
            cola.push(aux);
        }
    }
    int gen=generacion[0];
    int cont=0;
    for(int i=1; i<=n; i++) {
        if(generacion[i]==gen) {
            cont++;
        }
    }
    cout << cont;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    leer();
    return 0;
}
