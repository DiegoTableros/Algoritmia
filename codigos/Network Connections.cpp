#include <bits/stdc++.h>

using namespace std;
int n,m,a,b;
char com;
int padre[100002];

void inicializar() {
    for(int i=1; i<=n; i++) {
        padre[i]=i;
    }
}

int FIND(int x) {
    ///Si es su padre, es el representante
    if(padre[x]==x) {
        return x;
    }
    ///Si no, seguimos buscando y actualizando
    return padre[x]=FIND(padre[x]);
}

bool mismo_conjunto(int x, int y) {
    return FIND(x)==FIND(y);
}

void UNION(int x, int y) {
    ///Unir el conjunto donde esta X con el conjunto donde Y
    int padre_x=FIND(x), padre_y=FIND(y);
    padre[padre_x]=padre_y;
}

void leer() {
    cin >> n >> m;
    inicializar();
    for(int i=1; i<=m; i++) {
        cin >> com >> a >> b;
        if(com=='U') {
            ///Unir conjunto a con b
            UNION(a,b);

        } else {
            ///a y b estan en el mismo conjunto?
            cout << mismo_conjunto(a,b) << "\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    leer();
    return 0;
}
