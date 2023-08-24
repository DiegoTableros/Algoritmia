#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<int> fac(11);

int solucion(int a){
    int cont=0,aux;

    for (int i=1; i<=9; i++) {
        if(i==1){
            fac[1]=1;
        }else{
            fac[i]=i*(fac[i-1]);
        }
    }
    while(N>0){
        vector<int>::iterator low;
        low=lower_bound(fac.begin()+1, fac.end()-1, a);
        aux=low-fac.begin();
        N-=fac[aux];
        cont++;
    }

    return cont;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    cout << solucion(N);
    return 0;
}
