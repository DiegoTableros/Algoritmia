#include <bits/stdc++.h>

using namespace std;
long long int t,n,a,n_original,b,c,cont;

void proceso() {
    a=b=c=0;
    cin >> n_original;
    n=n_original;
    cont=2;
    while(cont*cont<=n) {
        ///Vemos si el actual lo divide
        if(n%cont==0) {
            ///Actualizamos n
            n/=cont;
            if(a==0) {
                a=cont;
            } else {
                b=cont;
                c=n;
                if(c!=1 && c!=a && c!=b) {
                    cout << "YES\n" << a << " " << b << " " << c << "\n";
                    return;
                } else {
                    cout << "NO\n";
                    return;
                }
            }
        }
        cont++;
    }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    for(int z=1; z<=t; z++) {
        proceso();
    }
    return 0;
}
