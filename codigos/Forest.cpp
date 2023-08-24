#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
vector <vi> persona;
int casos,P,T,i,j;

int main() {
  	ios_base::sync_with_stdio(0); cin.tie(0);
  	cin >> casos;
  	string aux, temp;
  	vector <string> tokens;
  	int k;
  	while(casos--) {
    	cin >> P >> T;
      	getline(cin,aux);
      	stringstream ss(aux);
      	while(getline(ss, temp, ' ')) {
          tokens.push_back(temp);
        }
      	i=stoi(tokens[0],nullptr,10);
      	j=stoi(tokens[1],nullptr,10);
      	tokens.clear();
      	cout << i << " " << j;
   	}
  	return 0;
}
