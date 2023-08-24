//Modificar letras de un string
//Recorrer de inicio a fin un string
//Ordenar un string
//Buscar donde aparece un caracter
//Cuantas veces aparece un caracter

#include <bits/stdc++.h>
using namespace std;
string palabra, verbo;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> palabra;
    int conteo=count(palabra.begin(),palabra.end(),'3');
    cout << "Aparece " << conteo << " veces";
    return 0;
}
