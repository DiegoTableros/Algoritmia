#include <bits/stdc++.h>
using namespace std;
typedef set<int> si;
set <int>::iterator it;
vector <si> tree;
int padre[100002];
bool vivo[100002];
int q,tope=1;

void hijo(int act) {
  	tope++;
	tree[act].insert(tope);
  	padre[tope]=act;
  	vivo[tope]=1;
}

int busca_rey(int act) {
	if(vivo[act]==1) {
    	return act;
    }
  	///Si no, ve a tus hijos
  	it=tree[act].begin();
  	act=*it;
  	return busca_rey(act);
}

int muere(int muerto) {
	///Muere la persona "muerto"
  	///Vemos si tiene hijos
  	vivo[muerto]=0;
  	if(tree[muerto].size()==0) {
    	///Lo quitamos de la lista del padre
      	tree[padre[muerto]].erase(muerto);
    }
	return busca_rey(1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> q;
    int evento,x;
    tree.resize(100002);
  	vivo[1]=1;
    for(int i=1; i<=q; i++) {
        cin >> evento >> x;
        if(evento==1) {
            ///x tiene un hijo
            hijo(x);
        } else {
            ///busca heredero
            cout << muere(x) << "\n";
        }
    }
    return 0;
}
