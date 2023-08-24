#include <bits/stdc++.h>

using namespace std;
long long int q,x,a,MEX,meter,aux;
set <long long int> cubeta;
set <long long int>::iterator it;

long long int encuentra_menor(long long int num) {
    /*int inicio=num%x;
    while(cubeta.find(inicio)!=cubeta.end()) {
        inicio+=x;
    }
    return inicio;*/
    num-=x;
    ///Primero avanzamos mientras no estemos en la cubeta
    while(cubeta.find(num)==cubeta.end() && num>=0) {
        num-=x;
    }
    ///En este punto o somos negativos o ya encontramos alguno
    if(num>=0) {
        return num;
    }
    return LONG_LONG_MAX;
}

long long int sumas(long long int num) {
    while(cubeta.find(num)!=cubeta.end()) {
        num+=x;
    }
    return num;
}

void leer() {
    cin >> q >> x;
    for(int i=1; i<=q; i++) {
        cin >> a;
        meter=min(encuentra_menor(a),sumas(a));
        cubeta.insert(meter);
        it=cubeta.find(MEX);
        while(it!=cubeta.end()) {
            ///Encontro al MEX en la cubeta
            MEX++;
            it=cubeta.find(MEX);
        }
        for(it=cubeta.begin(); it!=cubeta.end(); it++) {
            cout << *it << " ";
        }
        cout << "\n";
        cout << MEX << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);//cin.tie(0);
    leer();
    return 0;
}
