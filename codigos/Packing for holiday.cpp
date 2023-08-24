#include <bits/stdc++.h>

using namespace std;
int t,L,A,H;

bool cabe() {
    cin >> L >> A >> H;
    if(L<=20 && A<=20 && H<=20) {
        return true;
    }
    return false;
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    for(int x=1; x<=t; x++) {
        if(cabe()) {
            cout << "Case " << x << ": good\n";
        } else {
            cout << "Case " << x << ": bad\n";
        }
    }
    return 0;
}
