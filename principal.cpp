#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;

//Prototipo
int*** crearMatriz(int);
int*** hacerCalculos(int***,int,int);
void mostrarProcedimiento(int***, int, int);
string cadena(string);
bool cadenaValida(string);
bool anioBi(int);
bool evaluarFecha(int,int,int);

int main(){
	char resp;
	int opcion;
	do{
		cout<<endl<<"___Lab 2___"<<endl;
		cout<<"Ingrese numero de ejercicio: ";
		cin>>opcion;
		cout<<endl;
		switch(opcion){
			case 1:{
				cout<<"---- Ejercicio 1 ----";
				vector<int>numeros;	
						
			       }
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
			case 3:{
				string fecha;
				cout<<"---- Ejercicio 3 ----";
				cout<<endl<<"Ingrese cadena: ";
				cin>>fecha;
				while(fecha.length()<8||fecha.length()>8||cadenaValida(fecha)==false){
					cout<<"Ingrese otra cadena: ";
					cin>>fecha;
				}	
			       	cout<<"Resultado: "<<cadena(fecha);
			       }	
				break;	

		}
		cout<<endl<<"Continuar[s]: ";
		cin>>resp;
	}while(resp=='s');


	return 0;
}

//Funciones ejercicio 3

string cadena(string fecha){
	int resultado;
	int meses[] = {0,3,3,6,1,4,6,2,5,0,3,5};	
  	int dias[] = {1,2,3,4,5,6,0};	
	string dia="", anio="", mes="", anioCompleto;
	int d, a, m, aniocompleto, numero=0;
	anio+=fecha.at(2);	
	anio+=fecha.at(3);	
	anioCompleto+=fecha.at(0);
	anioCompleto+=fecha.at(1);
	anioCompleto+=fecha.at(2);
	anioCompleto+=fecha.at(3);
	mes+=fecha.at(4);	
	mes+=fecha.at(5);	
	dia+=fecha.at(6);
	dia+=fecha.at(7);
	aniocompleto = atoi(anioCompleto.c_str());
	d = atoi(dia.c_str());
 	a = atoi(anio.c_str());
	m = atoi(mes.c_str());
	if(evaluarFecha(a,m,d)){	
		if(aniocompleto>=1800&&aniocompleto<=1899){
			numero = 2;
		}else if(aniocompleto>=2000&&aniocompleto<=2099){
			numero = 6;	
		}
		resultado = (d+meses[m-1]+a+(a/4)+numero)%7;
		switch(resultado){
			case 1:{
			       	return "Lunes";
			       }
			case 2:{
				return "Martes";
			       }
			case 3:{
			       	return "Miercoles";
			       }
			case 4:{
			       	return "Jueves";
			       }
			case 5:{
			       	return "Viernes";
			       }
			case 6:{
			       	return "Sabado";
			       }
			case 0:{
			       	return "Domingo";
			       }
		}	
		return fecha;
	}else{
		fecha = "Cadena incorrecta";
		return fecha;
	}
	
}

bool evaluarFecha(int anio, int mes, int dia){
	if(anioBi(anio)){
		if(mes==2&&dia>29){
			return false;
		}
	}
	if(anioBi(anio)==false){
		if(mes==2&&dia>28){
			return false;
		}
	}
	if(mes>12){
		return false;
	}
	if(mes>7){
		if(mes%2==0&&dia>31){
			return false;
		}
		if(mes%2!=0&&dia>30){
			return false;
		}
	}
	if(mes<7){
		if(mes%2==0&&dia>30){
			return false;
		}
		if(mes%2!=0&&dia>31){
			return false;
		}
	}
	return true;	
}


bool cadenaValida(string cadena){
	for(int i=0; i<cadena.length(); i++){
		if(cadena[i]<48||cadena[i]>57){
			return false;
		}
	}
	return true;
}

bool anioBi(int anio){
	if(anio%4==0){
		return true;	
	}else{
		return false;
	}
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
