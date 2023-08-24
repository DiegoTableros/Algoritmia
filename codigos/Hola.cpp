#include <bits/stdc++.h>
using namespace std;

int P, L, S;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> P >> L >> S;
  if(((L/S)+1)==P) {
    cout << "CABEN";
  } else {
    cout << "RIESGO";
  }
  return 0;
}
