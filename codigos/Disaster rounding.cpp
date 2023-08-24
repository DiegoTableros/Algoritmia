#include <bits/stdc++.h>
#include <math.h>
using namespace std;
long long int n,num,sum;
long long int aux,aux2;
#define MOD 1000000007

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    num=round(sqrt(n));
    num--;
    ///sum+=((num*(num+1)*(2*num+1))/3);
    sum=num;
    sum%=MOD;
    sum*=(num+1);
    sum%=MOD;
    sum*=(2*num+1);
    sum%=MOD;
    sum/=3;
    sum%=MOD;
    ///Ya tenemos toda la suma del bloque anterior
    aux=n-(num*(num+1));
    aux%=MOD;
    aux*=(num+1);
    aux%=MOD;
    sum+=aux;
    sum%=MOD;
    cout << sum;
    return 0;
}
