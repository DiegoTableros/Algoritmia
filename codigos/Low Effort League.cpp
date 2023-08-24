#include <bits/stdc++.h>

using namespace std;
int equipos;
int skill;
int arre[50000];
long long int st[200000];

int left(int i){
	return (i<<1);
}

int right(int i){
	return (i<<1)+1;
}

int limite;
void leer(){
	cin >> equipos;
	limite = 1 << equipos;
	for(int i=0; i< limite ; i++){
		cin >> skill;
		arre[i]=skill;
	}
}
long long int res;
void build(int p, int L, int R){
	if(L==R){
		st[p]=arre[L];
		return ;
	}
	build(left(p), L, (L+R)/2);
	build(right(p),(L+R)/2+1, R);
	long long int aux = abs(st[left(p)]-st[right(p)]);
	if(L==0){
		if(st[left(p)]<=st[right(p)]){
			st[p]=st[left(p)];
			res+=aux*aux;


			return;
		}else{
			st[p]=st[left(p)];
			return;
		}
	}
	int maximo;
	int minimo;
	if(st[left(p)] >= st[right(p)]){
		maximo= st[left(p)];
		minimo=st[right(p)];
	}else{
		maximo=st[right(p)];
		minimo=st[left(p)];
	}
	int diferencia1= abs(arre[0]-maximo);
	int diferencia2= abs(maximo-minimo);
	if(st[left(p)] > arre[0] || st[right(p)] > arre[0]){
		if(diferencia1 < diferencia2){
			st[p]=maximo;
			return;
		}else{
			st[p] = minimo;
			res+= aux*aux;
			return;
		}
	}
	if(st[left(p)] <= st[right(p)]){
		st[p]=st[right(p)];
		return;
	}else{
		st[p]=st[left(p)];
	}

}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	leer();
	build(1,0,limite-1);
	cout << res<<"\n";
	return 0;
}
