#include <bits/stdc++.h>

using namespace std;
struct rama {
    int baja;
    int hijo;
};
typedef vector<rama> vr;
vector <vr> arbol;
int n,q,b,r,a,b;

void leer() {
    cin >> n >> q;
    arbol.resize(n+1);
    for(int i=1; i<=n; i++) {
        cin >> b >> r;
        arbol[i].resize(b+1);
        for(int j=1; j<=r; j++) {
            cin >> a >> b;
            int alto=max(a,b);
            int bajo=min(a,b);
            ///Este cable conecta a alto con bajo
            arbol[i][alto]=min(bajo,arbol[i][alto]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    return 0;
}
