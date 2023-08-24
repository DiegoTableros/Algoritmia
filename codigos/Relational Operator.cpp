#include <iostream>

using namespace std;
int t,a,b;

void comparar() {
    cin >> a >> b;
    if(a<b) {
        cout << "<\n";
    } else if (a>b) {
        cout << ">\n";
    } else {
        cout << "=\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    for(int i=1; i<=t; i++) {
        comparar();
    }
    return 0;
}
