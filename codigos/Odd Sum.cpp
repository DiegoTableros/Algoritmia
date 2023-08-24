#include <bits/stdc++.h>
using namespace std;
int n,suma;
long long int res,impares,min_impar_pos,max_impar_neg;
long long int a[100002];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
  	cin >> n;
  	max_impar_neg=-1000000;
  	min_impar_pos=1000000;
	for(int i=1; i<=n; i++){
    	cin >> a[i];
      	if(a[i]>0) {
        	res+=a[i];
        }
      	if(a[i]<0 && abs(a[i])%2==1 && a[i]>max_impar_neg) {
        	max_impar_neg=a[i];
        }
      	if(a[i]>0 && a[i]%2==1 && a[i]<min_impar_pos) {
        	min_impar_pos=a[i];
        }
    }
  	if(res%2==0) {
    	res-=min(min_impar_pos,-max_impar_neg);
    }
  	cout << res;
  	return 0;
}
