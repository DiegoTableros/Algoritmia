#include <bits/stdc++.h>

using namespace std;
long long int n,a,b,potencia,encendido;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    while(n!=0) {
        ///Tenemos un numero para trabajar, hacemos recorrimiento
        bool toca_a=1;
        a=0;
        b=0;
        potencia=1;
        while(n>0) {
            ///Checamos si el bit actual está encendido
            encendido=n&1;
            if(encendido) {
                ///Ponemos un bit mas a quien corresponda
                if(toca_a) {
                    ///Le toca a "a"
                    a=a|potencia;
                    toca_a=0;
                } else {
                    ///Le toca a "b"
                    b=b|potencia;
                    toca_a=1;
                }
            }
            ///Recorremos el numero y aumentamos la potencia
            potencia*=2;
            n=n>>1;
        }
        cout << a << " " << b << "\n";
        ///Leemos el siguiente numero
        cin >> n;
    }
    return 0;
}
