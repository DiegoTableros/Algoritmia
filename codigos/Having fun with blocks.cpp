#include <iostream>

using namespace std;
struct matriz22 {
    long long int uno,dos,tres,cuatro;
};
#define MOD 1000000007
long long int k;

matriz22 multiplica(matriz22 A, matriz22 B) {
    matriz22 res;
    res.uno=A.uno*B.uno+A.dos*B.tres;
    res.uno%=MOD;
    res.dos=A.uno*B.dos+A.dos*B.cuatro;
    res.dos%=MOD;
    res.tres=A.tres*B.uno+A.cuatro*B.tres;
    res.tres%=MOD;
    res.cuatro=A.tres*B.dos+A.cuatro*B.cuatro;
    res.cuatro%=MOD;
    return res;
}

void leer() {
    cin >> k;
    ///Creamos la matriz base
    matriz22 matriz;
    matriz.uno=3;
    matriz.dos=8;
    matriz.tres=1;
    matriz.cuatro=3;
    ///Creamos la matriz respuesta
    matriz22 res;
    res.uno=1;
    res.dos=0;
    res.tres=0;
    res.cuatro=1;
    ///Restamos 1 a K
    k--;
    ///Hacemos la exponenciacion binaria tomando a K
    while(k>0) {
        ///Vemos si el bit menos significativo esta activo
        bool activo=(k & 1);
        if(activo) {
            ///Multiplicamos la respuesta por la matriz de potencias
            res=multiplica(res,matriz);
        }
        ///Multiplicamos la matriz de pontencias por si misma
        matriz=multiplica(matriz,matriz);
        ///Recorremos los bits de K
        k=k>>1;
    }
    ///En este punto ya esta elevada la matriz
    long long int nk=res.tres*3+res.cuatro;
    nk%=MOD;
    nk*=nk;
    nk%=MOD;
    cout << nk;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    leer();
    return 0;
}
