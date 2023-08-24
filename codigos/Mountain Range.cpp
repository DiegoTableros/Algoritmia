#include <bits/stdc++.h>

using namespace std;
struct punto {
    double x,y;
};
punto monta[252];
int a,b,n;

void leer() {
    cin >> n;
    punto act;
    act.x=0;
    act.y=0;
    for(int i=1; i<=n; i++) {
        cin >> a >> b;
        monta[i].x=act.x+a;
        monta[i].y=act.y+a;
        act=monta[i];
        act.x+=b;
        act.y-=b;
    }
}

void heidi() {
    stack <int> pila;
    ///Vamos de pico en pico
    for(int i=1; i<=n; i++) {
        ///Hacemos la recta con el de atras
        punto dos=monta[i],uno=monta[i-1];
        for(int k=i-1; k>0; k--) {
            ///Vemos si el pico x cumple la ecuacion
            double y_esperada=uno.y+((dos.y-uno.y)/(dos.x-uno.x))*(monta[k].x-uno.x);
            if(monta[k].y>=y_esperada) {
                uno=monta[k];
                pila.push(k);
            }
        }
        ///Vaciamos la pila
        cout << pila.size() << " ";
        while(!pila.empty()) {
            cout << pila.top() << " ";
            pila.pop();
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    leer();
    heidi();
    return 0;
}
