#include <iostream>
using namespace std;
int n,uno,dos,t;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int aux;
    cin >> t;
    while(t--) {
        cin >> n;
        uno=0; dos=0;
        for(int i=1; i<=n; i++) {
            cin >> aux;
            if(aux==1) {
                uno++;
            } else {
                dos++;
            }
        }
        if(uno%2==1) {
            cout << "NO\n";
            continue;
        }
        if(dos%2==0) {
            cout << "YES\n";
        } else {
            uno-=2;
            if(uno%2==0 && uno>=0) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}
