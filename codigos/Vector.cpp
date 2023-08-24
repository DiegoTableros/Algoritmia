#include <bits/stdc++.h>
///Aqui ya viene incluida <vector>
using namespace std;
int n,aux;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    vector <int> vec(n);
    vec.push_back(7);
    for(int i=0; i<vec.size(); i++) {
        cout << vec[i] << " ";
    }
    return 0;
}
