#include <bits/stdc++.h>
using namespace std;
int n,m,salida,tiempo,c;
typedef pair<int,int> ii;
typedef vector<ii> vii;
vector <vii> listaAdy;
int distancia[102];
#define INF 1000000000

void dijkstra() {
    ii par;
    for(int i=1; i<=n; i++) {
        distancia[i]=INF;
    }
    distancia[salida]=0;
    set <ii> p_q;
    p_q.insert(ii(0,salida));
    while(!p_q.empty()) {
        par=*p_q.begin();
        p_q.erase(p_q.begin());
        int u=par.second, dist=par.first;
        if(distancia[u]<dist) {
            continue;
        }
        for(int i=0; i<listaAdy[u].size(); i++) {
            par=listaAdy[u][i];
            int v=par.first, pond=par.second;
            if(distancia[v]>distancia[u]+pond) {
                distancia[v]=distancia[u]+pond;
                p_q.insert(ii(distancia[v],v));
            }
        }
    }
}

void leer() {
    int u,v,w;
    cin >> n >> salida >> tiempo >> m;
    listaAdy.resize(n+2);
    for(int i=1; i<=m; i++) {
        cin >> u >> v >> w;
        listaAdy[u].push_back(ii(v,w));
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> c;
    for(int z=1; z<=c; z++) {
        leer();
        dijkstra();
        int cont=0;
        for(int i=1; i<=n; i++) {
            if(distancia[i]<=tiempo) {
                cont++;
            }
        }
        cout << cont;
        listaAdy.clear();
        if(z<c) {
            cout << "\n";
        }
    }
    return 0;
}
