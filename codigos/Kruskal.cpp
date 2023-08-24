/*#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
vector < pair<int,ii> > arista;
int n,m;
int padre[1002];
int prof[1002];

void inicializar() {
    for(int i=1; i<=n; i++) {
        padre[i]=i;
    }
}

int Find(int x) {
    if(padre[x]==x) {
        return x;
    }
    padre[x]=Find(padre[x]);
    return padre[x];
}

bool mismo_conjunto(int x, int y) {
    return Find(x)==Find(y);
}

void Union(int x, int y) {
    if(!mismo_conjunto(x,y)) {
        int rex=Find(x),rey=Find(y);
        if(prof[rex]>prof[rey]) {
            padre[rey]=rex;
        } else {
            padre[rex]=rey;
            if(prof[rex]==prof[rey]) {
                prof[rex]++;
            }
        }
    }
}

void leer() {
    int u,v,peso;
    cin >> n >> m;
    inicializar();
    for(int i=1; i<=m; i++) {
        cin >> u >> v >> peso;
        arista.push_back(make_pair(peso,make_pair(u,v)));
    }
    sort(arista.begin(),arista.end());
}

void kruskal() {
    ///Impresion auxiliar
    cout << "MST:\n";
    int costo_total=0;
    for(int i=0; i<arista.size(); i++) {
        pair <int,ii> a=arista[i];
        ///Checamos que no pertenezcan al mismo conjunto
        if(!mismo_conjunto(a.second.first,a.second.second)) {
            ///No crea ciclo, sumamos al costo
            costo_total+=a.first;
            ///Unimos
            Union(a.second.first,a.second.second);
            ///Impresion auxiliar
            cout << "(" << a.second.first << "," << a.second.second << ")\n";
        }
    }
    ///Impresion auxiliar
    cout << "Costo: " << costo_total << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    leer();
    kruskal();
    return 0;
}*/

/*	4 7
 * 	0 1 4
 * 	1 2 2
 *  0 2 4
 *  0 3 6
 *  0 4 6
 * 	2 3 8
 * 	3 4 9
 */
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
///Guardamos <Ponderacion,<U,V>>
vector < pair<int,ii> > lista_aristas;
int n,m;

/* Union Find Disjoint Sets
 * 		Union: Dados dos nodos une sus conjuntos en uno solo
 * 		Find: Encuentra el representante de un nodo
 * 		mismo_conjunto: Devuelve T/F si estan en un mismo conjunto (dos nodos)
 * 		iniciar_UFDS: Asigna inicialmente los padres de cada nodo
 */
int padre[1002];

void iniciar_UFDS(int N) {
  	///Inicialmente todos los conjuntos son disjuntos
	for(int i=1; i<=N; i++) {
    	padre[i]=i;
    }
}

int Find(int a) {
	if(padre[a]==a) {
    	///Llegamos al representante
      	return a;
    }
  	///Path compression
  	return padre[a]=Find(padre[a]);
}

bool mismo_conjunto(int a, int b) {
	return Find(a)==Find(b);
}

void Union(int a, int b) {
	int padreA=Find(a),padreB=Find(b);
  	if(!mismo_conjunto(a,b)) {
    	padre[padreA]=padreB;
    }
}

void leer() {
  	int u,v,w;
  	///Numero de nodos y aristas, respectivamente
	cin >> n >> m;
  	iniciar_UFDS(n);
  	for(int i=1; i<=m; i++) {
    	cin >> u >> v >> w;
      	///lista_aristas.push_back(make_pair(w,make_pair(u,v)));
      	lista_aristas.push_back(make_pair(w,make_pair(u,v)));
    }
  	///PASO 1: Ordenamos las aristas por su peso
  	sort(lista_aristas.begin(),lista_aristas.end());
}

void kruskal() {
	int peso_total=0;
  	for(int i=0; i<lista_aristas.size(); i++) {
      	///Recuerden que tenemos <w,<u,v>>
    	int u=lista_aristas[i].second.first;
      	int v=lista_aristas[i].second.second;
      	int w=lista_aristas[i].first;
      	///Preguntamos que no pertenezcan al mismo conjunto
      	if(!mismo_conjunto(u,v)) {
        	///Entonces esta arista no forma un ciclo, es parte del MST!
          	cout << "(" << u << "," << v << ")\n";
          	///Los unimos en un mismo conjunto
          	Union(u,v);
          	///Añadimos el peso al peso_total
          	peso_total+=w;
        }
    }
  	///Imprimimos el peso total
  	cout << "Peso del MST: " << peso_total;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    leer();
  	kruskal();
    return 0;
}
