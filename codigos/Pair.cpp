#include <bits/stdc++.h>
using namespace std;
long long int suma_amarillas,suma_verdes,suma_rojas,total;
long long int a,b,c,n,A,B,C,D,E,F;

void calcula_beta() {
	if(a==A || a==F) {
    	b=min(B,min(C,min(D,E)));
      	return;
    }
  	if(a==B || a==E) {
    	b=min(A,min(C,min(D,F)));
      	return;
    }
  	if(a==C || a==D) {
    	b=min(A,min(B,min(E,F)));
      	return;
    }
}

void calcula_gamma() {
  	long long int aux;
  	aux=A+E+C;
  	c=min(LONG_LONG_MAX,aux);
  	aux=A+E+D;
  	c=min(c,aux);
  	aux=A+B+D;
  	c=min(c,aux);
  	aux=A+B+C;
  	c=min(c,aux);
  	aux=F+E+C;
  	c=min(c,aux);
  	aux=F+E+D;
  	c=min(c,aux);
  	aux=F+B+D;
  	c=min(c,aux);
  	aux=F+B+C;
  	c=min(c,aux);
}

void leer() {
  	///Ponemos las formulas para solo multiplicar por alpha,beta y 1 respectivamente
  	suma_verdes=(4*(n-2))+(5*(n-2)*(n-2));
  	suma_amarillas=(4*(n-1))+(4*(n-2));
  	suma_rojas=4;
  	///Calculando el minimo de las seis, alpha
  	a=min(A,min(B,min(C,min(D,min(E,F)))));
  	///Calculando la pareja minima de alpha, beta
  	calcula_beta();
  	///Calculando la triada minima, gamma
  	calcula_gamma();
  	///Finalmente la suma total
  	suma_verdes*=a;
  	suma_amarillas*=(a+b);
  	suma_rojas*=c;
  	total=suma_verdes+suma_amarillas+suma_rojas;
  	cout << total;
}

int main() {
  	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	cin >> A >> B >> C >> D >> E >> F;
  	if(n==1) {
  		total=A+B+C+D+E+F;
		total-=max(A,max(B,max(C,max(D,max(E,F)))));
      	cout << total;
    } else {
    	leer();
    }
	return 0;
}
