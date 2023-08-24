#include <bits/stdc++.h>

using namespace std;
int c,s,q;
typedef pair<int,int> ii;
vector < pair<int,ii> > aristas;
vector <ii> listaAdy[102];
int padre[102];
int visit[102];

void inicializar() {
    for(int i=0; i<=c; i++) {
        padre[i]=i;
    }
}

int Find(int x) {
    if(padre[x]==x) {
        return x;
    }
    return padre[x]=Find(padre[x]);
}

bool mismo_conjunto(int a, int b) {
    return Find(a)==Find(b);
}

void Union(int a, int b) {
    if(!mismo_conjunto(a,b)) {
        int pA=Find(a), pB=Find(b);
        padre[pA]=pB;
    }
}

void kruskal() {
    inicializar();
    int a=0;
    for(int i=0; i<aristas.size(); i++) {
        int u=aristas[i].second.first;
        int v=aristas[i].second.second;
        int w=aristas[i].first;
        if(!mismo_conjunto(u,v)) {
            Union(u,v);
            listaAdy[u].push_back(make_pair(v,w));
            listaAdy[v].push_back(make_pair(u,w));
        }
    }
}

void leer() {
    int a,b,w;
    for(int i=1; i<=s; i++) {
        cin >> a >> b >> w;
        aristas.push_back(make_pair(w,make_pair(a,b)));
    }
    sort(aristas.begin(),aristas.end());
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int z=1;
    cin >> c >> s >> q;
    while(c!=0 && s!=0 && q!=0) {
        cout << "Case #" << z << "\n";
        leer();
        kruskal();
        z++;
    }
    return 0;
}
