#include <bits/stdc++.h>
using namespace std;
string arre[100002];
int n;
string aux,rever;

void leer() {
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> aux;
        sort(aux.begin(),aux.end());
        reverse(aux.begin(),aux.end());
        for(int x=aux.size(); x<=18; x++) {
            aux+=':';
        }
        arre[i]=aux;
    }
    sort(arre+1,arre+n+1);
    for(int i=n; i>=1; i--) {
        for(int j=0; j<=18; j++) {
            if(arre[i][j]!=':') {
                cout << arre[i][j];
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    leer();
    return 0;
}
