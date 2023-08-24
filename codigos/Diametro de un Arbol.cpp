#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
vector <vi> lista;
int n,diametro;
bool visit[200002];

void leer() {
    int a,b;
    cin >> n;
    lista.resize(n+2);
    for(int i=1; i<n; i++) {
        cin >> a >> b;
        lista[a].push_back(b);
        lista[b].push_back(a);
    }
}

int arbol(int act) {
    int a=0,b=0,prof;
    for(int i=0; i<(int)lista[act].size(); i++) {
        if(visit[lista[act][i]]==0) {
            visit[lista[act][i]]=1;
            prof=arbol(lista[act][i])+1;
            if(prof>a) {
                b=a;
                a=prof;
            } else if(prof>b) {
                b=prof;
            }
        }
    }
    if(a+b>diametro) {
        diametro=a+b;
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    leer();
    visit[1]=1;
    arbol(1);
    cout << diametro;
    return 0;
}
