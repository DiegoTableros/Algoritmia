#include <bits/stdc++.h>
using namespace std;
int n,m,u,v,w;
typedef pair<int,int> ii;
vector <ii> lista[1002];
int visit[1002];
priority_queue <ii> aristas;

int prim(int ini) {
    ///Impresion auxiliar
    cout << "MST:\n";
    int costo_total=0;
    ///Metemos el nodo inicial
    visit[ini]=1;
    for(int i=0; i<lista[ini].size(); i++) {
        aristas.push(make_pair(-lista[ini][i].second,lista[ini][i].first));
    }
    while(!aristas.empty()) {
        ii a=aristas.top();
        aristas.pop();
        if(visit[a.second]==0) {
            ///Lo añadimos al arbol
            visit[a.second]=1;
            costo_total+=(-a.first);
            ///Metemos a la cola de prioridad las aristas de este ultimo nodo
            for(int i=0; i<lista[a.second].size(); i++) {
                aristas.push(make_pair(-lista[a.second][i].second,lista[a.second][i].first));
            }
        }
    }
    return costo_total;
}

void leer() {
    cin >> n >> m;
    for(int i=1; i<=m; i++) {
        cin >> u >> v >> w;
        lista[u].push_back(make_pair(v,w));
    }
    cout << prim(1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    leer();
    return 0;
}
