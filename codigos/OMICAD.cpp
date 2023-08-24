#include <bits/stdc++.h>

using namespace std;

struct dato {
    int x1,x2,y1,y2;
};
dato edificio[50002];
int piso[50002];
int n;
vector <int> cont[50002];

bool comp(dato x, dato y) {
    return x.x1<y.x1;
}

void leer() {
    cin >> n;
    ///Leemos todos los edificios y de paso calculamos su area
    for(int i=1; i<=n; i++) {
        cin >> edificio[i].x1 >> edificio[i].y1 >> edificio[i].x2 >> edificio[i].y2;
    }
    ///Ordenamos los edificios con la esquina sup izquierda, priorizando x y luego y
    sort(edificio+1,edificio+n+1,comp);
    ///Guardamos la planta baja
    edificio[0].x1=-1;
    edificio[0].y1=-1;
    edificio[0].x2=70000;
    edificio[0].y2=70000;
}

bool contenido(dato A, dato B) {
    if(A.x1>=B.x1 && A.y1>=B.y1 && A.x2<=B.x2 && A.y2<=B.y2) {
        return true;
    }
    return false;
}

void pisos() {
    for(int i=1; i<=n; i++) {
        ///Estamos en el edificio i-esimo
        ///Vamos a empezar preguntando en el nivel cero haciendo el arbol
        int padre=0;
        int bandera=0,entramos=0;
        while(bandera==0) {
            ///Estamos en el nodo de nuestro presunto padre, exploramos sus hijos
            for(int j=0; j<cont[padre].size() && entramos==0; j++) {
                ///Vemos si estamos contenidos en este hijo
                if(contenido(edificio[i],edificio[cont[padre][j]])) {
                    ///Estamos contenidos aqui, nos movemos de padre
                    padre=cont[padre][j];
                    entramos=1;
                }
            }
            ///Si llegamos aqui es porque no estamos dentro de ningun hijo, aqui pertenecemos
            if(entramos==0) {
                ///No entramos en ninguno, nos ponemos como hijo
                cont[padre].push_back(i);
                ///Actualizamos nuestro piso, claro
                piso[i]=piso[padre]+1;
                ///Y frenamos el while
                bandera=1;
            } else {
                entramos=0;
            }
        }
    }
}

void impresion_ayuda() {
    cout << "Pisos de cada edificio\n";
    for(int i=1; i<=n; i++) {
        cout << piso[i] << " ";
    }
    cout << "\nLista de contención\n";
    for(int i=0; i<=n; i++) {
        cout << i << ": ";
        for(int j=0; j<cont[i].size(); j++) {
            cout << cont[i][j] << " ";
        }
        cout << "\n";
    }
}

long long int volumen() {
    long long int vol=0;
    for(int i=1; i<=n; i++) {
        vol+=((edificio[i].x2-edificio[i].x1)*(edificio[i].y2-edificio[i].y1))*piso[i];
    }
    return vol;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    leer();
    pisos();
    cout << volumen();
    //impresion_ayuda();
    return 0;
}
