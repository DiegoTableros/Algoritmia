#include <bits/stdc++.h>

using namespace std;
int n,xs,ys;
typedef pair<int,int> ii;
vector <ii> puntosX;
vector <ii> puntosY;

void leer() {
    int a,b;
    cin >> n >> xs >> ys;
    for(int i=1; i<=n; i++) {
        cin >> a >> b;
        puntosX.push_back(ii(a,b));
        puntosY.push_back(ii(b,a));
    }
    sort(puntosX.begin(),puntosX.end());
    sort(puntosY.begin(),puntosY.end());
}

void proceso() {
    int men_x=0,may_x=0,men_y=0,may_y=0;
    ///Primero nos recorremos en el eje X
    for(int i=0; i<puntosX.size(); i++) {
        if(puntosX[i].first<=xs-1) {
            men_x++;
        }else if(puntosX[i].first>=xs+1) {
            may_x++;
        }
    }
    for(int i=0; i<puntosY.size(); i++) {
        if(puntosY[i].first<=ys-1) {
            men_y++;
        }else if(puntosY[i].first>=ys+1) {
            may_y++;
        }
    }
    int maximo=max(men_x,max(may_x,max(men_y,may_y)));
    cout << maximo << "\n";
    if(maximo==men_x) {
        cout << xs-1 << " " << ys;
    } else if(maximo==may_x) {
        cout << xs+1 << " " << ys;
    } else if(maximo==men_y) {
        cout << xs << " " << ys-1;
    } else {
        cout << xs << " " << ys+1;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    leer();
    proceso();
    return 0;
}
