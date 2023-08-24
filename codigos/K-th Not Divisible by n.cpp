#include <bits/stdc++.h>

using namespace std;
int n,k,t,repre,bloque;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    for(int i=1; i<=t; i++) {
        cin >> n >> k;
        bloque=k/(n-1);
        repre=(bloque*n)+1;
        n--;
        if(k%n==0) {
            cout << repre-2 << "\n";
        } else {
            cout << repre+((k%n)-1) << "\n";
        }
    }
    return 0;
}
