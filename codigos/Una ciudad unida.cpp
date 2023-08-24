#include <bits/stdc++.h>

using namespace std;
vector <short> arre[2002];
int n,m,a,b,aux;
short padre[2002];
queue <short> cola;
short cubeta[2002];

void leer() {
    cin >> n >> m;
    for(int i=1; i<=m; i++) {
        cin >> a >> b;
        arre[a].push_back(b);
        arre[b].push_back(a);
    }
}

void propagacion() {
    for(int i=1; i<=n; i++) {
        ///Si encontramos a alguien con padre cero, hacemos ese bosque
        if(padre[i]==0) {
            ///Hacemos que todo este bosque tenga padre i
            cola.push(i);
            padre[i]=i;
            cubeta[i]++;
            while(!cola.empty()) {
                ///Sacamos el nodo actual
                short act=cola.front();
                cola.pop();
                ///Nos propagamos a sus hijos
                for(int x=0; x<arre[act].size(); x++) {
                    short aux=arre[act][x];
                    if(padre[aux]==0) {
                        ///Asignamos el padre
                        padre[aux]=i;
                        ///Sumamos uno a la cubeta
                        cubeta[i]++;
                        ///Lo metemos a la cola
                        cola.push(aux);
                    }
                }
            }
            ///Con esto todo el bosque ya quedo con padre i y la cubeta tiene el numero de arboles
        }
    }
}

void conteo() {
    int res=0;
    int N=n;
    ///Recorremos la cubeta
    for(int i=1; i<=n; i++) {
        ///Si hay un numero, estamos en un bosque
        if(cubeta[i]!=0) {
            ///Nos quitamos del N general
            N-=cubeta[i];
            ///A la respuesta le sumamos nosotros por los que quedan en N
            res+=(cubeta[i]*N);
        }
    }
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    leer();
    propagacion();
    conteo();
    return 0;
}
