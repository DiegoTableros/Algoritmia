#include <bits/stdc++.h>

using namespace std;
int k,N,M,X,Y;

void preguntas() {
    cin >> N >> M;
    for(int i=1; i<=k; i++) {
        ///Por cada casa que pregunten, imprimimos

        cin >> X >> Y;
        if(Y==M || X==N) {
            ///Esta en la division del eje X o del eje Y
            cout << "divisa\n";
        } else if(X>N && Y>M) {
            ///La casa esta en Northeastern Nlogonia
            cout << "NE\n";
        } else if(X>N && Y<M) {
            ///La casa esta en Southeastern Nlogonia
            cout << "SE\n";
        } else if(X<N && Y>M) {
            ///La casa esta en Northwestern Nlogonia
            cout << "NO\n";
        } else {
            ///La casa esta en Southwestern Nlogonia
            cout << "SO\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> k;
    while(k!=0) {
        preguntas();
        cin >> k;
    }
    return 0;
}
