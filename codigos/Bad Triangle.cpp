#include <bits/stdc++.h>
using namespace std;
int t,n,a,b,c,aux;

void leer() {
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> aux;
        if(i==1) {
            a=aux;
        } else if(i==2) {
            b=aux;
        } else if(i==n) {
            c=aux;
        }
    }
    if((a+b)<=c) {
        cout << "1 2 " << n << "\n";
    } else {
        cout << "-1\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    for(int z=1; z<=t; z++) {
        leer();
    }
    return 0;
}
