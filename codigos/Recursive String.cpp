#include <bits/stdc++.h>
using namespace std;
int fibo[37];
int n,k;

void calcula(){
    fibo[0]=1;
    fibo[1]=1;
    fibo[2]=1;
    for(int i=3; i<=n; i++) {
        fibo[i]=fibo[i-1]+fibo[i-2]+fibo[i-3];
    }
}

void busca(int nivel) {
    if(nivel==0) {
        cout << "a"; return;
    }
    if(nivel==1) {
        cout << "b"; return;
    }
    if(nivel==2) {
        cout << "c"; return;
    }
    ///Si no es un caso base debemos avanzar en el arbol
    for(int i=1; i<=3; i++) {
        ///Restamos para ver que rama caemos
        if(k<=fibo[nivel-i]) {
            ///Avanzamos a esta rama
            busca(nivel-i);
            return;
        } else {
            ///Restamos para saltarnos todo esto
            k-=fibo[nivel-i];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    calcula();
    if(fibo[n]<k) {
        cout << "-1";
    } else {
        busca(n);
    }
    return 0;
}
