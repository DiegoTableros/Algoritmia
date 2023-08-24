#include <iostream>

using namespace std;
int n1,n2,k1,k2;
bool visit[102][102][102][2];
long long int memo[102][102][102][2];
#define MOD 100000000

long long int dp(int x,int y,int z,int f) {
    if(z>k1 && f==0) {
        return 0;
    }
    if(z>k2 && f==1) {
        return 0;
    }
    if(x<0 || y<0) {
        return 0;
    }
    if(x==0 && y==0) {
        return 1;
    }
    if(visit[x][y][z][f]) {
        return memo[x][y][z][f];
    }
    visit[x][y][z][f]=1;
    long long int res=0;
    if(f==0) {
        res+=dp(x-1,y,z+1,0);
        res%=MOD;
        res+=dp(x,y-1,1,1);
        res%=MOD;
    } else {
        res+=dp(x-1,y,1,0);
        res%=MOD;
        res+=dp(x,y-1,z+1,1);
        res%=MOD;
    }
    memo[x][y][z][f]=res;
    return res;
}

void leer() {
    cin >> n1 >> n2 >> k1 >> k2;
    cout << dp(n1,n2,0,0);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    leer();
    return 0;
}
