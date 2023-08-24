#include <bits/stdc++.h>
using namespace std;
int n;
string s1, s2;
set<string> ordena;
typedef pair<string,string> ss;
vector<ss> relacion;
vector<string> palabra;
vector<string>::iterator it1, it2;
vector<int> padre;
string cadena;

int FIND(int x) {
	///Encuentra el representante de palabra[x]
  	if(palabra[x]==palabra[padre[x]]) {
    	return x;
    }
  	padre[x]=FIND(padre[x]);
  	return padre[x];
}

void UNION(int a, int b) {
	///Unir la palabra palabra[a] con la palabra[b]
  	int x=FIND(a), y=FIND(b);
  	if(x!=y) {
    	///No están en el mismo conjunto, los unimos
      	///Debe quedar el menor lexicografico
      	if(palabra[x].size()<palabra[y].size()) {
        	padre[y]=x;
        } else if(palabra[x].size()==palabra[y].size()) {
        	if(palabra[x]<palabra[y]) {
            	padre[y]=x;
            } else {
            	padre[x]=y;
            }
        } else {
        	padre[x]=y;
        }
    }
}

void leer() {
	cin >> n;
  	for(int i=0; i<n; i++) {
		cin >> s1;
      	cin >> s2;
      	relacion.push_back(make_pair(s1, s2));
      	ordena.insert(s1);
      	ordena.insert(s2);
    }
  	int i=0;
  	while(!ordena.empty()) {
    	palabra.push_back(*ordena.begin());
      	padre.push_back(i);
      	i++;
    	ordena.erase(ordena.begin());
    }
  	///Hacemos el UNION FIND
  	for(i=0; i<relacion.size(); i++) {
    	int x,y;
      	it1=lower_bound(palabra.begin(), palabra.end(), relacion[i].first);
      	x=it1-palabra.begin();
      	it1=lower_bound(palabra.begin(), palabra.end(), relacion[i].second);
      	y=it1-palabra.begin();
      	UNION(x,y);
    }
  	///En este punto ya esta todo listo para buscar
  	bool band=0;
  	while(cin >> cadena) {
        if(cadena=="\n") {
            break;
        }
        if(band==1) {
            cout << " ";
        } else {
            band=1;
        }
    	int x;
      	it1=lower_bound(palabra.begin(), palabra.end(), cadena);
      	x=it1-palabra.begin();
      	if(binary_search(palabra.begin(),palabra.end(),cadena)==0){
        	///No la encontró, no tiene codificacion
          	cout << cadena;
        } else {
          	///Imprimimos la codificacion directa
          	cout << palabra[FIND(x)];
        }
    }
    cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  	leer();
  	return 0;
}
