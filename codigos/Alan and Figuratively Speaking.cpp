#include <bits/stdc++.h>
using namespace std;
string cadena;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> cadena;
    for(int i=0; i<cadena.size(); i++) {
        if(cadena[i]=='O' || cadena[i]=='o') {
            cadena[i]='0';
        } else if(cadena[i]=='I' || cadena[i]=='i') {
            cadena[i]='1';
        } else if(cadena[i]=='Z' || cadena[i]=='z') {
            cadena[i]='2';
        } else if(cadena[i]=='E' || cadena[i]=='e') {
            cadena[i]='3';
        } else if(cadena[i]=='A' || cadena[i]=='a') {
            cadena[i]='4';
        } else if(cadena[i]=='S' || cadena[i]=='s') {
            cadena[i]='5';
        } else if(cadena[i]=='G' || cadena[i]=='g') {
            cadena[i]='6';
        } else if(cadena[i]=='T' || cadena[i]=='t') {
            cadena[i]='7';
        } else if(cadena[i]=='B' || cadena[i]=='b') {
            cadena[i]='8';
        }
    }
    cout << cadena;
    return 0;
}
