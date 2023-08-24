#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
char mapa[1252][1252];
int n,m,x_ini,y_ini,x_fin,y_fin;
bool memo[1252][1252];
int dist[1252][1252][6];
bool visit[1252][1252][4];
int matriz[6][4];
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

void leer() {
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin >> mapa[i][j];
            if(mapa[i][j]=='O') {
                x_ini=i;
                y_ini=j;
            }
            if(mapa[i][j]=='#') {
                memo[i][j]=1;
            }
            if(mapa[i][j]=='X') {
                x_fin=i;
                y_fin=j;
            }
        }
    }
    matriz[1][1]=-1;
    matriz[2][1]=1;
    matriz[3][2]=1;
    matriz[4][2]=-1;
}

void precalculo() {
    for(int i=2; i<n; i++) {
        for(int j=2; j<m; j++) {
            if(mapa[i][j]!='#') {
                ///Checamos que direccion NORTE aun no esta puesta
                if(!visit[i][j][1]) {
                    visit[i][j][1]=1;
                    ///Vemos si el de arriba ya la tiene
                    if(visit[i-1][j][1]) {
                        ///Si es así, usamos su respuesta
                        dist[i][j][1]=dist[i-1][j][1]+1;
                    } else {
                        ///Tenemos que construir la respuesta
                        int x=i,y=j;
                        while(mapa[x-1][y]!='#') {
                            dist[i][j][1]++;
                            x--;
                        }
                    }
                }
                ///SUR
                if(!visit[i][j][2]) {
                    visit[i][j][2]=1;
                    ///Vemos si el de arriba ya la tiene
                    if(visit[i-1][j][2]) {
                        ///Si es así, usamos su respuesta
                        dist[i][j][2]=dist[i-1][j][2]-1;
                    } else {
                        ///Tenemos que construir la respuesta
                        int x=i,y=j;
                        while(mapa[x+1][y]!='#') {
                            dist[i][j][2]++;
                            x++;
                        }
                    }
                }
                ///ESTE
                if(!visit[i][j][3]) {
                    visit[i][j][3]=1;
                    ///Vemos si el de la izquierda ya la tiene
                    if(visit[i][j-1][3]) {
                        ///Si es así, usamos su respuesta
                        dist[i][j][3]=dist[i][j-1][3]-1;
                    } else {
                        ///Tenemos que construir la respuesta
                        int x=i,y=j;
                        while(mapa[x][y+1]!='#') {
                            dist[i][j][3]++;
                            y++;
                        }
                    }
                }
                ///OESTE
                if(!visit[i][j][4]) {
                    visit[i][j][4]=1;
                    ///Vemos si el de la izquierda ya la tiene
                    if(visit[i][j-1][4]) {
                        ///Si es así, usamos su respuesta
                        dist[i][j][4]=dist[i][j-1][4]+1;
                    } else {
                        ///Tenemos que construir la respuesta
                        int x=i,y=j;
                        while(mapa[x][y-1]!='#') {
                            dist[i][j][4]++;
                            y--;
                        }
                    }
                }
            }
        }
    }
}

void busqueda() {
    iii act,aux;
    int x,y,menor;
    priority_queue <iii> cola;
    cola.push(make_pair(0,make_pair(x_ini,y_ini)));
    memo[x_ini][y_ini]=1;
    while(!cola.empty()) {
        act=cola.top();
        cola.pop();
        act.f*=-1;
        if(act.s.f==x_fin && act.s.s==y_fin) {
            cout << act.f;
            return;
        }
        act.f++;
        ///Movimientos normales
        for(int i=1; i<=4; i++) {
            aux=act;
            aux.s.f+=matriz[i][1];
            aux.s.s+=matriz[i][2];
            if(aux.s.f>0 && aux.s.f<=n && aux.s.s>0 && aux.s.s<=m) {
                if(memo[aux.s.f][aux.s.s]==0) {
                    memo[aux.s.f][aux.s.s]=1;
                    aux.f*=-1;
                    cola.push(aux);
                }
            }
        }
        x=act.s.f;
        y=act.s.s;
        menor=min(dist[x][y][1],min(dist[x][y][2],min(dist[x][y][3],dist[x][y][4])));
        ///Ahora metemos los cuatro posibles movimientos a portales
        aux.f=act.f+menor;
        aux.f*=-1;
        ///NORTE
        aux.s.f=x-dist[x][y][1];
        aux.s.s=y;
        if(memo[aux.s.f][aux.s.s]==0) {
            memo[aux.s.f][aux.s.s]=1;
            cola.push(aux);
        }
        ///SUR
        aux.s.f=x+dist[x][y][2];
        aux.s.s=y;
        if(memo[aux.s.f][aux.s.s]==0) {
            memo[aux.s.f][aux.s.s]=1;
            cola.push(aux);
        }
        ///ESTE
        aux.s.f=x;
        aux.s.s=y+dist[x][y][3];
        if(memo[aux.s.f][aux.s.s]==0) {
            memo[aux.s.f][aux.s.s]=1;
            cola.push(aux);
        }
        ///OESTE
        aux.s.f=x;
        aux.s.s=y-dist[x][y][4];
        if(memo[aux.s.f][aux.s.s]==0) {
            memo[aux.s.f][aux.s.s]=1;
            cola.push(aux);
        }
    }
    cout << "THE CAKE IS A LIE";
    return;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    leer();
    precalculo();
    busqueda();
    /*for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cout << "(" << i << "," << j << "):\t";
            cout << dist[i][j][1] << " " << dist[i][j][2] << " " << dist[i][j][3] << " " << dist[i][j][4] << "\n";
        }
    }*/
    return 0;
}
