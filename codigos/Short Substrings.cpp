#include <bits/stdc++.h>
using namespace std;
int t;
string a,b;

void leer() {
    cin >> b;
    for(int i=0; i<b.size(); i+=2) {
        a+=b[i];
    }
    if(b.size()%2==0) {
        a+=b[b.size()-1];
    }
    cout << a << "\n";
    a.clear();
    b.clear();
    return;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    for(int x=1; x<=t; x++) {
        leer();
    }
    return 0;
}
