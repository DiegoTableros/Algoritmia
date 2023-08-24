#include <bits/stdc++.h>
using namespace std;
int t,n,diez,num;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    for(int z=1; z<=t; z++) {
        cin >> n;
        queue <int> cola;
        diez=1;
        while(n>0) {
            num=n%10;
            if(num!=0) {
                cola.push(num*diez);
            }
            diez*=10;
            n/=10;
        }
        cout << cola.size() << "\n";
        while(!cola.empty()) {
            cout << cola.front() << " ";
            cola.pop();
        }
        cout << "\n";
    }
    return 0;
}
