#include <bits/stdc++.h>
using namespace std;

#define TAMMAX 22
double matriz[TAMMAX][TAMMAX];
int n;

void leer() {
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> matriz[i][j];
        }
    }
}

double determinante() {
    ///
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    leer();

    return 0;
}
