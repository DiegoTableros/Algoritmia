#include <bits/stdc++.h>

using namespace std;
int n,i,j;
int arre[1000002];
int izq[1000002];
int der[1000002];
map <int,int> cubeta;
map <int,int> ::iterator it;

void leer() {
    cin >> n;
    for(int x=1; x<=n; x++) {
        cin >> arre[x];
    }
    ///Preparamos la cubeta de preguntas a la izquierda
    for(int i=1; i<=n; i++) {
        izq[i]=cubeta[arre[i]]+1;
        cubeta[arre[i]]++;
    }
    cubeta.clear();
    ///Preparamos la cubeta de preguntas a la derecha
    for(int i=n; i>0; i--) {
        der[i]=cubeta[arre[i]]+1;
        cubeta[arre[i]]++;
    }
}

long long int proceso() {
    long long int pares=0;
    ///Ahora recorremos las cubetas simultaneamente
    for(int i=1; i<=n; i++) {
        for(int j=i+1; j<=n; j++) {
            if(izq[i]>der[j]) {
                pares++;
            }
        }
    }
    return pares;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    leer();
    cout << proceso();
    return 0;
}
