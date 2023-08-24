#include <bits/stdc++.h>

using namespace std;
int n,campos,verdes,azules;
int tope_a, tope_v;
int monti_a[100002];
int monti_v[100002];

void meter_a(int x) {
    tope_a++;
    int act=tope_a;
    int padre=act/2;
    while(monti_a[padre]<x) {
        monti_a[act]=monti_a[padre];
        act=padre;
        padre=act/2;
    }
    monti_a[act]=x;
}

int sacar_a() {
    int regresa=monti_a[1];
    int x=monti_a[tope_a];
    tope_a--;
    int act=1;
    int hijo=2;
    while(hijo<=tope_a) {
        if(monti_a[hijo]<monti_a[hijo+1] && hijo+1<=tope_a) {
            hijo++;
        }
        if(x>=monti_a[hijo]) {
            ///Ya estamos en el lugar correcto
            break;
        } else {
            ///Necesitamos cambiar
            monti_a[act]=monti_a[hijo];
            act=hijo;
            hijo=act*2;
        }
    }
    monti_a[act]=x;
    return regresa;
}

void meter_v(int x) {
    tope_v++;
    int act=tope_v;
    int padre=act/2;
    while(monti_v[padre]<x) {
        monti_v[act]=monti_v[padre];
        act=padre;
        padre=act/2;
    }
    monti_v[act]=x;
}

int sacar_v() {
    int regresa=monti_v[1];
    int x=monti_v[tope_v];
    tope_v--;
    int act=1;
    int hijo=2;
    while(hijo<=tope_v) {
        if(monti_v[hijo]<monti_v[hijo+1] && hijo+1<=tope_v) {
            hijo++;
        }
        if(x>=monti_v[hijo]) {
            ///Ya estamos en el lugar correcto
            break;
        } else {
            ///Necesitamos cambiar
            monti_v[act]=monti_v[hijo];
            act=hijo;
            hijo=act*2;
        }
    }
    monti_v[act]=x;
    return regresa;
}

void simu() {
    ///Aqui debemos hacer los enfrentamientos
    queue <int> sobre_a;
    queue <int> sobre_v;
    ///Mientras aun esten vivos
    while(azules>0 && verdes>0) {
        ///Hay al menos un soldado de cada facción, calculamos cuantos campos
        campos=min(campos,min(azules,verdes));
        ///Por cada campo sacamos dos a pelear
        for(int x=1; x<=campos; x++) {
            ///Sacamos a los dos mas fuertes
            int sold_a=sacar_a();
            int sold_v=sacar_v();
            verdes--;
            azules--;
            ///Procedemos por casos
            if(sold_a>sold_v) {
                sold_a-=sold_v;
                sobre_a.push(sold_a);
            } else if(sold_v>sold_a) {
                sold_v-=sold_a;
                sobre_v.push(sold_v);
            }
        }
        ///Ahora checamos los sobrevivientes
        azules+=sobre_a.size();
        while(!sobre_a.empty()) {
            meter_a(sobre_a.front());
            sobre_a.pop();
        }
        verdes+=sobre_v.size();
        while(!sobre_v.empty()) {
            meter_v(sobre_v.front());
            sobre_v.pop();
        }
    }
    ///Ahora checamos quien gano
    if(verdes==0 && azules>0) {
        ///Ganan los azules
        cout << "blue wins\n";
        while(tope_a>0) {
            cout << sacar_a() << "\n";
        }
    } else if(azules==0 && verdes>0) {
        ///Ganan los verdes
        cout << "green wins\n";
        while(tope_v>0) {
            cout << sacar_v() << "\n";
        }
    } else {
        cout << "green and blue died\n";
    }
}

void leer() {
    monti_a[0]=INT_MAX;
    monti_v[0]=INT_MAX;
    cin >> n;
    for(int x=1; x<=n; x++) {
        cin >> campos >> verdes >> azules;
        int aux;
        ///Metemos todos los elementos a sus monticulos
        for(int i=1; i<=verdes; i++) {
            cin >> aux;
            meter_v(aux);
        }
        for(int i=1; i<=azules; i++) {
            cin >> aux;
            meter_a(aux);
        }
        ///Ahora debemos hacer la simulacion
        simu();
        if(x!=n) {
            cout << "\n";
        }
        ///"Borramos" los monticulos
        tope_a=0;
        tope_v=0;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    leer();
    return 0;
}
