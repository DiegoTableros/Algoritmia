#include <bits/stdc++.h>
using namespace std;
int n,c,m,conjuntos;
struct punto {
	int x,y;
};
punto ciudad[752];
bool matriz[752][752];
int padre[752];
typedef pair<int,int> ii;
vector < pair<long long int, ii> > lista_aristas;

void inicializar() {
	for(int i=1; i<=n; i++) {
    	padre[i]=i;
    }
  	conjuntos=n;
}

int Find(int a){
  if(padre[a]==a){
    return a;
  }
  return padre[a]=Find(padre[a]);
}

bool mismo_conjunto(int a,int b){
  return Find(a)==Find(b);
}

void Union(int a, int b){
	int padreA=Find(a),padreB=Find(b);
  	if(!mismo_conjunto(a,b)){
    	padre[padreA]=padreB;
      	conjuntos--;
  	}
}

long long int distancia(int a, int b) {
	///Esta funcion devuelve la DISTANCIA AL CUADRADO entre la ciudad a y la b
  	long long int x2,y2;
  	x2=ciudad[b].x-ciudad[a].x;
  	x2*=x2;
  	y2=ciudad[b].y-ciudad[a].y;
  	y2*=y2;
  	return x2+y2;
}

void Kruskal(){
  	///lista_aristas:  <w,<u,v>>
	for(int i=0; i<lista_aristas.size() && conjuntos>1; i++){
    	int u=lista_aristas[i].second.first;
    	int v=lista_aristas[i].second.second;
      	if(!mismo_conjunto(u,v)){
        	Union(u,v);
          	cout << u << " " << v << "\n";
      	}
    }
}

void leer() {
  	int a,b;
	cin >> n;
  	for(int i=1; i<=n; i++) {
    	cin >> ciudad[i].x >> ciudad[i].y;
    }
  	inicializar();
  	cin >> m;
  	for(int i=1; i<=m; i++) {
    	cin >> a >> b;
      	Union(a,b);
      	matriz[a][b]=1;
      	matriz[b][a]=1;
    }
  	///Guardado de aristas
  	for(int i=1; i<=n; i++) {
  		for(int j=i+1; j<=n; j++) {
        	if(matriz[i][j]==0) {
            	///Metemos una posible arista entre la ciudad i y la j con su distancia
                lista_aristas.push_back(make_pair(distancia(i,j),make_pair(i,j)));
            }
        }
    }
  	///Ordenamos las aristas
  	sort(lista_aristas.begin(),lista_aristas.end());
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
  	cin >> c;
  	for(int z=1; z<=c; z++) {
    	leer();
      	if(conjuntos==1) {
        	cout << "No new highways need\n";
        } else {
            Kruskal();
        }
      	cout << "\n";
    }
  	return 0;
}
