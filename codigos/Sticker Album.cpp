#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,a,b;
    cin >> n >> a >> b;
    vector <double> E(n+1);
    if(a==0) {
        double invlm1=1/double(b);
        E[0]=0;
        E[1]=(b+1)*invlm1;
        for(int x=2; x<=n; x++) {
            if((x-b-1)>=0) {
                E[x]=E[x-1]+invlm1*(E[x-1]-E[x-b-1]);
            }
        }
    } else {
        double invl=1/double(b-a+1);
        E[0]=0;
        for(int x=1; x<=a; x++)
            E[x]=1;
        for(int x=a+1; x<=n; x++){
            if((x-b-1)>=0) {
                E[x]=E[x-1]+invl*(E[x-a]-E[x-b-1]);
            }
        }
    }
    cout << fixed << setprecision(5) << E[n] << "\n";
    return 0;
}
