#include <bits/stdc++.h>
using namespace std;
int peso[102],valor[102];
int n,w;
#define menos_infinito -1e9
///Memorizado de [maxN][maxP]
long long int memo[102][100002];

long long int dp(int i, int p) {
    if(p>w) {
        ///Si excedemos el peso de la mochila no debemos seguir
        return menos_infinito;
    }
    if(p==w) {
        ///Si estamos en el peso exacto de la mochila, terminamos
        return 0;
    }
    if(i>n) {
        ///Considerando los casos anteriores, hemos terminado
        return 0;
    }
    ///Checamos memorizado, si ya hemos calculado este valor ...
    if(memo[i][p]!=0) {
        return memo[i][p];
    }
    ///Si no, debemos tomar o no tomar
    long long int tomar,no_tomar;
    tomar=dp(i+1,p+peso[i])+valor[i];
    no_tomar=dp(i+1,p);
    ///Guardamos el maximo en nuestra casilla para el futuro ...
    memo[i][p]=max(tomar,no_tomar);
    ///Retornamos este mismo valor
    return memo[i][p];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ///Lectura
    cin >> n >> w;
    ///Leemos desde 1 hasta n
    for(int i=1; i<=n; i++) {
        cin >> peso[i] >> valor[i];
    }
    ///Imprimimos la dp
    cout << dp(1,0);
    return 0;
}
