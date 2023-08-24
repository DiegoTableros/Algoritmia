#include <bits/stdc++.h>

using namespace std;
long long int t,n,a,b,c,maxi;

void leer() {
    cin >> t;
    for(int i=1; i<=t; i++) {
        cin >> a >> b >> c >> n;
        ///Sacamos el mayor
        maxi=max(a,max(b,c));
        ///Tenemos que igualar las monedas, las restamos de N
        if(maxi==a) {
            n-=(a-b);
            n-=(a-c);
        } else if (maxi==b) {
            n-=(b-a);
            n-=(b-c);
        } else {
            n-=(c-a);
            n-=(c-b);
        }
        ///Si las monedas son negativas, bai
        if(n<0) {
            cout << "NO\n";
        } else {
            ///Vemos si es divisible entre 3
            if(n%3==0) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    leer();
    return 0;
}
