#include <bits/stdc++.h>
using namespace std;
long long int t,n,w,h;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    long long int res;
    while(t--) {
        cin >> w >> h >> n;
        res=1;
        while(w%2==0 && res<n) {
            w/=2;
            res*=2;
        }
        if(res>=n) {
            cout << "YES" << "\n";
            continue;
        }
        while(h%2==0 && res<n) {
            h/=2;
            res*=2;
        }
        if(res>=n) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
