#include <bits/stdc++.h>

using namespace std;
int n,h;

void leer() {
    cin >> n >> h;
    for(int i=1; i<n; i++) {
        long double corte=i;
        corte/=n;
        corte=sqrt(corte);
        corte*=h;
        cout << fixed << setprecision(12) << corte << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    leer();
    return 0;
}
