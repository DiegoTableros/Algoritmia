#include <bits/stdc++.h>
using namespace std;
double distancia[100002];
int n,k;
long double a,b,c,dist;

void leer() {
	cin >> n >> k;
    for(int i=1; i<=n; i++) {
    	cin >> a >> b >> c;
      	distancia[i]=(a*a)+(b*b)+(c*c);
    }
  	sort(distancia+1,distancia+n+1);
  	///Sacamos la de la posicion K
  	cout << setprecision(8) << fixed << sqrt(distancia[k]);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
	leer();
  	return 0;
}
