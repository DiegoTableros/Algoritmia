#include <bits/stdc++.h>
using namespace std;
int t,n;
typedef pair<long long int,int> ii;
int h[200002];
int w[200002];
vector <ii> area;
map <int,int> mapa;

void leer() {
    for(int i=1; i<=n; i++) {
        cin >> h[i] >> w[i];
        area.push_back(make_pair(h[i]*w[i],i));
    }
    sort(area.begin(),area.end());
}

void simu() {
    for(int i=n-1; i>=0; i--) {
        ///Estamos en i
        int act=area[i].second;
        bool bandera=0;
        for(int j=0; j<i && bandera==0; j++) {
            int aux=area[j].second;
            ///Condiciones de cupo
                if(h[aux]<h[act] && w[aux]<w[act]) {
                    mapa.insert(make_pair(act,aux));
                    bandera=1;
                } else if(w[aux]<h[act] && h[aux]<w[act]) {
                    mapa.insert(make_pair(act,aux));
                    bandera=1;
                }else if(h[aux]<w[act] && w[aux]<h[act]) {
                    mapa.insert(make_pair(act,aux));
                    bandera=1;
                } else if(w[aux]<w[act] && h[aux]<h[act]) {
                    mapa.insert(make_pair(act,aux));
                    bandera=1;
                }
        }
        if(bandera==0) {
            mapa.insert(make_pair(act,-1));
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        leer();
        simu();
        while(!mapa.empty()){
            cout << mapa.begin()->second << " ";
            mapa.erase(mapa.begin());
        }
        area.clear();
        cout << "\n";
    }
    return 0;
}
