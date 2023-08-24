#include <bits/stdc++.h>

using namespace std;
map <int,int> mapa;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ///Metemos 5 elementos
    for(int i=1; i<=5; i++) {
        mapa[i]=(i*10);
    }
    mapa[2]++;
    mapa[4]=15;

    for(map<int,int>::iterator ite=mapa.begin(); ite!=mapa.end(); ite++) {
        cout << ite->first << " " << ite->second << " " << "\n";
    }
    return 0;
}
