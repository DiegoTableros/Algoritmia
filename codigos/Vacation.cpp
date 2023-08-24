#include <bits/stdc++.h>
using namespace std;
int arre[100002][5];
int memo[100002][5];
int n;

/*int dp(int dia, int ultima) {
    if(dia>n) {
        return 0;
    }
    if(memo[dia][ultima]!=0) {
        return memo[dia][ultima];
    }
    int uno,dos,tres;
    uno=ultima==1?0:dp(dia+1,1)+arre[dia][1];
    dos=ultima==2?0:dp(dia+1,2)+arre[dia][2];
    tres=ultima==3?0:dp(dia+1,3)+arre[dia][3];
    memo[dia][ultima]=max(max(uno,dos),tres);
    return memo[dia][ultima];
}*/

int dp() {
    ///Los casos base ya están llenos de ceros
    ///Memo[dias_del_1_al_N][ultima_actividad]
    int a,b;
    for(int dia=n; dia>0; dia--) {
        for(int ultima=1; ultima<=3; ultima++) {
            if(ultima==1) {
                a=memo[dia+1][2]+arre[dia][1];
                b=memo[dia+1][3]+arre[dia][1];
            } else if(ultima==2) {
                a=memo[dia+1][1]+arre[dia][2];
                b=memo[dia+1][3]+arre[dia][2];
            } else {
                a=memo[dia+1][1]+arre[dia][3];
                b=memo[dia+1][2]+arre[dia][3];
            }
            memo[dia][ultima]=max(a,b);
        }
    }
    return max(memo[1][1],max(memo[1][2],memo[1][3]));
}


void leer() {
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> arre[i][1] >> arre[i][2] >> arre[i][3];
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    leer();
    //cout << dp(1,0);
    cout << dp();
    return 0;
}
