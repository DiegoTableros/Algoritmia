#include <bits/stdc++.h>

using namespace std;
int t,n;
int arre[1002];

void leer() {
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> arre[i];
    }
    int alice=1,bob=n;
    int prev=0;
    bool turno_alice=1;
    int dulces=n;
    int total_alice=0,total_bob=0,mov;
    int movimientos=0;
    while(dulces>0) {
        mov=0;
        movimientos++;
        if(turno_alice) {
            while(mov<=prev && alice<=bob) {
                mov+=arre[alice];
                alice++;
                dulces--;
            }
            total_alice+=mov;
            prev=mov;
            turno_alice=0;
        }else{
            while(mov<=prev && alice<=bob) {
                mov+=arre[bob];
                bob--;
                dulces--;
            }
            total_bob+=mov;
            prev=mov;
            turno_alice=1;
        }
    }
    cout << movimientos << " " << total_alice << " " << total_bob << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    for(int z=1; z<=t; z++) {
        leer();
    }
    return 0;
}
