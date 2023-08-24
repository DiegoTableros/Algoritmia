#include <bits/stdc++.h>
using namespace std;
int n;
int arre[1000002];
int aux,l,l2;
int dist[1000002];
set <int> num;

bool se_puede() {
	int cont=0;
  	for(int i=1; i<=n && dist[i]<=l2 && cont<2; i++) {
    	if(num.find(dist[i])!=num.end() && num.find(dist[i]+l2)!=num.end()) {
        	cont++;
        }
    	if(cont==2) {
        	return true;
        }
    }
  	return false;
}

int main() {
  	ios_base::sync_with_stdio(0); cin.tie(0);
  	cin >> n;
  	for(int i=1; i<=n; i++) {
    	cin >> arre[i];
      	l+=arre[i];
    }
  	l2=l/2;
  	for(int i=2; i<=n; i++) {
    	dist[i]=dist[i-1]+arre[i-1];
    }
  	for(int i=1; i<=n; i++) {
    	num.insert(dist[i]);
    }
  	if(se_puede()) {
    	cout << 'Y';
    } else {
    	cout << 'N';
    }
	return 0;
}
