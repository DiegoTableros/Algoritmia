#include <bits/stdc++.h>

using namespace std;
int comando;
struct punto {
    int x,y,z;
};

priority_queue <punto> monti;
/*VENTAJAS
    -Rapida
    -Eficiente
    -Funciones sencillas
  DESVENTAJAS
    -Es solo de mayores
        (se arregla metiendo negativos)
    -Solo funciona con determinados tipos
        (primitivos y pair primitivo)
*/
int main() {
    ios_base::sync_with_stdio(0);
    cout << "MONTICULO DE MAYORES\n";
    while(1) {
        cout << "1 para meter un numero\n2 para sacar el mayor\n3 para tamaño\n ";
        cin >> comando;
        if(comando==1) {
            cout << "Meter el numero: ";
            cin >> comando;
            monti.push(comando);
            cout << "Se introdujo " << comando << " al monticulo";
        } else if(comando==2) {
            cout << "El mayor actual era " << monti.top();
            monti.pop();
        } else {
            cout << "El tamaño del monticulo es " << monti.size();
        }
        cout << "\n\n";
    }
    return 0;
}
