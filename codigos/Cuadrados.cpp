#include <bits/stdc++.h>
using namespace std;
int n;
int arre[1002][1002];
typedef pair<int,int> ii;
queue <ii> cola;
int res[1002];

void leer() {
    int aux;
    cin >> n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> aux;
            if(aux==0) {
                arre[i][j]=1;
                cola.push(ii(i,j));
            } else {
                arre[i][j]=0;
            }
        }
    }
}

void cuadrados() {
    while(!cola.empty()) {
        int i=cola.front().first, j=cola.front().second;
        cola.pop();
        ///Aumentamos al contador de cuadrados de este tipo
        res[arre[i][j]]++;
        ///Vemos si se forma otro cuadrado con las adyacentes
        if(arre[i][j]==arre[i+1][j] && arre[i][j]==arre[i+1][j+1] && arre[i][j]==arre[i][j+1]){
            ///Tenemos un nuevo cuadrado, aumentamos en la casilla
            arre[i][j]++;
            ///Y metemos a la cola
            cola.push(ii(i,j));
        }
    }
    ///Imprimimos las respuestas
    for(int i=1; i<=n; i++) {
        cout << res[i] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    leer();
    cuadrados();
    return 0;
}
