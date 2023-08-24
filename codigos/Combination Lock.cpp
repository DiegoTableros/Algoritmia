#include <bits/stdc++.h>

using namespace std;
int ini,A,B,C;

int grados() {
    int suma_grados=0;
    int marca=ini,grados=0;
    ///Sumamos los 720° de las primeras dos vueltas
    suma_grados+=720;
    ///Estamos en ini y queremos ir a A en sentido horario
    ///Iremos restando y sumando 9°
    grados=0;
    while(marca!=A) {
        if(marca==0) {
            marca=39;
        } else {
            marca--;
        }
        grados+=9;
    }
    ///Sumamos los grados que recorrimos
    suma_grados+=grados;
    ///Sumamos 360° de la vuelta
    suma_grados+=360;
    ///Estamos en A y queremos ir a B en sentido antihorario
    ///Iremos sumando y sumando 9°
    grados=0;
    while(marca!=B){
        if(marca==39) {
            marca=0;
        } else {
            marca++;
        }
        grados+=9;
    }
    ///Sumamos los grados que recorrimos
    suma_grados+=grados;
    ///Finalmente estamos en B y debemos ir a C en sentido horario
    ///Iremos restando y sumando 9°
    grados=0;
    while(marca!=C) {
        if(marca==0) {
            marca=39;
        } else {
            marca--;
        }
        grados+=9;
    }
    ///Sumamos los grados que recorrimos
    suma_grados+=grados;
    ///Presionamos el botón, regresamos cuantos grados recorrimos
    return suma_grados;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> ini >> A >> B >> C;
    while(ini!=0 || A!=0 || B!=0 || C!=0) {
        ///Imprimimos los grados correspondientes a esta lectura
        cout << grados() << "\n";
        ///Leemos la proxima entrada
        cin >> ini >> A >> B >> C;
        ///La proxima vez preguntará si no son cero, cuando entre leerá la siguiente y así sucesivamente
    }
    return 0;
}
