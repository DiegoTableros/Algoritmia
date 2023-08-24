#include <bits/stdc++.h>
using namespace std;

char a_Mayuscula(char letra) {
 	if('A'<=letra && letra<='Z') {
    	return letra;
 	}
	char mayuscula=letra-'a';
	mayuscula+='A';
	return mayuscula;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    char aux;
    cin >> aux;
    cout << a_Mayuscula(aux);
    return 0;
}
