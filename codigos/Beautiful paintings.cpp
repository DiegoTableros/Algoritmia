#include <bits/stdc++.h>

using namespace std;
int n,num,res,aux;
set <int> paint;
int cubeta[1002];

void leer() {
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> num;
        cubeta[num]++;
    }
    ///Recorremos hasta ya no tener elementos
    while(n>0) {
        ///Primero rescatamos todos los numeros una sola vez
        for(int i=1; i<=1000; i++) {
            if(cubeta[i]>0) {
                cubeta[i]--;
                n--;
                paint.insert(i);
            }
        }
        ///Sumamos a la respuesta
        res+=paint.size()-1;
        ///Y eliminamos del set para la otra ronda
        paint.clear();
    }
    cout << res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    leer();
    return 0;
}
