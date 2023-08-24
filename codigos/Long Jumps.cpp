#include <iostream>
using namespace std;
int arre[200002];
int n,t;
int acum[200002];
int res;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i=1; i<=n; i++) {
            cin >> arre[i];
        }
        res=0;
        ///Empezamos desde atrás
        for(int i=n; i>=1; i--) {
            int nueva=i+arre[i];
            if(nueva>n) {
                acum[i]=arre[i];
            } else {
                acum[i]=arre[i]+acum[nueva];
            }
            if(res<acum[i]) {
                res=acum[i];
            }
        }
        cout << res << "\n";
        for(int i=1; i<=n; i++) {
            arre[i]=0;
            acum[i]=0;
        }
    }
    return 0;
}
