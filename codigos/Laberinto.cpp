#include <bits/stdc++.h>
using namespace std;
///Maximos de filas y columnas (modificables)
#define maxF 52
#define maxC 52
int n,m;
///Mapa de caracteres del laberinto
char mapa[maxF][maxC];
///Coordenadas de la entrada y la salida
int fila_inicial,col_inicial,fila_final,col_final;
///Estructura para guardar datos de cada casilla
struct edo{
    int f,c;
};
edo memorizado[maxF][maxC];
///Arreglo para marcar visitados
bool visit[maxF][maxC];

void leer() {
    ///Numero de filas y columnas
    cin >> n >> m;
    ///Leemos los caracteres del mapa
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin >> mapa[i][j];
            ///Casos de entrada y salida
            if(mapa[i][j]=='E') {
                fila_inicial=i; col_inicial=j;
            }
            if(mapa[i][j]=='S') {
                fila_final=i; col_final=j;
            }
            ///Caso muro, lo marcamos como visitado para no pasar por ahí
            if(mapa[i][j]=='M') {
                visit[i][j]=1;
            }
        }
    }
}

void busqueda_en_amplitud() {
    ///Creamos una cola para la amplitud
    queue <edo> cola;
    ///Preparamos el estado inicial de donde salimos
    edo act; act.f=fila_inicial; act.c=col_inicial;
    ///Marcamos como visitado el inicial
    visit[act.f][act.c]=1;
    ///Lo metemos a la cola
    cola.push(act);

    ///Mientras la cola de estados tenga elementos ...
    while(!cola.empty()){
        ///Sacamos el actual
        act=cola.front();
        cola.pop();
        ///Nos movemos a casillas adyacentes, up,down,left,right
        ///MOVER ARRIBA
        edo aux=act; aux.f--;
        if(aux.f>=0 && visit[aux.f][aux.c]==0) {
            visit[aux.f][aux.c]=1;
            memorizado[aux.f][aux.c]=act;
            ///Caso encontramos la salida
            if(aux.f==fila_final && aux.c==col_final) {
                return;
            }
            cola.push(aux);
        }
        ///MOVER ABAJO
        aux=act; aux.f++;
        if(aux.f<=n && visit[aux.f][aux.c]==0) {
            visit[aux.f][aux.c]=1;
            memorizado[aux.f][aux.c]=act;
            ///Caso encontramos la salida
            if(aux.f==fila_final && aux.c==col_final) {
                return;
            }
            cola.push(aux);
        }
        ///MOVER IZQUIERDA
        aux=act; aux.c--;
        if(aux.c>=0 && visit[aux.f][aux.c]==0) {
            visit[aux.f][aux.c]=1;
            memorizado[aux.f][aux.c]=act;
            ///Caso encontramos la salida
            if(aux.f==fila_final && aux.c==col_final) {
                return;
            }
            cola.push(aux);
        }
        ///MOVER DERECHA
        aux=act; aux.c++;
        if(aux.c<=m && visit[aux.f][aux.c]==0) {
            visit[aux.f][aux.c]=1;
            memorizado[aux.f][aux.c]=act;
            ///Caso encontramos la salida
            if(aux.f==fila_final && aux.c==col_final) {
                return;
            }
            cola.push(aux);
        }
    }
}

void imprime_camino() {
    cout << "\n\n\n";
    ///Si nunca se pudo llegar, imprimimos
    if(memorizado[fila_final][col_final].c==0 && memorizado[fila_final][col_final].f==0) {
        cout << "No existe salida del laberinto.\n";
        return;
    }
    ///Si se pudo llegar, vamos modificando el mapa para imprimirlo
    edo act; act.f=fila_final; act.c=col_final;
    while(act.f!=fila_inicial || act.c!=col_inicial) {
        mapa[act.f][act.c]=' ';
        ///Nos movemos
        act=memorizado[act.f][act.c];
    }
    ///Imprimimos el mapa modificado
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cout << mapa[i][j];
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    leer();
    busqueda_en_amplitud();
    imprime_camino();
    return 0;
}
