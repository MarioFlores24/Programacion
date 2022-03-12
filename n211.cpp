#include <iostream>
#include <iomanip>
using namespace std;


struct Estudiante {
	int *codigo;
	string *nom, *apell;
	int **pm_notas;
};

int main () {
	
	int cantidad_estudiantes=0, cantidad_notas=0, contador=0;
	float promedio=0,sumatoria_notas=0;
	
	Estudiante estudiante;
	
	
	cout<<"Ingrese cantidad de estudiantes: ";  
	cin>>cantidad_estudiantes; 
	cout<<"Ingrese cantidad de notas: ";
	cin>>cantidad_notas;
	
		estudiante.pm_notas= new int *[cantidad_estudiantes]; 
		estudiante.codigo = new int [cantidad_estudiantes];
		estudiante.nom = new string [cantidad_estudiantes];
		estudiante.apell = new string [cantidad_estudiantes];
		
		for(int i=0; i<cantidad_estudiantes;i++){
			estudiante.pm_notas[i] = new int [cantidad_notas];
		}
	
	system("cls");
	cout<<"---------------------------------------------------------INGRESO DE DATOS-----------------------------------------------"<<endl;
	contador=1;
	for(int i=0; i<cantidad_estudiantes;i++) {
			
		cout<<"------------------------------------------------------------------------------------------------------------------------\n"<<endl;
		cout<<"usted esta ingresando el estudiante No."<<contador<<".          Total de Estudiantes a ingresar  No."<<cantidad_estudiantes<<"."<<endl;
		contador++; 
		cout<<"------------------------------------------------------------------------------------------------------------------------\n"<<endl;
		cout<<"Codigo: ";
		cin>>estudiante.codigo[i];
		cin.ignore();
		cout<<"Nombre: ";
		getline(cin,estudiante.nom[i]);
		
		cout<<"Apellido: ";
		getline(cin,estudiante.apell[i]);
		
			for(int j=0; j<cantidad_notas;j++) {
				cout<<"Ingrese Nota "<<j +1<<": ";
				cin>>*(*(estudiante.pm_notas+i)+j);	
			}
	cout<<"------------------------------------------"<<endl;		
	}
	
system("cls");
	cout<<"---------------------------------------------------------MOSTRANDO NOTAS-----------------------------------------------"<<endl;
	for(int i=0; i<cantidad_estudiantes;i++) {
		cout<<"Codigo: "<<estudiante.codigo[i]<<"\tEstudiante: "<<estudiante.nom[i]<<"\tApellido: "<<estudiante.apell[i]<<"\n"<<endl;
		sumatoria_notas=0;
		promedio=0; 
		for (int j=0; j<cantidad_notas;j++) {
		cout<<"Nota ["<<j + 1<<"]: "<<*(*(estudiante.pm_notas+i)+j);
		sumatoria_notas=sumatoria_notas+*(*(estudiante.pm_notas+i)+j);
		cout<<endl;
		}
		promedio=sumatoria_notas/cantidad_notas;
		cout<<"\n"<<endl;
		cout<<"Promedio: "<< fixed <<setprecision(2)<<promedio<<endl;
			if(promedio>61){
				cout<<"Aprobado"<<endl;
			} else  {
				cout<<"Reprobado"<<endl;
			}
	}


system("PAUSE");
return 0;
	
}
