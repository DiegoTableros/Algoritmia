#include <bits/stdc++.h>
using namespace std;
char cadena[52];
char cadena_ordenada[52];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> cadena;
    while(strcmp(cadena,"#")!=0) {
        bool se_puede=next_permutation(cadena,cadena+strlen(cadena));
        if(se_puede) {
            cout << cadena << "\n";
        } else {
            cout << "No Successor\n";
        }
        cin >> cadena;
    }
    return 0;
}
