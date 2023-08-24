#include <bits/stdc++.h>

using namespace std;
struct punto {
    int x;
    int y;
};
punto cuadra_1[6];
punto cuadra_2[6];
punto ciento_dos;

punto resta_vec(punto A, punto B) {
    punto aux;
    aux.x=A.x-B.x;
    aux.y=A.y-B.y;
    return aux;
}

int p_punto(punto A, punto B) {
    return A.x*B.x+A.y*B.y;
}

int p_cruz(punto A, punto B) {
    return A.x*B.y-A.y*B.x;
}

bool punto_en_segmento(punto A, punto B, punto P) {
    return (p_cruz(resta_vec(B,A),resta_vec(P,A))==0) && (p_punto(resta_vec(A,P),resta_vec(B,P))<=0);
}

void leer() {
    for(int i=1; i<=4; i++) {
        cin >> cuadra_1[i].x >> cuadra_1[i].y;
    }
    for(int i=1; i<=4; i++) {
        cin >> cuadra_2[i].x >> cuadra_2[i].y;
    }
    ciento_dos.x=102;
    ciento_dos.y=102;
}

void proceso() {
    ///Primero debemos ver si algun punto de C_1 esta en algun borde de C_2
    bool bandera=0;
    for(int i=1; i<=4 && bandera==0; i++) {
        for(int j1=1; j1<=4 && bandera==0; j1++) {
            int j2=j1+1;
            if(j2==5) {
                j2=1;
            }
            if(punto_en_segmento(cuadra_2[j1],cuadra_2[j2],cuadra_1[i])) {
                ///Esta en el segmento, ya valio
                bandera=1;
            }
        }
    }
    if(bandera) {
        ///Se intersecan
        cout << "YES";
        return;
    }
    ///Ahora vemos si algun punto de C_2 esta en C_1
    for(int i=1; i<=4 && bandera==0; i++) {
        for(int j1=1; j1<=4 && bandera==0; j1++) {
            int j2=j1+1;
            if(j2==5) {
                j2=1;
            }
            if(punto_en_segmento(cuadra_1[j1],cuadra_1[j2],cuadra_2[i])) {
                ///Esta en el segmento, ya valio
                bandera=1;
            }
        }
    }
    if(bandera) {
        ///Se intersecan
        cout << "YES";
        return;
    }
    ///Ahora solo queda checar si algun punto esta dentro
    ///Sacamos area del primer cuadrado
    long double area_1=0;
    for(int i1=1; i1<=4; i1++) {
        int i2=i1+1;
        if(i2==5) {
            i2=1;
        }
        ///Sacamos el area
        area_1+=(p_cruz(resta_vec(cuadra_1[i2],ciento_dos),resta_vec(cuadra_1[i1],ciento_dos)))/2;
    }
    area_1=abs(area_1);
    long double area_2=0;
    for(int i1=1; i1<=4; i1++) {
        int i2=i1+1;
        if(i2==5) {
            i2=1;
        }
        ///Sacamos el area
        area_2+=(p_cruz(resta_vec(cuadra_2[i2],ciento_dos),resta_vec(cuadra_2[i1],ciento_dos)))/2;
    }
    area_2=abs(area_2);
    ///Ahora comprobamos que ningun punto de C_1 este dentro de C_2
    for(int i=1; i<=4 && bandera==0; i++) {
        long double area=0;
        for(int i1=1; i1<=4 && bandera==0; i1++) {
            int i2=i1+1;
            if(i2==5) {
                i2=1;
            }
            ///Sacamos el area
            area+=(p_cruz(resta_vec(cuadra_2[i2],cuadra_1[i]),resta_vec(cuadra_2[i1],cuadra_1[i])))/2;
        }
        area=abs(area);
        ///Si el area es igual, esta dentro
        if(area==area_2) {
            bandera=1;
        }
    }
    if(bandera) {
        cout << "YES";
        return;
    }
    ///Ahora comprobamos que ningun punto de C_2 este dentro de C_1
    for(int i=1; i<=4 && bandera==0; i++) {
        long double area=0;
        for(int i1=1; i1<=4 && bandera==0; i1++) {
            int i2=i1+1;
            if(i2==5) {
                i2=1;
            }
            ///Sacamos el area
            area+=(p_cruz(resta_vec(cuadra_1[i2],cuadra_2[i]),resta_vec(cuadra_1[i1],cuadra_2[i])))/2;
        }
        area=abs(area);
        ///Si el area es igual, esta dentro
        if(area==area_1) {
            bandera=1;
        }
    }
    if(bandera) {
        cout << "YES";
        return;
    }
    ///Si no pasa ningun casi, imprimimos NO
    cout << "NO";
    return;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    leer();
    proceso();
    return 0;
}
