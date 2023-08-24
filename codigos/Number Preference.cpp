#include <bits/stdc++.h>

using namespace std;
long long int n,s,uno,num,dos;
set <long long int> cubeta;
map <long long int,int> mapa;
map <long long int, int> :: iterator it;
set <long long int> :: iterator ite;

void leer() {
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> num;
        if(num==1) {
            uno++;
            cin >> s;
            for(int j=1; j<=s; j++) {
                cin >> num;
                mapa[num]++;
            }
        } else {
            dos++;
            cin >> s;
            for(int j=1; j<=s; j++) {
                cin >> num;
                cubeta.insert(num);
            }
        }
    }
    long long int cont=0;
    ///Parche
    if(uno==0) {
        cont=1e18-cubeta.size();
        cout << cont;
        return;
    }
    ///Quitamos los del set
    for(ite=cubeta.begin(); ite!=cubeta.end(); ite++) {
        mapa.erase(*ite);
    }
    ///Finalmente recorremos la cubeta buscando los que tengan el numero uno
    for(it=mapa.begin(); it!=mapa.end(); it++) {
        if(it->second==uno) {
            cont++;
        }
    }
    cout << cont;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    leer();
    return 0;
}
