#include <bits/stdc++.h>
using namespace std;
int t,n,m;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
  	for(int i=1;i<=t;i++){
        cin >> n >> m;
        int aux1,aux2;
        if(m%2==0) {
            aux1=m/2;
            aux2=m/2;
        } else {
            aux1=m/2;
            aux2=(m/2)+1;
        }
        if(n==1) {
            cout << 0 << "\n";
        } else if(n==2) {
            cout << m << "\n";
        } else {
            cout << ((2*aux1)+(2*aux2)) << "\n";
        }
    }
    return 0;
}
