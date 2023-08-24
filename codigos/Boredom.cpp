#include <bits/stdc++.h>

using namespace std;
int n,aux,tope;
long long int arre[100002];
long long int cnt[100002];
long long int memo[100002];
bool visit[100002];

long long int dp(int v) {
    if(v==1) {
        return cnt[1];
    }
    if(v==0) {
        return 0;
    }
    if(visit[v]) {
        return memo[v];
    }
    visit[v]=1;
    memo[v]=max(dp(v-1),dp(v-2)+(cnt[v]*v));
    return memo[v];
}

void leer() {
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> aux;
        if(cnt[aux]==0) {
            tope++;
            arre[tope]=aux;
        }
        cnt[aux]+=1;
    }
    long long int res=0;
    for(int i=1; i<=tope; i++) {
        res=max(res,dp(arre[i]));
    }
    cout << res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    leer();
    return 0;
}
