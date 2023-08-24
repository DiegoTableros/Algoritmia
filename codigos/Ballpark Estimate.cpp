#include <bits/stdc++.h>

using namespace std;
long long int n,a,b,N;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    n=N;
    a=1;
    b=1;
    while(n>=10) {
        n/=10;
        a*=10;
        b*=10;
    }
    ///Al final n tiene el numero mas significativo, multiplicamos
    if(N<10) {
        a=N;
        b=10;
    } else {
        a*=n;
        b*=(n+1);
    }
    ///Ahora sacamos el de menor distancia
    if(abs(N-b)<=abs(N-a)) {
        cout << b;
    } else {
        cout << a;
    }
    return 0;
}
