//Obtener la siguiente permutacion
//Obtener la permutacion previa
//¿Cuando devuelve false?
///Obtener las n! permutaciones: O(n!*n/2)
///n=11 aprox 2 seg, 1<=n<=10

#include <bits/stdc++.h>
using namespace std;
int arre[14]={0,1,2,3,4,5,6,7,8,9,10,11,12,0}; int n=12;

void leer() {
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> arre[i];
    }
}

void imprime() {
    ///Lineal: O(n)
    for(int i=1; i<=n; i++) {
        cout << arre[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    //leer();
    do{
        //imprime();
    }while(next_permutation(arre+1,arre+n+1)==true);
    return 0;
}
