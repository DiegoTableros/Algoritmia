#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli n,w;
lli peso[102],valor[102];
lli dp[102][2];
lli pesoacum[102][2];
#define infneg -1e12

void mochila() {
    ///Vamos subiendo
    for(int act=n; act>0; act--) {
        //TOMAR
        lli uno=infneg,dos=infneg;
        if(pesoacum[act+1][0]+peso[act]<=w) {
            uno=dp[act+1][0]+valor[act];
        }
        if(pesoacum[act+1][1]+peso[act]<=w) {
            dos=dp[act+1][1]+valor[act];
        }
        ///Dejamos el mas grande
        if(uno>dos) {
            pesoacum[act][0]=pesoacum[act+1][0]+peso[act];
            dp[act][0]=uno;
        } else {
            pesoacum[act][0]=pesoacum[act+1][1]+peso[act];
            dp[act][0]=dos;
        }
        //NO TOMAR
        uno=infneg; dos=infneg;
        if(pesoacum[act+1][0]<=w) {
            uno=dp[act+1][0];
        }
        if(pesoacum[act+1][1]<=w) {
            dos=dp[act+1][1];
        }
        ///Dejamos el mas grande
        if(uno>dos) {
            pesoacum[act][1]=pesoacum[act+1][0];
            dp[act][1]=uno;
        } else {
            pesoacum[act][1]=pesoacum[act+1][1];
            dp[act][1]=dos;
        }
    }
    ///Al final el resultado es el maximo de tomar y no tomar de n=1
    cout << max(dp[1][0],dp[1][1]);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> w;
    for(int i=1; i<=n; i++) {
        cin >> peso[i] >> valor[i];
    }
    mochila();
    for(int i=1; i<=n; i++) {
        printf("%6lld",dp[i][0]);
        printf("%6lld\n",dp[i][1]);
    }
    return 0;
}
