#include <bits/stdc++.h>
using namespace std;
int n,aux;
int arre[1000];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> aux;
        arre[i]=aux;
    }
    for(int i=0; i<n; i++) {
        cout << arre[i] << " ";
    }
    return 0;
}
