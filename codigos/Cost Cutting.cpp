#include <iostream>

using namespace std;
int t,a,b,c;
bool bandera;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    for(int i=1; i<=t; i++) {
        cin >> a >> b >> c;
        bandera=0;
        cout << "Case " << i << ": ";
        if(a>=c && a<=b && bandera==0) {
            cout << a << "\n";
            bandera=1;
        }
        if(a>=b && a<=c && bandera==0) {
            cout << a << "\n";
            bandera=1;
        }
        if(b>=a && b<=c && bandera==0) {
            cout << b << "\n";
            bandera=1;
        }
        if(b>=c && b<=a && bandera==0) {
            cout << b << "\n";
            bandera=1;
        }
        if(c>=a && c<=b && bandera==0) {
            cout << c << "\n";
            bandera=1;
        }
        if(c>=b && c<=a && bandera==0) {
            cout << c << "\n";
            bandera=1;
        }
    }
    return 0;
}
