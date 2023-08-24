#include <bits/stdc++.h>
using namespace std;
struct edo{
  	///Fila, columna y pasos
	int f,c,p;
};
char mapa[1002][1002];
int pasos[1002][1002];
bool visit[1002][1002];
int filas,columnas,f_ini,c_ini;
int mov[6][4];

void leer() {
	cin >> filas >> columnas;
  	for(int i=1; i<=filas; i++) {
    	for(int j=1; j<=columnas; j++) {
        	cin >> mapa[i][j];
          	if(mapa[i][j]=='E') {
            	f_ini=i; c_ini=j;
            }
        }
    }
  	mov[1][2]=-1; mov[2][1]=1; mov[3][2]=1; mov[4][1]=-1;
}

void propaga() {
    edo act;
    act.f=f_ini; act.c=c_ini; act.p=0;
    visit[act.f][act.c]=1;
    queue <edo> cola;
    cola.push(act);
    while(!cola.empty()){
        act=cola.front();
        cola.pop();
        act.p++;
        for(int x=1; x<=4; x++) {
            edo aux=act;
            aux.f+=mov[x][1]; aux.c+=mov[x][2];
            if(mapa[aux.f][aux.c]=='.' && visit[aux.f][aux.c]==0 && aux.f>0 && aux.f<=filas && aux.c>0 && aux.c<=columnas) {
                ///Es posible
                visit[aux.f][aux.c]=1;
                pasos[aux.f][aux.c]=aux.p;
                cola.push(aux);
            }
        }
    }
}

char consulta(int x, int y) {
    ///Vemos si hay muro
    if(mapa[x][y]=='#') {
        return 'W';
    }
    ///Vemos si hay objeto
    if(mapa[x][y]=='X') {
        return 'X';
    }
    ///Vemos si es la salida
    if(mapa[x][y]=='E') {
        return 'E';
    }
    ///Es necesariamente un punto '.'
    ///Si es cero, este punto es aislado
    if(pasos[x][y]==0) {
        return '?';
    }
    ///Si no es cero, entonces es válido, buscamos casillas
    int p_mejor=1000007;
    char l_mejor;
    ///Vemos a la izquierda
    if((y-1)>0 && (pasos[x][y-1]!=0 || mapa[x][y-1]=='E') && pasos[x][y-1]<p_mejor) {
        p_mejor=pasos[x][y-1];
        l_mejor='L';
    }
    if((x+1)<=filas && (pasos[x+1][y]!=0 || mapa[x+1][y]=='E') && pasos[x+1][y]<p_mejor) {
        p_mejor=pasos[x+1][y];
        l_mejor='D';
    }
    if((y+1)<=columnas && (pasos[x][y+1]!=0 || mapa[x][y+1]=='E') && pasos[x][y+1]<p_mejor) {
        p_mejor=pasos[x][y+1];
        l_mejor='R';
    }
    if((x-1)>0 && (pasos[x-1][y]!=0 || mapa[x-1][y]=='E') && pasos[x-1][y]<p_mejor) {
        p_mejor=pasos[x-1][y];
        l_mejor='U';
    }
    return l_mejor;
}

void querys() {
    int q,x,y;
    cin >> q;
    while(q--) {
        cin >> x >> y;
        cout << consulta(x,y) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
  	leer();
  	propaga();
  	/*for(int i=1; i<=filas; i++) {
        for(int j=1; j<=columnas; j++) {
            cout << pasos[i][j] << " ";
        }
        cout << "\n";
  	}*/
  	querys();
  	return 0;
}
