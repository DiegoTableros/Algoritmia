#include <bits/stdc++.h>
using namespace std;
int t,n,k;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    for(int i=1; i<=t; i++) {
        cin >> n >> k;
        if(n%2==0) {
            if(k%2==0) {
                ///N par, K par
                if((n-2*(k-1))>0) {
                    cout << "YES\n";
                    for(int i=1; i<k; i++) {
                        cout << "2 ";
                    }
                    cout << (n-2*(k-1)) << "\n";
                } else if(n-(k-1)>0) {
                    cout << "YES\n";
                    for(int i=1; i<k; i++) {
                        cout << "1 ";
                    }
                    cout << (n-(k-1)) << "\n";
                } else {
                    cout << "NO\n";
                }
            }else{
                ///N par, K impar
                if((n-2*(k-1))>0) {
                    cout << "YES\n";
                    for(int i=1; i<k; i++) {
                        cout << "2 ";
                    }
                    cout << (n-2*(k-1)) << "\n";
                } else {
                    cout << "NO\n";
                }
            }
        }else{
            if(k%2==0) {
                ///N impar, K par
                cout << "NO\n";
            }else {
                ///N impar, K impar
                if((n-(k-1))>0) {
                    cout << "YES\n";
                    for(int i=1; i<k; i++) {
                        cout << "1 ";
                    }
                    cout << (n-(k-1)) << "\n";
                } else {
                    cout << "NO\n";
                }
            }
        }
    }
    return 0;
}
