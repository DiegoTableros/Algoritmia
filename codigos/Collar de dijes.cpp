#include <bits/stdc++.h>

using namespace std;
short P[1002];
short V[1002];
map <pair<int,int>,int> memo;
map <pair<int,int>,int> :: iterator it;
short M,N;

void leer() {
    cin >> N >> M;
    for(int i=1; i<=N; i++) {
        cin >> P[i] >> V[i];
    }
    return;
}

int f(int p, int i) {

    if(p>M) {
        return -30000;
    }

    if(i>N) {
        return 0;
    }
    ///Visitado
    if((it=memo.find(make_pair(p,i)))!=memo.end()){
        return it->second;
    }

    int Tomar=f(p+P[i],i+1)+V[i];
    int NoTomar=f(p,i+1);
    memo[make_pair(p,i)]=max(Tomar,NoTomar);;
    return Tomar;
}

int main() {
    leer();
    cout << f(0,1);

    /*for(int i=0; i<=M; i++) {
        for(int j=0; j<=N; j++) {
            cout << memo[j][i] << " ";
        }
        cout << "\n";
    }*/
    return 0;
}
