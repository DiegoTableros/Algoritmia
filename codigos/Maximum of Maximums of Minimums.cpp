#include <bits/stdc++.h>

using namespace std;
long long int n,num,minimo,maximo,k,primero,ultimo;

void leer() {
    cin >> n >> k;
    for(int i=1; i<=n; i++) {
        cin >> num;
        if(i==1) {
            minimo=num;
            maximo=num;
            primero=num;
        }
        if(num<minimo) {
            minimo=num;
        } else if(num>maximo) {
            maximo=num;
        }
        if(i==n) {
            ultimo=num;
        }
    }
    if(k==1) {
        cout << minimo;
    } else if(k==2){
        cout << max(primero,ultimo);
    } else {
        cout << maximo;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    leer();
    return 0;
}
