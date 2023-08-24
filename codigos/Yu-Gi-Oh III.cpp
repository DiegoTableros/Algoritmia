#include <bits/stdc++.h>

using namespace std;

int n, dinero , k;

struct cartas{
    int sentimiento;
  int precio;///Hola hermoso
};

///Memorizado con MAP
typedef pair<int,int> pii;
map <pair<pii,int>,int> memo;
map <pair <pii,int>,int>::iterator it;

cartas yugi[10002];

void leer(){
  cin >> dinero >> n >> k;
  for(int i=1 ; i <= n  ; i++){
    	cin >> yugi[i].sentimiento >> yugi[i].precio;
  }
}

int DP(int carta, int dinero, int compradas){
  if(dinero < 0){
    return INT_MIN;
  }
  if(carta > n ){
    return 0;
  }
  if (compradas >= k ){
    return 0;
  }
  it=memo.find(make_pair(make_pair(carta,dinero),compradas));
  if(it!=memo.end()) {
  	return memo[make_pair(make_pair(carta,dinero),compradas)];
  }
  ///Que movimientos ponemos?
  //avanzar de tomar o no tomar, va, mientras pondre el memorizado
    //ok

  int retorno = max(DP(carta,dinero-yugi[carta].precio, compradas+1)+yugi[carta].sentimiento, DP(carta+1,dinero,compradas));
  ///Forma alternativa: memo[make_pair(make_pair(carta,dinero),compradas)]=retorno;
  	memo[make_pair(make_pair(carta,dinero),compradas)]=retorno;
    return retorno;
  //ya me hice bolas
  ///No hace falta comprar y avanzar? no verdad, ya va incluido no?
  ///Por que? que pasa, recuerda que (carta,dinero) es un pair tambien
  //jalo jalo
  ///Ya lo puse, jalas?
  ///Vamos a correrlo, te hablo por whats a ver que paso
  ///Parece que ya quedo, que pasa que pasa
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  leer();
  cout << DP(1, dinero, 0);
  return 0;
}
