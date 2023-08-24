#include <bits/stdc++.h>

using namespace std;
long long int n,k;
long long int arre[1000002];

long long int lcm(long long int a, long long int b) {
    long long int res=a*b;
    res/=__gcd(a,b);
    return res;
}

void leer() {
    cin >> n >> k;
    for(int i=1; i<=n; i++) {
        cin >> arre[i];
    }
    long long int res=1;
    for(int i=1; i<=n; i++) {
        res=lcm(res,__gcd(arre[i],k));
    }
    if(res==k) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    leer();
    return 0;
}
