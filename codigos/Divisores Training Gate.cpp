#include <bits/stdc++.h>

using namespace std;
int n;

void divisores() {
    int raiz=sqrt(n);
    set <int> SET;
    for(int i=1; i<=raiz; i++) {
        if(n%i==0) {
            ///Divisor
            SET.insert(i);
            SET.insert(n/i);
        }
    }
    cout << SET.size() << "\n";
    while(!SET.empty()) {
        cout << *SET.begin() << " ";
        SET.erase(SET.begin());
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    while(n!=0) {
        divisores();
        cin >> n;
    }
    return 0;
}
