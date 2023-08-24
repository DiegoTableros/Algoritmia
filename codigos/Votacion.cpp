#include <bits/stdc++.h>
using namespace std;

queue <short> arre[10002];
short votos[52];
bool activo[52];
short aux;
short c,v,vivos;
short mayor,v_mayor,v_menor;

bool simu() {
    ///Contamos los votos
    mayor=0,v_mayor=0,v_menor=20000;
    for(int i=1; i<=c; i++) {
        if(activo[i]) {
            if(votos[i]>v_mayor) {
                v_mayor=votos[i];
                mayor=i;
            }
            if(votos[i]<v_menor && votos[i]!=0) {
                v_menor=votos[i];
            }
        }
    }
    ///Preguntamos si alguien ya gano
    if(v_mayor>(v/2)) {
        return true;
    }
    ///Sino, debemos hacer eliminacion
    for(int i=1; i<=c; i++) {
        if(votos[i]==v_menor) {
            activo[i]=0;
            vivos--;
        }
    }
    for(int i=1; i<=v; i++) {
        if(!arre[i].empty()) {
            votos[arre[i].front()]--;
        }
        ///Mientras su preferencia actual haya sido eliminada ...
        while(!arre[i].empty() && activo[arre[i].front()]==0) {
            ///Elminamos su preferencia actual
            arre[i].pop();
        }
        ///Si quedamos en un elemento, añadimos el voto a el
        if(!arre[i].empty()) {
            votos[arre[i].front()]++;
        }
    }
    return false;
}

void leer() {
    cin >> c >> v;
    vivos=c;
    for(int i=1; i<=v; i++) {
        for(int j=1; j<=c; j++) {
            cin >> aux;
            arre[i].push(aux);
            if(j==1) {
                votos[aux]++;
            }
        }
    }
    memset(activo,1,sizeof(activo));
    bool bandera=0;
    do{
        bandera=simu();
    }while(bandera==0 && vivos>0);
    if(vivos>0) {
        cout << mayor;
    } else {
        cout << 0;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    leer();
    return 0;
}
