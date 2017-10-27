#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main(){
	char resp;
	int opcion;
	do{
		cout<<"___Lab 2__"<<endl;
		cout<<"Ingrese numero de ejercicio: ";
		cin>>opcion;
		cout<<endl;
		switch(opcion){
			case 1:
				cout<<"---- Ejercicio 1 ----";
				
				break;
			case 2:{
				int grado=0, coeficiente=0, a;       
				cout<<"---- Ejercicio 2 ----"<<endl;
			 	cout<<"Ingrese el grado del polinomio: ";
			  	cin>>grado;
				for(int i=grado; i>=0; i--){
					cout<<"- Polinomio del grado x^"<<i<<": ";
					cin>>coeficiente;	
				}
				cout<<"Ingrese a: ";
				cin>>a;
			       }
				break;
			case 3:
				cout<<"---- Ejercicio 3 ----";

				break;	

		}
		cout<<"Continuar[s]: ";
		cin>>resp;
	}while(resp=='s');



}

int*** 

void imprimirMatriz(int*** matriz){
}


int*** crearMatriz(int size){
	int*** matriz = new int**[size];
	for(int i=0; i<size; i++){
		matriz[i] = new int*[3];
	}
	for(int i=0; i<size; i++){
		for(int j=0; j<3; j++){
			matriz[i][j] = new int [size];
		}
	}
	return matriz;
}
