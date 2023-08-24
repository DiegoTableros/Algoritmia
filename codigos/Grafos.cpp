#include <bits/stdc++.h>

using namespace std;
///Lista Ady para N nodos (N<=100)
vector <int> lista[1002];
int nodos,aristas,a,b;
int distancia[1002];

void leer() {
    cin >> nodos >> aristas;
    for(int i=1; i<=aristas; i++) {
        cin >> a >> b;
        ///Meter "b" a la lista de "a"
        lista[a].push_back(b);
        ///Meter "a" a la lista de "b"
        lista[b].push_back(a);
    }
}

void bfs(int nodo_inicial) {
    ///Declaramos una cola para los pendientes
    queue <int> cola;
    ///El primero (desde donde nos expandemos) es el inicial
    ///Lo metemos innicialmente a la cola
    cola.push(nodo_inicial);
    ///Mientras aun haya nodos pendientes ...
    while(cola.empty()==0) {
        ///Sacamos el nodo actual
        int nodo_actual=cola.front();
        ///Y lo eliminamos de la cola
        cola.pop();
        ///Vemos sus conexiones con la lista
        for(int i=0; i<lista[nodo_actual].size(); i++) {
            ///Sacamos el nodo con el que esta conectado
            int aux=lista[nodo_actual][i];
            ///Si no tiene distancia asignada y no es el inicial
            if(distancia[aux]==0 && aux!=nodo_inicial) {
                ///Su distancia es la del nodo actual +1
                distancia[aux]=distancia[nodo_actual]+1;
                ///Lo metemos a la cola
                cola.push(aux);
            }
        }
    }
    ///Finalmente, imprimimos las distancias para corroborar
    for(int i=1; i<=nodos; i++) {
        cout << distancia[i] << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    leer();
    ///A BFS() le tenemos que mandar el nodo inicial
    bfs(2);
    return 0;
}
