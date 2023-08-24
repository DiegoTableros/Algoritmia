#include <bits/stdc++.h>

using namespace std;
#define P 1
#define NP 0
int n,num[202];
string aux,res;

bool valido(int ind, bool desicion) {
    ///Solo debemos checar la posicion ind y la ind-1
    bool bandera=1;
    ///Checamos la posicion ind
    return bandera;
}


bool f(int i) {
    bool poner=0,no_poner=0;
    ///Si es valido poner una mina en la posicion i
    if(valido(i,P)) {
        poner=f(i+1);
    }
    ///Si es valido no poner una mina en i
    if(valido(i,NP)) {
        no_poner=f(i+1);
    }
    ///Checamos cual desicion es 1, esa es la correcta
    if(poner) {
        ///Debemos poner una mina aqui
        res[i]='*';
        ///y es camino correcto
        return 1;
    }
    if(no_poner) {
        res[i]='.';
        return 1;
    }
    return 0;
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    cin >> aux;
    for(int i=0; i<n; i++) {
        res[i]='\0';
        switch(aux[i]) {
        case '0':
            num[i]=0;
            break;
        case '1':
            num[i]=1;
            break;
        case '2':
            num[i]=2;
            break;
        case '3':
            num[i]=3;
            break;
        }
    }

    return 0;
}
