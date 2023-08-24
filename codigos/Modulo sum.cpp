#include <bits/stdc++.h>

using namespace std;
int n,m;
long long int arre[1000002];
bool visit[]

bool dp(nn,S) {
    if(S==0) {
        return true;
    }
    if(nn==0 && S>0) {
        return false;
    }
    if(visit[nn][S]) {
        return memo[nn][S];
    }
}

void leer() {
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        cin >> arre[i];
    }
    if(n>m) {
        cout << "YES";
        return;
    }
    if(dp(n,arre[n]%m)) {
        cout << "YES";
        return;
    }
    cout << "NO";
    return;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    leer();
    return 0;
}
