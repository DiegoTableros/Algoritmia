#include <bits/stdc++.h>

using namespace std;
int n,cont;
bool band;

void leer() {
    cin >> n;
    if(n%2==1) {
        n-=3;
        cont=1;
        band=1;
    }
    cont+=n/2;
    cout << cont << "\n";
    if(band==1) {
        cont--;
        cout << "3 ";
    }
    for(int i=1; i<=cont; i++) {
        cout << "2 ";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    leer();
    return 0;
}
