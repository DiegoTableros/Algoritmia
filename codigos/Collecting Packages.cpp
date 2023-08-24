#include <bits/stdc++.h>

using namespace std;
int t,n,dife;
pair <int,int> arre[1002];
string res;

void leer() {
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> arre[i].first;
        cin >> arre[i].second;
    }
    sort(arre+1,arre+n+1);
    int x=0,y=0;
    for(int i=1; i<=n; i++) {
        if(arre[i].second-y<0) {
            cout << "NO\n";
            return;
        }
        dife=arre[i].first-x;
        for(int z=1; z<=dife; z++) {
            res+='R';
        }
        x=arre[i].first;
        dife=arre[i].second-y;
        for(int z=1; z<=dife; z++) {
            res+='U';
        }
        y=arre[i].second;
    }
    cout << "YES\n";
    cout << res << "\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    for(int x=1; x<=t; x++) {
        leer();
        res.clear();
    }
    return 0;
}
