#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
vector <iii> slop;
long long int s, a, b, coins,aux,res,cont;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
  	cont=0;
	cin >> s;
  	for(int i=1;i<=s;i++){
    	cin >> a >> b;
      	slop.push_back(make_pairmake_pair(a,b));
    }
  	sort(slop.begin(), slop.end());
  	cin >> coins;
  	for(int i=1; i<=coins; i++) {
    	cin >> a >> b;
      	ii comp=make_pair(a,b);
      	aux=lower_bound(slop.begin(), slop.end(), comp);
      	res+=slop[aux].second;
    }
  	cout << res;
  	return 0;
}
