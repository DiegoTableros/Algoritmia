#include <bits/stdc++.h>

using namespace std;
int n, arre[1000002];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> arre[i];
    }
    sort(arre+1,arre+n+1);
    for(int i=1; i<=n; i++) {
        cout << arre[i] << " ";
    }
    return 0;
}
