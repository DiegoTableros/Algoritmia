#include <bits/stdc++.h>

using namespace std;
int n,k;
int arre[100002];
char segment_tree[400002];

void construir(int ini, int fin, int nodo) {
    if(ini==fin) {
        if(arre[ini]>0) {
            segment_tree[nodo]='+';
        } else if(arre[ini]<0) {
            segment_tree[nodo]='-';
        } else {
            segment_tree[nodo]='0';
        }
        return;
    }
    int mitad=(ini+fin)/2;
    int hijo=nodo*2;
    construir(ini,mitad,hijo);
    construir(mitad+1,fin,hijo+1);
    ///Ahora guardamos +,- o 0
    if(segment_tree[hijo]=='0' || segment_tree[hijo+1]=='0') {
        segment_tree[nodo]='0';
    } else if(segment_tree[hijo]==segment_tree[hijo+1]) {
        segment_tree[nodo]='+';
    } else {
        segment_tree[nodo]='-';
    }
    return;
}

char query(int ini, int fin, int nodo, int a, int b) {
    ///Caso en que se salga del rango
    if(b<ini || a>fin) {
        return '+';
    }
    ///Caso de intervalo totalmente contenido
    if(a<=ini && fin<=b) {
        return segment_tree[nodo];
    }
    ///Si no, el intervalo [ini,fin] contiene en parte a [a,b]
    char izq,der;
    int mitad=(ini+fin)/2,hijo=nodo*2;
    izq=query(ini,mitad,hijo,a,b);
    der=query(mitad+1,fin,hijo+1,a,b);
    if(izq=='0' || der=='0') {
        return '0';
    } else if(izq!=der) {
        return '-';
    } else {
        return '+';
    }
}

char actualiza(int ini, int fin, int nodo, int i, int valor) {
    ///Caso intervalo ajeno
    if(fin<i || ini>i) {
        return segment_tree[nodo];
    }
    ///Caso igual al intervalo a cambiar [i,i]
    if(ini==i && fin==i) {
        ///Cambiamos
        arre[i]=valor;
        if(valor>0) {
            segment_tree[nodo]='+';
        } else if(valor<0) {
            segment_tree[nodo]='-';
        } else {
            segment_tree[nodo]='0';
        }
        return segment_tree[nodo];
    }
    ///Caso intervalo [ini,fin] contiene una parte
    char izq,der;
    int mitad=(ini+fin)/2,hijo=nodo*2;
    izq=actualiza(ini,mitad,hijo,i,valor);
    der=actualiza(mitad+1,fin,hijo+1,i,valor);
    ///Actualizamos este nodo
    if(izq=='0' || der=='0') {
        segment_tree[nodo]='0';
    } else if(izq==der) {
        segment_tree[nodo]='+';
    } else {
        segment_tree[nodo]='-';
    }
    return segment_tree[nodo];
}

void leer() {
    int a,b;
    char com;
    for(int i=1; i<=n; i++) {
        cin >> arre[i];
    }
    ///Construimos segment tree
    construir(1,n,1);
    for(int x=1; x<=k; x++) {
        cin >> com >> a >> b;
        if(com=='C') {
            ///Cambiar el a-esimo por b
            actualiza(1,n,1,a,b);
        } else {
            ///Imprimir el producto de [a,b]
            cout << query(1,n,1,a,b);
        }
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    while(cin >> n) {
        cin >> k;
        leer();
    }
    return 0;
}
