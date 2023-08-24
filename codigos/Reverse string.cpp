#include <bits/stdc++.h>
using namespace std;
///Declaramos dos string
string cadena,salida;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	///Leemos la cadena
	cin >> cadena;
	reverse(cadena.begin(),cadena.end());
	cout << cadena;
	return 0;
}
