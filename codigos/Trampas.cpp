/*TRAMPAS
 * Este problema es una busqueda priorizada, nos interesa recorrer en el menor numero de trampas
 *
 * 	7 8
	2 6
	########
	#.S.#..#
	#.xx#.##
	#...x.##
	#...#x##
	#.....##
	########
 */
#include <bits/stdc++.h>
using namespace std;
int n,m,fila_ini,col_ini,fila_res,col_res;
char mapa[302][302];
int matriz[6][4];
typedef pair<int,int> ii;
typedef pair<ii,ii> iiii;
/// <<-trampas,-pasos>,<f,c>>
priority_queue <iiii> prioridad;
bool visit[302][302];

void busqueda() {
  	iiii act;
  	///Metemos estado inicial
  	if(mapa[fila_ini][col_ini]=='x') {
    	prioridad.push(make_pair(make_pair(-1,0),make_pair(fila_ini,col_ini)));
    } else {
		prioridad.push(make_pair(make_pair(0,0),make_pair(fila_ini,col_ini)));
    }
  	///Visitado inicial
  	visit[fila_ini][col_ini]=1;
  	while(!prioridad.empty()) {
    	act=prioridad.top();
      	prioridad.pop();
      	///Impresion de ayuda
      	//cout << "Estado: " << -act.first.first << -act.first.second << act.second.first << act.second.second << "\n";
      	///Checamos si es la respuesta
      	if(act.second.first==fila_res && act.second.second==col_res) {
        	///Imprimimos numero de trampas
          	cout << -act.first.first;
          	return;
        }
      	///Aumentamos los pasos
      	act.first.second--;
      	///Nos propagamos con la matriz de movimientos
      	for(int i=1; i<=4; i++) {
        	iiii aux=act;
          	///Hacer el movimiento
          	aux.second.first+=matriz[i][1];
          	aux.second.second+=matriz[i][2];
          	///Vemos si no nos salimos del mapa o caemos en #
          	if(aux.second.first>0 && aux.second.first<=n && aux.second.second>0 && aux.second.second<=m) {
            	if(mapa[aux.second.first][aux.second.second]!='#' && visit[aux.second.first][aux.second.second]==0) {
                  	///Marcamos visitado
                  	visit[aux.second.first][aux.second.second]=1;
                	///Estamos en una casilla ".", "x" o bien "S"
                  	if(mapa[aux.second.first][aux.second.second]=='x') {
                    	///Aumentamos el numero de trampas
                      	aux.first.first--;
                    }
                  	///Metemos a la cola de prioridad
                  	prioridad.push(aux);
                }
            }
        }
    }
}

void leer() {
	cin >> n >> m;
  	cin >> fila_ini >> col_ini;
  	for(int i=1; i<=n; i++) {
    	for(int j=1; j<=m; j++) {
        	cin >> mapa[i][j];
          	if(mapa[i][j]=='S') {
            	fila_res=i;
            	col_res=j;
            }
        }
    }
  	///Matriz guarda los movimientos N-S-E-O
  	///Norte: (x,y) -> (x-1,y)
  	matriz[1][1]=-1;
  	matriz[1][2]=0;
  	///Sur: (x,y) -> (x+1,y)
  	matriz[2][1]=1;
  	matriz[2][2]=0;
  	///Este: (x,y) -> (x,y+1)
  	matriz[3][1]=0;
  	matriz[3][2]=1;
  	///Oeste: (x,y) -> (x,y-1)
  	matriz[4][1]=0;
  	matriz[4][2]=-1;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  	leer();
  	busqueda();
    return 0;
}
