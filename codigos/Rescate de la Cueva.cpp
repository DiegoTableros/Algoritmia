#include <bits/stdc++.h>

using namespace std;
int padres[1000002];
vector <int> lista[1000002];
int n,q,a,b,derrumbe,cueva;
bool visit[1000002];
queue <int> cola;

void leer() {
    cin >> n >> q;
    for(int i=1; i<n; i++) {
        cin >> a >> b;
        lista[a].push_back(b);
        lista[b].push_back(a);
    }
}

void propagacion() {
    cola.push(1);
    visit[1]=1;
    while(!cola.empty()) {
        int act=cola.front();
        cola.pop();
        for(int i=0; i<lista[act].size(); i++) {
            int aux=lista[act][i];
            if(visit[aux]==0) {
                visit[aux]=1;
                padres[aux]=act;
                cola.push(aux);
            }
        }
    }
}

void querys() {
    for(int i=1; i<=q; i++) {
        cin >> derrumbe >> cueva;
        int act=cueva;
        while(act!=1 && act!=derrumbe) {
            act=padres[act];
        }
        if(act==derrumbe) {
            cout << "0\n";
        } else {
            cout << "1\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    leer();
    propagacion();
    querys();
    return 0;
}
