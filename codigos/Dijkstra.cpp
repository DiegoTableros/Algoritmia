#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define INF 1000000000
///Lista de adyacencia
vector <vii> lista;
///Cola de prioridad para Dijkstra
set <ii> cola;
///Arreglo de distancias
int distancia[1002];
int n,m;

void leer() {
    cin >> n >> m;
    lista.resize(n);
    int u,v,w;
    for(int i=1; i<=m; i++) {
        cin >> u >> v >> w;
        lista[u].push_back(ii(v,w));
    }
}

void dijkstra(int inicio) {
    for(int i=0; i<=n; i++) {
        distancia[i]=INF;
    }
    distancia[inicio]=0;
    cola.insert(ii(0,inicio));
    while(!cola.empty()) {
        ii act=*cola.begin();
        cola.erase(cola.begin());
        ///Si la distancia "d" de este par (d,nodo) es mayor a la guardada, ignorar
        if(act.first>distancia[act.second]) {
            continue;
        }
        ///Ya esta guardada la distancia optima, ahora exploramos a los otros
        for(int i=0; i<lista[act.second].size(); i++) {
            ii aux=lista[act.second][i];
            ///Vemos si mejoramos la distancia, esto es "relajar"
            if(distancia[aux.first]>distancia[act.second]+aux.second) {
                ///Actualizamos distancia
                distancia[aux.first]=distancia[act.second]+aux.second;
                ///Metemos a la cola
                cola.insert(ii(distancia[aux.first],aux.first));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    leer();
    dijkstra(0);
    for(int i=1; i<n; i++) {
        cout << distancia[i] << " ";
    }
    return 0;
}
