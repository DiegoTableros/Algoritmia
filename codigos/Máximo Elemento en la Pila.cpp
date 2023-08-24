#include <bits/stdc++.h>
using namespace std;
int com,n,aux,maximo;
stack <int> pila;
stack <int> maxi;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    maxi.push(INT_MIN);
    pila.push(INT_MIN);
    cin >> n;
    while(n--) {
        cin >> com;
        if(com==1) {
            cin >> aux;
            pila.push(aux);
            if(aux>maxi.top()) {
                maxi.push(aux);
            } else {
                maxi.push(maxi.top());
            }
        } else if(com==2) {
            pila.pop();
            maxi.pop();
        } else {
            cout << maxi.top() << "\n";
        }
    }
    return 0;
}
