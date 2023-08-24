//Algoritmo de ordenamiento QuickSort
#include<iostream>
#include<conio.h>

using namespace std;

void intercambio(float &x, float &y){
	float aux;
	aux=x;
	x=y;
	y=aux;
}

void quickSort(float a[], int primero, int ultimo){//Defino los parámetros a heredar de mi función
	int i,j,central;//Defino variables
	float pivote;//Defino mi pivote

	central=(primero+ultimo) / 2;//Defino la posicion central
	pivote= a[central];//Defino la posicion del pivote
	i=primero;//indico la posicion del 1er elemento
	j=ultimo;//indico la posicion del ultimo elemento

	do{//El algoritmo será recursivo...
		while(a[i]<pivote) i++;//Mientras los elementos de la izquierda sean menores al pivote, el programa avanza hacia la derecha
		while(a[j]>pivote) j--;//Mientras los elementos de la derecha sean mayores al pivote, el programa avanza hacia la izq
		if(i<=j){//Mantenemos la condición de que mientras i<=j, ejecute un intercambio
			intercambio(a[i],a[j]);//Invocamos la funcion intercambio que se declaró al inicio
		}
		i++;

	}while(i<=j);//mientras el indice i <=j esto quiere decir que mientras no se crucen

	if(primero <j){
		quickSort(a, primero, j);//Ordenamos la sublista izq
	}
	if(i < ultimo){
		quickSort(a, i, ultimo);//Ordenamos la sublista der
	}
}

int main(){
	float arreglo[]={4,8,2,10,6,9,7,3,1};
	quickSort(arreglo,0,8);
	cout<<"Arreglo ordenado de forma ascendente";
	for(int i=0; i<8; i++){
		cout<<arreglo[i]<<"|"<<endl;
	}
	cout<<"Arreglo ordenado de forma descendente";
	for(int i=8; i>=0; i--){
		cout<<arreglo[i]<<"|"<<endl;
	}
	getch();
	return 0;
}
