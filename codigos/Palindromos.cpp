/**Algoritmo, funcion comprueba palindromo
    - Iniciar dos variables i,j en el inicio y fin del string
    - Mientras i sea menor o igual que j
        - Checar ¿string[i]==string[j]?
            - Si es falso retornamos false pues ya no es palindromo
        - Avanzamos i en uno
        - Retrocedemos j en uno
    - Si terminamos el ciclo i>j y concluimos que es palindromo, retorna true
**/
#include <bits/stdc++.h>
using namespace std;
string palabra;

bool es_palindromo() {
    int i=0,j=palabra.size()-1;
    while(i<=j) {
        if(palabra[i]!=palabra[j]) {
            ///No coinciden, ya no es palindromo
            return false;
        }
        ///Avanzamos los iteradores
        i++; j--;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> palabra;
    if(es_palindromo()==true){
        cout << "Ciertamente es un palindromo =)";
    } else {
        cout << "No es un anitalavalatina =(";
    }
    return 0;
}
