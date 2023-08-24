#include <bits/stdc++.h>
using namespace std;
int t;
int n,k;
string arre;

int caso() {
    cin >> n >> k;
    cin >> arre;
    ///Mesas iniciales
    for(int i=0; i<n; i++) {
        if(arre[i]=='1') {
            int ini=(i-k)<0?0:i-k;
            int fin=(i+k)>=n?(n-1):i+k;
            for(i=ini; i<=fin; i++) {
                arre[i]='1';
            }
            i--;
        }
    }
    ///Mesas que pueden estar despues
    int res=0;
    for(int i=0; i<n; i++) {
        if(arre[i]=='0') {
            res++;
            int ini=(i-k)<0?0:i-k;
            int fin=(i+k)>=n?(n-1):i+k;
            for(i=ini; i<=fin; i++) {
                arre[i]='1';
            }
            i--;
        }
    }
    arre.clear();
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    for(int x=1; x<=t; x++) {
        cout << caso() << "\n";
    }
    return 0;
}
