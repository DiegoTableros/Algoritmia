#include <bits/stdc++.h>

using namespace std;
long long int n,x,d;

void leer() {
    cin >> d;
    for(int i=1; i<=d; i++) {
        cin >> x;
        n=((sqrt(1.0+8.0*x)/2.0)-0.5);
        cout << n << "\n";
        n=(n*(n+1))/2;
        cout << x-n << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    leer();
    return 0;
}
