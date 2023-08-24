#include <bits/stdc++.h>
#define aum_x 20000

using namespace std;
int n,m,j,x,y,cont;
struct c{
    int centro,radio,disparo;
};
c circulo[10002];
struct p{
    int uno,dos;
};
p cubeta[40002];

void leer() {
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> circulo[i].centro;
        circulo[i].centro+=aum_x;
        cin >> circulo[i].radio;
        ///Hacemos la propagacion del dominio de este circulo
        cubeta[circulo[i].centro].uno=i;
        ///Vamos a la derecha
        j=circulo[i].centro+1;
        for(int aux=1; aux<=circulo[i].radio && j<=40000; aux++) {
            if(cubeta[j].uno==0) {
                cubeta[j].uno=i;
            } else {
                cubeta[j].dos=i;
            }
            j++;
        }
        ///Vamos a la izquierda
        j=circulo[i].centro-1;
        for(int aux=1; aux<=circulo[i].radio && j>=0; aux++) {
            if(cubeta[j].uno==0) {
                cubeta[j].uno=i;
            } else {
                cubeta[j].dos=i;
            }
            j--;
        }
    }
}

bool dentro(int x, int y, int k) {
    ///Veamos si el punto (x,y) esta dentro del circulo K
    int radio=circulo[k].radio*circulo[k].radio;
    x-=circulo[k].centro;
    x*=x;
    y*=y;
    if((x+y<=radio)) {
        return true;
    }
    return false;
}

void disparos() {
    int aux;
    cin >> m;
    for(int i=1; i<=m; i++) {
        cin >> x >> y;
        x+=aum_x;
        ///Ahora buscamos a que le pegamos
        if(cubeta[x].uno!=0) {
            aux=cubeta[x].uno;
            ///Es probable que le demos a este, vemos si ya tiene disparo asignado
            if(circulo[aux].disparo==0) {
                ///Si le damos
                if(dentro(x,y,aux)) {
                    ///Asignamos disparo
                    cont++;
                    circulo[aux].disparo=i;
                }
            }
        }
        ///Comprobamos el segundo
        if(cubeta[x].dos!=0) {
            aux=cubeta[x].dos;
            if(circulo[aux].disparo==0) {
                if(dentro(x,y,aux)) {
                    cont++;
                    circulo[aux].disparo=i;
                }
            }
        }
    }
    ///Finalmente imprimimos los disparos
    cout << cont << "\n";
    for(int i=1; i<=n; i++) {
        if(circulo[i].disparo!=0) {
            cout << circulo[i].disparo << " ";
        } else {
            cout << "-1 ";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    leer();
    disparos();
    return 0;
}
