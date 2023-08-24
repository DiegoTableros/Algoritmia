#include <bits/stdc++.h>
using namespace std;

///Numero de particulas.
#define n 2
///Numero de iteraciones para resolver.
#define it 1000
///Tamaño de paso.
#define h 0.001
///Direcciones.
#define X 3
#define Y 4
#define MUT 1
#define WT 2
///Constantes de las celulas.
double rad_cell=20.0;
double dist_limite=pow(40*rad_cell,2);
double dist_opti=40.0;
double masa=1.0;
double c_p=10000.0;
double eta=1.0;
///Estructura para guardar las respuestas.
struct cell {
	double r_x,r_y;
	double v_x,v_y;
	double a_x,a_y;
  	short tipo;
};
///La matriz SOL funciona con el formato "sol[celula][tiempo]". En cada casilla tiene los datos de pos, vel y acel con el formato del struct punto.
cell sol[202][it+2];
///Este arreglo es de condiciones iniciales, debemos llenarlo con la generacion de celulas random.
cell cond_ini[202];

double semilla(short tipo) {
	/*Esta función genera numeros random para determinado tipo de celula
  	if(tipo==MUT) {
    	return (1+rand()%(50-1));
    }
    return (50+rand()%(100-50));
  	*/
  	double sem=(1+rand()%(10-1));
  	sem/=10;
  	cout << sem << "\n";
	return sem;
}

bool buscar_repetidos(int n1, int n2, int tipo, int tope) {
  	if(tipo==MUT) {
      	for(int i=1; i<tope; i++) {
          	if(n1==cond_ini[i].r_x && n2==cond_ini[i].r_y) {
              	return true;
            }
        }
    } else {
      	for(int i=1; i<tope; i++) {
          	if(n1==cond_ini[i].r_x && n2==cond_ini[i].r_y) {
              	return true;
            }
        }
    }
	return false;
}

void llenar(){
  	int num1,num2;
    for (int i=1; i<=n; i++){
        num1 = semilla(MUT);
      	num2 = semilla(MUT);
        while(buscar_repetidos(num1,num2,MUT,i)){
            num1 = semilla(MUT);
          	num2 = semilla(MUT);
        }
      	cond_ini[i].r_x=num1;
      	cond_ini[i].r_y=num2;
    }
}

double fuerza(int K, int T, short dir) {
	///Esta funcion devuelve la sumatoria de fuerzas de la celula K en el tiempo T para la direccion X o Y.
  	double sumatoria=0;
  	///Vamos a recorrer todas las celulas en "sol[i][T]"
  	for(int i=1; i<=n && dir==X; i++){
    	if(K!=i) {
        	///Calculamos la distancia al cuadrado de la celula K a la i
      		double distancia = ((sol[i][T].r_x-sol[K][T].r_x)*(sol[i][T].r_x-sol[K][T].r_x)) + ((sol[i][T].r_y-sol[K][T].r_y)*(sol[i][T].r_y-sol[K][T].r_y));
          	///Si ésta es menor o igual que el cuadrado de la distancia limite
            if (distancia <= dist_limite){
            	///Entra a la sumatoria
              	distancia=sqrt(distancia);
              	double aux=(dist_opti*dist_opti)-(dist_opti*distancia);
              	aux/=(distancia*distancia*distancia);
              	aux*=c_p;
              	double exponente=distancia/dist_opti;
              	aux*=exp(exponente);
              	aux/=distancia;
              	aux*=(sol[i][T].r_x-sol[K][T].r_x);
              	sumatoria+=aux;
            }
        }
    }
  	for(int i=1; i<=n && dir==Y; i++){
    	if(K!=i) {
        	///Calculamos la distancia al cuadrado de la celula K a la i
      		double distancia = ((sol[i][T].r_x-sol[K][T].r_x)*(sol[i][T].r_x-sol[K][T].r_x)) + ((sol[i][T].r_y-sol[K][T].r_y)*(sol[i][T].r_y-sol[K][T].r_y));
          	///Si ésta es menor o igual que el cuadrado de la distancia limite
            if (distancia <= dist_limite){
            	///Entra a la sumatoria
              	distancia=sqrt(distancia);
              	double aux=(dist_opti*dist_opti)-(dist_opti*distancia);
              	aux/=(distancia*distancia*distancia);
              	aux*=c_p;
              	double exponente=distancia/dist_opti;
              	aux*=exp(exponente);
              	aux/=distancia;
              	aux*=(sol[i][T].r_y-sol[K][T].r_y);
              	sumatoria+=aux;
            }
        }
    }
    ///Restamos la viscosidad
    if(dir==X) {
        sumatoria-=eta*sol[K][T].v_x;
    } else {
        sumatoria-=eta*sol[K][T].v_y;
    }
    return sumatoria;
}

void leap_frog() {
	///Preparamos la posicion y velocidad inicial de cada celula
	for(int i=1; i<=n; i++) {
        sol[i][0].v_x=cond_ini[i].v_x+(h*0.5*cond_ini[i].a_x);
      	sol[i][0].v_y=cond_ini[i].v_y+(h*0.5*cond_ini[i].a_y);
        sol[i][0].r_x=cond_ini[i].r_x;
      	sol[i][0].r_y=cond_ini[i].r_y;
        sol[i][1].r_x=sol[i][0].r_x+h*sol[i][0].v_x;
      	sol[i][1].r_y=sol[i][0].r_y+h*sol[i][0].v_y;
	}
	///Iteramos las soluciones
	for(int k=1; k<=it; k++) {
        ///Para cada K debemos crear la solucion para cada celula
        for(int i=1; i<=n; i++) {
            ///Primero calculamos la aceleracion como: acel_act = fuerza_act / masa
            sol[i][k].a_x=fuerza(i,k-1,X)/masa;
          	sol[i][k].a_y=fuerza(i,k-1,Y)/masa;
            ///Ahora calculamos la velocidad como: vel_act = vel_ant + h * acel_act
            sol[i][k].v_x=sol[i][k-1].v_x+h*sol[i][k].a_x;
          	sol[i][k].v_y=sol[i][k-1].v_y+h*sol[i][k].a_y;
            ///Por ultimo calculamos la siguiente posicion como: pos_sig = pos_act + h * vel_act
            sol[i][k+1].r_x=sol[i][k].r_x+h*sol[i][k].v_x;
          	sol[i][k+1].r_y=sol[i][k].r_y+h*sol[i][k].v_y;
        }
	}
}

void imprimir() {
    ///Imprimimos TODAS las soluciones
    for(int k=0; k<=it; k++) {
        cout << "Tiempo " << k << "\n";
        for(int i=1; i<=n; i++) {
            cout << "(" << sol[i][k].r_x << "," << sol[i][k].r_y << ") ";
        }
        cout << "\n\n";
    }
}


int main() {
  	ios_base::sync_with_stdio(0); cin.tie(0);
  	//llenar();
    cond_ini[1].r_x=-10;
    cond_ini[1].r_y=0;
    cond_ini[2].r_x=10;
    cond_ini[2].r_y=0;
    leap_frog();
    imprimir();
	return 0;
}
