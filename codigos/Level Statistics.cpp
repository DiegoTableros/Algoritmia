#include <bits/stdc++.h>

using namespace std;
int t,n,a,b;

void leer() {
    cin >> n;
    bool posible=1;
    int plays=0,clears=0;
    for(int i=1; i<=n; i++) {
        cin >> a >> b;
        if(posible) {
            ///Primero comprobamos si aumentaron
            if(a<plays || b<clears) {
                posible=0;
            }
            if(b>a) {
                posible=0;
            }
            if(b>(clears+a-plays)) {
                posible=0;
            }
            plays=a;
            clears=b;
        }
    }
    if(posible) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    for(int i=1; i<=t; i++) {
        leer();
    }
    return 0;
}
