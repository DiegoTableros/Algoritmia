#include <bits/stdc++.h>
using namespace std;
char sopa[42][42];
int filas,columnas,n,t;
int memo[42][42];
bool especial[42][42];
string palabra;
multiset <char> letras;
multiset <char> copia;
multiset <char>::iterator it;

void horizontales(int p) {
    ///Copiamos letras
    for(int f=1; f<=filas; f++) {
        int lim=(columnas-t)+1;
        for(int c=1; c<=lim; c++) {
            letras=copia;
            bool bandera=1;
            for(int i=0; i<t && bandera==1; i++) {
                it=letras.find(sopa[f][c+i]);
                if(it==letras.end()) {
                    bandera=0;
                } else {
                    letras.erase(it);
                }
            }
            if(bandera==1) {
                for(int i=0; i<t; i++) {
                    if(memo[f][c+i]!=p && memo[f][c+i]!=0) {
                        especial[f][c+i]=1;
                    } else {
                        memo[f][c+i]=p;
                    }
                }
            }
        }
    }
}

void verticales(int p) {
    ///Copiamos letras
    int lim=(filas-t)+1;
    for(int f=1; f<=lim; f++) {
        for(int c=1; c<=columnas; c++) {
            letras=copia;
            bool bandera=1;
            for(int i=0; i<t && bandera==1; i++) {
                it=letras.find(sopa[f+i][c]);
                if(it==letras.end()) {
                    bandera=0;
                } else {
                    letras.erase(it);
                }
            }
            if(bandera==1) {
                for(int i=0; i<t; i++) {
                    if(memo[f+i][c]!=p && memo[f+i][c]!=0) {
                        especial[f+i][c]=1;
                    } else {
                        memo[f+i][c]=p;
                    }
                }
            }
        }
    }
}

void diagonal_derecha(int p) {
    ///Copiamos letras
    int limf=(filas-t)+1;
    for(int f=1; f<=limf; f++) {
        int limc=(columnas-t)+1;
        for(int c=1; c<=limc; c++) {
            letras=copia;
            bool bandera=1;
            for(int i=0; i<t && bandera==1; i++) {
                it=letras.find(sopa[f+i][c+i]);
                if(it==letras.end()) {
                    bandera=0;
                } else {
                    letras.erase(it);
                }
            }
            if(bandera==1) {
                for(int i=0; i<t; i++) {
                    if(memo[f+i][c+i]!=p && memo[f+i][c+i]!=0) {
                        especial[f+i][c+i]=1;
                    } else {
                        memo[f+i][c+i]=p;
                    }
                }
            }
        }
    }
}

void diagonal_izquierda(int p) {
    ///Copiamos letras
    int limf=(filas-t)+1;
    for(int f=1; f<=limf; f++) {
        for(int c=columnas; c>=t; c--) {
            letras=copia;
            bool bandera=1;
            for(int i=0; i<t && bandera==1; i++) {
                it=letras.find(sopa[f+i][c-i]);
                if(it==letras.end()) {
                    bandera=0;
                } else {
                    letras.erase(it);
                }
            }
            if(bandera==1) {
                for(int i=0; i<t; i++) {
                    if(memo[f+i][c-i]!=p && memo[f+i][c-i]!=0) {
                        especial[f+i][c-i]=1;
                    } else {
                        memo[f+i][c-i]=p;
                    }
                }
            }
        }
    }
}

void llena(int p) {
    ///Esta función se encarga de rellenar donde haya anagramas
    horizontales(p);
    verticales(p);
    diagonal_derecha(p);
    diagonal_izquierda(p);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> filas >> columnas;
    for(int i=1; i<=filas; i++) {
        for(int j=1; j<=columnas; j++) {
            cin >> sopa[i][j];
        }
    }
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> palabra;
        t=palabra.size();
        for(int j=0; j<t; j++) {
            copia.insert(palabra[j]);
        }
        llena(i);
        copia.clear();
    }
    /*for(int i=1; i<=filas; i++) {
        for(int j=1; j<=columnas; j++) {
            cout << memo[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    for(int i=1; i<=filas; i++) {
        for(int j=1; j<=columnas; j++) {
            cout << especial[i][j] << " ";
        }
        cout << "\n";
    }*/
    int res=0;
    for(int i=1; i<=filas; i++) {
        for(int j=1; j<=columnas; j++) {
            if(especial[i][j]) res++;
        }
    }
    cout << res << "\n";
    return 0;
}
