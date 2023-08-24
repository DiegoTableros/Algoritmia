#include <bits/stdc++.h>

using namespace std;
long long int n;

void leer() {
    while(cin >> n) {
        int division=n/100;
        if(division*100!=n) {
            division++;
        }
        cout << division;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    leer();
    return 0;
}
