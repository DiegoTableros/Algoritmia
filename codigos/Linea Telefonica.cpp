#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<ii> vii;
vector <iii> aristas;
bool visit[1002];
int n,p,k;
vector <vi> lista;

void leer() {
    int u,v,w;
    cin >> n >> p >> k;
    for(int i=1; i<=p; i++) {
        cin >> u >> v >> w;
        aristas.push_back(make_pair(w,make_pair(u,v)));
    }
    sort(aristas.begin(),aristas.end());
    ///Ahora metemos las aristas de cada nodo
    lista.resize(n+2,vi);
    for(int i=0; i<aristas.size(); i++) {
        int u=aristas[i].second.first;
        int v=aristas[i].second.second;
        int w=aristas[i].first;
        lista[u].push_back(make_pair(v,w));
        lista[v].push_back(make_pair(u,w));
    }
    ///Ahora todo está en orden creciente
}

int dfs_may(int act, int may) {
    if(act==n) {
        return may;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    leer();
    cout << dfs_may(1,0);
    return 0;
}
