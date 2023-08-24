#include <bits/stdc++.h>

using namespace std;
short arre[100002];
int n,res,ind;

void leer() {
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> arre[i];
    }
    ///Buscamos los espacios vacios
    for(int i=1; i<=n; i++) {
        if(arre[i]==0) {
            ///Espacio vacio, lanzamos el contador
            int aux=1;
            for(int j=i-1; j>0 && arre[j]==2; j--) {
                aux++;
            }
            for(int j=i+1; j<=n && arre[j]==2; j++) {
                aux++;
            }
            ///Comparamos la respuesta
            if(res<aux) {
                ind=i;
                res=aux;
            }
        }
    }
    ///Imprimimos
    cout << res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    leer();
    return 0;
}
