#include <iostream>
#include <vector>
#include <string>

using namespace std;

//Prototipo
int*** crearMatriz(int);
int*** hacerCalculos(int***,int,int);
void mostrarProcedimiento(int***, int, int);



int main(){
	char resp;
	int opcion;
	do{
		cout<<endl<<"___Lab 2___"<<endl;
		cout<<"Ingrese numero de ejercicio: ";
		cin>>opcion;
		cout<<endl;
		switch(opcion){
			case 1:
				cout<<"---- Ejercicio 1 ----";
				
				break;
			case 2:{
				int grado=0, coeficiente=0, a=0, cont=0;      
				cout<<"---- Ejercicio 2 ----"<<endl;
			 	cout<<"Ingrese el grado del polinomio: ";
			  	cin>>grado;
				int*** matriz = crearMatriz(grado+1);
				for(int i=grado; i>=0; i--){
					cout<<"- Polinomio del grado x^"<<i<<": ";
					cin>>coeficiente;
					for(int j=0; j<grado+1; j++){
						matriz[j][0][cont]=coeficiente;
						if(i==grado){
							matriz[j][2][0]=coeficiente;
						}
					}
					cont++;
				}
				cout<<"Ingrese a: ";
				cin>>a;
				matriz = hacerCalculos(matriz,grado+1,a);
			        mostrarProcedimiento(matriz,a,grado+1);
			       }
				break;
			case 3:
				string cadena;
				cout<<"---- Ejercicio 3 ----";
				cout<<endl<<"Ingrese cadena: ";
				cin>>cadena;
				while(cadena.length()<8||cadena.length()>8){
					cout<<"Ingrese otra cadena: ";
					cin>>cadena;
				}	
				break;	

		}
		cout<<endl<<"Continuar[s]: ";
		cin>>resp;
	}while(resp=='s');



}

//Funciones ejercicio 3
string cadena(string fecha){

}


//Funciones ejercicio 2

int*** hacerCalculos(int*** matriz, int size, int a){
	int y=2, x1=0, x=0,  multiplicar = 0;
	for(int i=1; i<size; i++){
		for(int j=0; j<3; j++){
			for(int k=0; k<size; k++){
				matriz[i][j][k]= matriz[i-1][j][k];
			}
		}
		multiplicar = matriz[i][2][x]*a;
		x+=1;
		matriz[i][1][x]=multiplicar;
	        matriz[i][2][x]=matriz[i][0][x]+multiplicar;
	}
	return matriz;
}


void mostrarProcedimiento(int*** procedimiento, int a, int size){
	for(int i=0; i<size; i++){
		cout<<endl<<"________________________________"<<endl;
		for(int j=0; j<3; j++ ){
			for(int z=0; z<size; z++){
				cout<<" "<<procedimiento[i][j][z]<<" ";
			
			}

			if(j==0){
		 		cout<<"|"<<a<<endl;
			}else if(j==1){
				cout<<endl<<"----------------"<<endl;
			}
		}
	}
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
