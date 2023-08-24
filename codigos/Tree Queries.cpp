#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
vector <vi> tree;
queue <int> cola;
struct nodo {
    int nivel;
    int padre;
};
nodo arbol[200002];
int memo[200002];
int visit[200002];
int n,k,m;

bool query(int color) {
    bool bandera=1;
    int aux,niv,nivel_profundo=0,act;
    cin >> k;
    for(int i=1; i<=k; i++) {
        cin >> aux;
        ///Rescatamos el nodo mas profundo
        if(arbol[aux].nivel>nivel_profundo) {
            nivel_profundo=arbol[aux].nivel;
            act=aux;
        }
        ///Rescatamos su nivel
        niv=arbol[aux].nivel;
        ///Vemos si el nivel esta visitado con el color
        if(visit[niv]==color) {
            ///Ya esta visitado, debemos checar que los padres sean iguales
            if(memo[niv]!=arbol[aux].padre) {
                ///Distintos, valio
                bandera=0;
            }
        } else {
            ///No esta visitado
            visit[niv]=color;
            ///Guardamos el padre
            memo[niv]=arbol[aux].padre;
        }
    }
    ///Checamos la bandera antes de proceder
    if(bandera==0) {
        return false;
    }
    ///Ahora vamos del mas profundo (act) hacia arriba checando los padres
    while(act!=1) {
        ///Nuestro nivel esta en arbol[act].nivel
        ///Nuestro padre esta en arbol[act].padre
        ///Preguntamos si alguien almaceno padre en nuestro nivel
        if(visit[arbol[act].nivel]==color) {
            ///Alguien guardó padre, lo comparamos
            if(memo[arbol[act].nivel]!=arbol[act].padre) {
                return false;
            }
        }
        ///Avanzamos al nodo siguiente
        act=arbol[act].padre;
    }
    return true;
}

void leer() {
    cin >> n >> m;
    int a,b;
    tree.resize(n+1);
    ///Leemos el arbol
    for(int i=1; i<n; i++) {
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    ///Hacemos la propagación
    cola.push(1);
    while(!cola.empty()) {
        int act=cola.front();
        cola.pop();
        for(int i=0; i<tree[act].size(); i++) {
            int aux=tree[act][i];
            if(arbol[aux].nivel==0 && aux!=1) {
                ///Debemos actualizarlo
                arbol[aux].nivel=arbol[act].nivel+1;
                arbol[aux].padre=act;
                cola.push(aux);
            }
        }
    }
    ///Ahora leemos las querys
    for(int x=1; x<=m; x++) {
        if(query(x)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    leer();
    return 0;
}
