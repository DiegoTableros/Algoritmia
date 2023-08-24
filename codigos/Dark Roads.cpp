#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
vector < pair<int,ii> > lista_aristas;
int nodos,aristas,total;
int p[200002];

void inicializar() {
	for(int i=1; i<=nodos; i++) {
    	p[i]=i;
    }
}

int Find(int x){
  if(p[x]==x){
    return x;
  }
  return p[x]=Find(p[x]);
}

bool same_set(int x, int y) {
	return Find(x)==Find(y);
}

void Union(int a,int b) {
  int p_a=Find(a), p_b=Find(b);
  if(!same_set(a,b)) {
    p[p_a]=p_b;
  }
}

void kruskal() {
	int w_t=0;
  	for(int i=0; i<lista_aristas.size(); i++) {
    	int u=lista_aristas[i].second.first;
      	int v=lista_aristas[i].second.second;
      	int w=lista_aristas[i].first;
      	if(!same_set(u,v)) {
        	Union(u,v);
        	w_t+=w;
        }
    }
  	cout << total-w_t << "\n";
}

void leer(){
  	int a,b,w;
    total=0;
  	for(int i=1;i<=aristas;i++){
    	cin>> a >> b >> w;
      	total+=w;
    	lista_aristas.push_back(make_pair(w,make_pair(a,b)));
    }
  	sort(lista_aristas.begin(),lista_aristas.end());
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> nodos >> aristas;
  	while(nodos!=0 && aristas!=0) {
    	leer();
      	inicializar();
      	kruskal();
      	lista_aristas.clear();
      	cin >> nodos >> aristas;
    }
  	return 0;
}
