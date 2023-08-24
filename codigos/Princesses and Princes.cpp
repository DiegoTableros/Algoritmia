#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
vector <vi> lista;
bool visit[100002];
int n,t,k,a,aux;

void leer() {
    cin >> n;
    lista.push_back(vii);
    for(int i=1; i<=n; i++) {
        lista.push_back(0);
        cin >> k;
        for(int x=1; x<=k; x++) {
            cin >> a;
            lista[i].push_back(a);
        }
    }
    ///Ahora asignamos los casamientos
    for(int i=1; i<=n; i++) {
        ///Estamos en la princesa i
        ///Buscamos entre su lista quien es el menor desocupado (si tiene)
        for(int j=1; j<=lista[i].size(); j++) {
            if(visit[lista[i][j]]==0) {
                ///Este principe esta libre, lo ocupamos
                visit[lista[i][j]]=1;
                break;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    for(int b=1; b<=t; b++) {
        leer();
    }
    return 0;
}
