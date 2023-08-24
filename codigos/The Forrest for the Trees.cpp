#include <bits/stdc++.h>

using namespace std;
int t,aristas,nodos,arboles,acorns;
bool letra[32];
string linea;

void leer() {
    memset(letra,0,sizeof(letra));
    aristas=0;
    nodos=0;
    arboles=0;
    acorns=0;
    getline(cin,linea);
    while(linea[0]!='*') {
        ///Rescatamos los nodos
        char A=linea[1], B=linea[3];
        int a=A-'A', b=B-'A';
        letra[a]=1;
        letra[b]=1;
        aristas++;
        getline(cin, linea);
    }
    ///Leemos la lista de nodos
    getline(cin,linea);
    for(int i=0; i<linea.size(); i+=2){
        nodos++;
        char A=linea[i];
        int a=A-'A';
        if(letra[a]==0) {
            acorns++;
        }
    }
    cout << "There are " << (nodos-aristas-acorns) << " tree(s) and " << acorns << " acorn(s).\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    getline(cin,linea);
    for(int x=1; x<=t; x++) {
        leer();
    }
    return 0;
}
