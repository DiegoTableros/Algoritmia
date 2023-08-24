#include <bits/stdc++.h>
using namespace std;
int n,m,a1,a2;
long double p;
long double prob[17];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int j=1; j<=n; j++) {
        prob[j]=1.0;
    }
    for(int i=1; i<=m; i++) {
        cin >> a1 >> a2 >> p;
        prob[a2]*=(prob[a1]*p);
    }
    for(int i=1;i<=n;i++){
        cout << prob[i] << "\n";
    }
    return 0;
}
