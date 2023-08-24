#include <bits/stdc++.h>
using namespace std;
string a;
int k,cont;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
  	cin >> a >> k;
  	for(int i=a.size()-1; i>=0 && k>0; i--){
    	if(a[i]!='0'){
        	cont++;
        } else {
        	k--;
        }
    }
  	if(k==0) {
  		cout << cont;
    } else {
    	cout << a.size()-1;
    }
  	return 0;
}
