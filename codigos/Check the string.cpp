#include <bits/stdc++.h>

using namespace std;
string cadena;

bool leer() {
    cin >> cadena;
    int a=0,b=0,c=0;
    ///Contamos las letras
    for(int i=0; i<cadena.size(); i++) {
        if(cadena[i]=='a') {
            a++;
        } else if(cadena[i]=='b') {
            b++;
        }else {
            c++;
        }
    }
    ///Continuamos si al menos hay una "a" o "b"
    if(a==0 || b==0) {
        return false;
    }
    ///Continuamos si C==A o C==B
    if(c!=a && c!=b) {
        return false;
    }
    ///Ahora checamos que esten en orden
    int i;
    for(i=0; i<a; i++) {
        if(cadena[i]!='a') {
            return false;
        }
    }
    ///Ahora checamos el orden de las b
    b+=a;
    for(;i<b; i++) {
        if(cadena[i]!='b') {
            return false;
        }
    }
    ///Si sobrevivimos a todo, listo
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(leer()) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}
