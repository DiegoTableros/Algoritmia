#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
vector <iii> lista_aristas;
int n,t;
int padre[100002];

void inicializar() {
    for(int i=0; i<=n; i++) {
        padre[i]=i;
    }
}

int Find(int x) {
    if(padre[x]==x){
        return x;
    }
    return padre[x]=Find(padre[x]);
}

bool mismo_conjunto(int a, int b) {
    return Find(a)==Find(b);
}

void Union(int a, int b) {
    if(!mismo_conjunto(a,b)) {
        int padrea=Find(a), padreb=Find(b);
        padre[padrea]=padreb;
    }
}

void leer() {
    int w;
    char coma;
    cin >> n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> w;
            if(j<n) {
                cin >> coma;
            }
            if(w!=0) {
                lista_aristas.push_back(make_pair(w,make_pair(i,j)));
            }
        }
    }
    sort(lista_aristas.begin(),lista_aristas.end());
}

void kruskal() {
    int costo_total=0;
    int aristas=0;
    for(int i=0; i<lista_aristas.size(); i++) {
        int u=lista_aristas[i].second.first;
        int v=lista_aristas[i].second.second;
        int w=lista_aristas[i].first;
        if(!mismo_conjunto(u,v)) {
            Union(u,v);
            costo_total+=w;
            aristas++;
            char aux1=(char)u+'A'-1;
            char aux2=(char)v+'A'-1;
            cout << aux1 << "-" << aux2 << " " << w << "\n";
            if(aristas==n-1) {
                break;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    for(int x=1; x<=t; x++) {
        leer();
        inicializar();
        cout << "Case " << t << ":\n";
        kruskal();
        lista_aristas.clear();
    }
    return 0;
}
