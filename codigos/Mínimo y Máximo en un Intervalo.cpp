#include <bits/stdc++.h>
using namespace std;
int n,c;
int arre[1000002];
int st_menor[4000008];
int st_mayor[4000008];
#define mas_infinito 1e8
#define men_infinito -1e8

int construye_menor(int nodo, int izq, int der) {
    ///Caso base, rango [i,i]
    if(izq==der) {
        ///Guardamos y retornamos
        return st_menor[nodo]=arre[izq];
    }
    ///Lanzamos el constructor a los hijos
    int mitad=(izq+der)/2;
    int izquierda=construye_menor(nodo*2,izq,mitad);
    int derecha=construye_menor(nodo*2+1,mitad+1,der);
    st_menor[nodo]=izquierda<derecha?izquierda:derecha;
    return st_menor[nodo];
}

int construye_mayor(int nodo, int izq, int der) {
    ///Caso base, rango [i,i]
    if(izq==der) {
        ///Guardamos y retornamos
        return st_mayor[nodo]=arre[izq];
    }
    ///Lanzamos el constructor a los hijos
    int mitad=(izq+der)/2;
    int izquierda=construye_mayor(nodo*2,izq,mitad);
    int derecha=construye_mayor(nodo*2+1,mitad+1,der);
    st_mayor[nodo]=izquierda>derecha?izquierda:derecha;
    return st_mayor[nodo];
}

int consulta_menor(int nodo, int izq, int der, int a, int b) {
    ///Caso rango que excluye a [a,b]
    if(b<izq || a>der) {
        ///Devolvemos algo muy grande
        return mas_infinito;
    }
    ///Caso rango totalmente contenido en [a,b]
    if(a<=izq && der<=b) {
        ///Retornamos todo este rango
        return st_menor[nodo];
    }
    ///Caso rango parcialmente contenido en [a,b]
    int mitad=(izq+der)/2;
    int izquierda=consulta_menor(nodo*2,izq,mitad,a,b);
    int derecha=consulta_menor(nodo*2+1,mitad+1,der,a,b);
    ///Retornamos el menor
    if(izquierda<derecha) {
        return izquierda;
    }
    return derecha;
}

int consulta_mayor(int nodo, int izq, int der, int a, int b) {
    ///Caso rango que excluye a [a,b]
    if(b<izq || a>der) {
        ///Devolvemos algo muy grande
        return men_infinito;
    }
    ///Caso rango totalmente contenido en [a,b]
    if(a<=izq && der<=b) {
        ///Retornamos todo este rango
        return st_mayor[nodo];
    }
    ///Caso rango parcialmente contenido en [a,b]
    int mitad=(izq+der)/2;
    int izquierda=consulta_mayor(nodo*2,izq,mitad,a,b);
    int derecha=consulta_mayor(nodo*2+1,mitad+1,der,a,b);
    ///Retornamos el menor
    if(derecha>izquierda) {
        return derecha;
    }
    return izquierda;
}

int actualiza_menor(int nodo, int izq, int der, int pos, int v) {
    ///Caso rango no contiene a [pos]
    if(pos<izq || der<pos) {
        ///No participa en la actualización, devuelve lo que tiene
        return st_menor[nodo];
    }
    ///Caso igual al que queremos actualizar
    if(izq==pos && der==pos) {
        return st_menor[nodo]=v;
    }
    int mitad=(izq+der)/2;
    int izquierda=actualiza_menor(nodo*2,izq,mitad,pos,v);
    int derecha=actualiza_menor(nodo*2+1,mitad+1,der,pos,v);
    ///Dejamos el menor
    if(izquierda<derecha) {
        st_menor[nodo]=izquierda;
    } else {
        st_menor[nodo]=derecha;
    }
    return st_menor[nodo];
}

int actualiza_mayor(int nodo, int izq, int der, int pos, int v) {
    ///Caso rango no contiene a [pos]
    if(pos<izq || der<pos) {
        ///No participa en la actualización, devuelve lo que tiene
        return st_mayor[nodo];
    }
    ///Caso igual al que queremos actualizar
    if(izq==pos && der==pos) {
        return st_mayor[nodo]=v;
    }
    int mitad=(izq+der)/2;
    int izquierda=actualiza_mayor(nodo*2,izq,mitad,pos,v);
    int derecha=actualiza_mayor(nodo*2+1,mitad+1,der,pos,v);
    ///Dejamos el menor
    if(izquierda<derecha) {
        st_mayor[nodo]=derecha;
    } else {
        st_mayor[nodo]=izquierda;
    }
    return st_mayor[nodo];
}

void leer() {
    cin >> n >> c;
    for(int i=1; i<=n; i++) {
        cin >> arre[i];
    }
    ///Construir el segment tree
    construye_menor(1,1,n);
    construye_mayor(1,1,n);
    ///Preguntas
    char com;
    int a,b;
    while(c--) {
        cin >> com >> a >> b;
        if(com=='C') {
            ///Consulta de maximo y minimo en el rango [a,b]
            cout << consulta_menor(1,1,n,a,b) << " ";
            cout << consulta_mayor(1,1,n,a,b) << "\n";
        } else {
            ///Actualización de un valor
            actualiza_mayor(1,1,n,a,b);
            actualiza_menor(1,1,n,a,b);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    leer();
    return 0;
}
