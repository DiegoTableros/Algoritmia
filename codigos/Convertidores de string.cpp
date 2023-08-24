//De string a dato: stoi, stod/stold, stoll
//De dato a string: to_string
#include <bits/stdc++.h>
using namespace std;
string numero;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long int grande;
    cin >> grande;
    cout << to_string(grande).size();
    return 0;
}
