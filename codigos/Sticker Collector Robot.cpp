#include <bits/stdc++.h>
using namespace std;
#define NORTE 1
#define SUR 2
#define ESTE 3
#define OESTE 4
int n,m,s;
char mapa[102][102];
string paso;
int fila,col,dir;
char letra;

void leer() {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin >> mapa[i][j];
            l=mapa[i][j];
            if(l=='N' || l=='S' || l=='L' || l=='O') {
                fila=i;
                col=j;
                switch(l) {
                case 'N':
                    dir=NORTE;
                    break;
                case 'S':
                    dir=SUR;
                    break;
                case 'L':
                    dir=ESTE;
                    break;
                case 'O':
                    dir=OESTE;
                    break;
                }
            }
        }
    }
    cin >> paso;
}

void recorrido() {

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> s;
    while(n!=0 && m!=0 && s!=0) {
        leer();
        recorrido();
        cin >> n >> m >> s;
    }
    return 0;
}
