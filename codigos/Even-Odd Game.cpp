#include <bits/stdc++.h>
using namespace std;
vector <int> pares;
int t,n;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    int aux;
    while(t--) {
        cin >> n;
        for(int i=1; i<=n; i++) {
            cin >> aux;
            pares.push_back(aux);
        }
        sort(pares.begin(),pares.end());
        //sort(impares.begin(),impares.end());
        long long int alice=0,bob=0;
        //int a=pares.size()-1;
        //int b=impares.size()-1;
        int a=n-1;
        bool va_alice=1;
        while(n>0) {
            //cout << alice << " " << bob << "\n";
            if(va_alice) {
                va_alice=0;
                if(pares[a]%2==0) {
                    alice+=pares[a];
                }
                a--;
                n--;
            } else {
                va_alice=1;
                if(pares[a]%2==1) {
                    bob+=pares[a];
                }
                a--;
                n--;
            }
        }
        if(alice>bob) {
            cout << "Alice\n";
        } else if(bob>alice) {
            cout << "Bob\n";
        } else {
            cout << "Tie\n";
        }
        pares.clear();
    }
    return 0;
}
