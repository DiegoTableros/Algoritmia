#include <bits/stdc++.h>

using namespace std;
struct punto {
    int x;
    int y;
};
punto arre[100002];
int a,b,c,n;

long double p_punto(punto X, punto Y) {
    return X.x*Y.x+X.y*Y.y;
}

long double p_cruz(punto X, punto Y) {
    return X.x*Y.y-X.y*Y.x;
}

void leer() {
    cin >> n;
    a=1;
    b=2;
    c=3;
    for(int i=1; i<=n; i++) {
        cin >> arre[i].x;
        cin >> arre[i].y;
    }
    bool bandera=0;
    ///Primero encontramos un triangulo con area positiva
    while(bandera==0) {
        ///Comprobamos que signo tiene
        punto ab,ac;
        ab.x=arre[b].x-arre[a].x;
        ab.y=arre[b].y-arre[a].y;
        ac.x=arre[c].x-arre[a].x;
        ac.y=arre[c].y-arre[a].y;
        if(p_cruz(ab,ac)<=0) {
            ///Cambiamos de punto
            c++;
        } else {
            bandera=1;
        }
    }
}

bool punto_en_segmento(punto X, punto Y, punto Z) {
    ///Ver si el punto Z esta en el segmento XY
    punto aux1,aux2,aux3,aux4;
    ///Y-X
    aux1.x=Y.x-X.x;
    aux1.y=Y.y-X.y;
    ///Z-X
    aux2.x=Z.x-X.x;
    aux2.y=Z.y-X.y;
    ///X-Z
    aux3.x=X.x-Z.x;
    aux3.y=X.y-Z.y;
    ///Y-Z
    aux4.x=Y.x-Z.x;
    aux4.y=Y.y-Z.y;
    return (p_cruz(aux1,aux2)==0) && (p_punto(aux3,aux4)<=0);
}

bool en_medio(punto A,punto B,punto C, punto I) {
    punto ab,ac;
    ab.x=B.x-A.x;
    ab.y=B.y-A.y;
    ac.x=C.x-A.x;
    ac.y=C.y-A.y;
    long double area_triangulo=(abs(p_cruz(ab,ac)))/2;
    long double area=0;
    ab.x=A.x-I.x;
    ab.y=A.y-I.y;
    ac.x=B.x-I.x;
    ac.y=B.y-I.y;
    area+=(p_cruz(ab,ac))/2;
    ab.x=C.x-I.x;
    ab.y=C.y-I.y;
    area+=(p_cruz(ac,ab))/2;
    ac.x=A.x-I.x;
    ac.y=A.y-I.y;
    area+=(p_cruz(ab,ac))/2;
    ///Si las areas coinciden
    if(area==area_triangulo) {
        return true;
    }
    return false;
}

void constelacion() {
    ///En este punto el triango abc tiene area positiva, vamos a comprobar los requerimientos
    ///Calculamos el area del triangulo, sera de ayuda
    for(int i=1; i<=n; i++) {
        if(i!=a && i!=b && i!=c) {
            ///Comprobamos los cuatro casos con el punto i
            ///Verificamos que no este en ningun segmento o en medio
            if(punto_en_segmento(arre[a],arre[b],arre[i])) {
                ///Cambiamos a b
                b=i;
            } else if(punto_en_segmento(arre[b],arre[c],arre[i])) {
                ///Cambiamos a c
                c=i;
            } else if(punto_en_segmento(arre[c],arre[a],arre[i])) {
                ///Cambiamos a a
                a=i;
            } else if(en_medio(arre[a],arre[b],arre[c],arre[i])) {
                ///Cambiamos a c
                c=i;
            }
        }
    }
    cout << a << " " << b << " " << c;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    leer();
    constelacion();
    return 0;
}
