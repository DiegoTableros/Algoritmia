#include <bits/stdc++.h>
using namespace std;
int n,m,k;
typedef pair<int,int> ii;
vector <ii> listaAdy[1002];
int distancia[1002];
#define INF 1000000000

void inicializar() {
    for(int i=1; i<=n; i++) {
        distancia[i]=INF;
    }
}

void leer() {
    int u,v,w;
    cin >> n >> k >> m;
    for(int i=1; i<=m; i++) {
        cin >> u >> v >> w;
        listaAdy[u].push_back(make_pair(v,w));
    }
}

void dijkstra(int ini) {
    ii x;
    set <ii> cola;
    cola.insert(make_pair(0,ini));
    distancia[ini]=0;
    while(!cola.empty()) {
        ii x=*cola.begin();
        int act=x.second, dist=x.second;
        cola.erase(cola.begin());
        if(distancia[act]<dist) {
            continue;
        }
        for(int i=0; i<listaAdy[act].size(); i++) {

        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    leer();
    dijkstra(ini);
    return 0;
}
