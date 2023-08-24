#include <bits/stdc++.h>

using namespace std;
long long int n,m,k,p,fila,num_ini,pos,dist;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    cin >> p;
    for(int i=1; i<=p; i++) {
        ///Leemos un paste
        cin >> k;
        ///Calculamos la fila donde estará
        if(k%n==0) {
            fila=k/n;
        } else {
            fila=k/n+1;
        }
        ///Calculamos el numero con el que empieza la fila
        num_ini=m*(n-1)+fila;
        ///Calculamos que posicion es este numero
        pos=n*(fila-1)+1;
        ///Calculamos a cuantos está del numero del paste, k
        dist=k-pos;
        ///Lo multiplicamos por los decrementos
        dist*=m;
        ///Y al numero de inicio de fila le restamos esto
        num_ini-=dist;
        ///Imprimimos la respuesta
        cout << num_ini << " ";
    }
    return 0;
}
