#include <bits/stdc++.h>
using namespace std;

long long int mesas[100002];
long long int arre[100002];
int n,costI,costD;
int maxi=-1;
int onde=-1;
int sum_total=0;
int vasos;

int bizq() {
  	int aux;
  	int cost=0;
  	for(int j=onde; j>=1; j--){
      	aux=mesas[j]-vasos;
      	cost+=aux;
      	if(j==1){
        	mesas[j]-=aux;
      		mesas[n]+=aux;
        }else{
      		mesas[j]-=aux;
      		mesas[j-1]+=aux;
        }
    }
  	for(int j=n; j>onde; j--){
    	aux=mesas[j]-vasos;
      	cost+=aux;
      	mesas[j]-=aux;
      	mesas[j-1]+=aux;
    }
	return cost;
}

int bder() {
  	int cost=0;
  	int aux;
  	for(int j=onde; j<=n; j++){
      	aux=mesas[j]-vasos;
      	cost+=aux;
      	if(j==n){
        	mesas[j]-=aux;
      		mesas[1]+=aux;
        }else{
      		mesas[j]-=aux;
      		mesas[j+1]+=aux;
        }
    }
  	for(int j=1; j<onde; j++){
    	aux=mesas[j]-vasos;
      	cost+=aux;
      	mesas[j]-=aux;
      	mesas[j+1]+=aux;
    }
	return cost;
}

int main() {
  	ios_base::sync_with_stdio(0); cin.tie(0);
  	cin >> n;
  	for(int i=1;i<=n;i++){
    	cin >> arre[i];
      	sum_total+=arre[i];
      	if(arre[i]>maxi){
        	maxi=arre[i];
          	onde=i;
        }
    }
  	vasos=sum_total/n;
  	for(int i=1; i<=n; i++) {
    	mesas[i]=arre[i];
    }
  	costI=bizq();
  	for(int i=1; i<=n; i++) {
    	mesas[i]=arre[i];
    }
  	costD=bder();
  	if(costD<0) {
    	costD=1000000000;
    }
  	if(costI<0) {
    	costI=1000000000;
    }
  	if(costI<=costD) {
    	cout << costI;
    }else {
    	cout << costD;
    }
  	return 0;
}
