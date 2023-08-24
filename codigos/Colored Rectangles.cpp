#include <bits/stdc++.h>
using namespace std;
int r,g,b;
priority_queue <int> red,green,blue;

void leer() {
    int aux;
    cin >> r >> g >> b;
    for(int i=1; i<=r; i++) {
        cin >> aux;
        red.push(aux);
    }
    for(int i=1; i<=g; i++) {
        cin >> aux;
        green.push(aux);
    }
    for(int i=1; i<=b; i++) {
        cin >> aux;
        blue.push(aux);
    }
}

void empareja() {
    int res=0;
    int rojo,verde,azul,peque;
    while((!red.empty() && !green.empty()) || (!red.empty() && !blue.empty()) || (!blue.empty() && !green.empty())) {
        if(red.empty()) {
            rojo=-1;
        } else {
            rojo=red.top();
        }
        if(blue.empty()) {
            azul=-1;
        } else {
            azul=blue.top();
        }
        if(green.empty()) {
            verde=-1;
        } else {
            verde=green.top();
        }
        peque=min(rojo,min(verde,azul));
        if(peque==verde && rojo!=-1 && azul!=-1) {
            res+=(rojo*azul);
            red.pop();
            blue.pop();
        }
        if(peque==rojo && azul!=-1 && verde!=-1) {
            res+=(azul*verde);
            blue.pop();
            green.pop();
        }
        if(peque==azul && rojo!=-1 && verde!=-1) {
            res+=(rojo*verde);
            red.pop();
            green.pop();
        }
    }
    cout << res;
    return;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    leer();
    empareja();
    return 0;
}
