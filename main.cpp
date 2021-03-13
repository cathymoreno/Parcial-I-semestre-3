#include <iostream>
#include <stdio.h>  
#include <string.h> 
#include<fstream>
#include <bits/stdc++.h> 
  


using namespace std;
const char *nombe_archivo = "archivo.dat";

struct Empleado{
	int codigo;
	char nombre[50];
	char apellido[50];
	char puesto[50];
	int sueldo;
	int bonificacion;
	int salario;
	int retorna_codigo()
      {
        return codigo;
      }
};
 void ingresar_empleado();
 void abrir_empleado();
 void delete_empleado();
 void modificar_empleado();
 int main (){
 	int mn;
	 mn=0;
	while(mn=4)
	{
	
 	system ("cls");
 	
	abrir_empleado();
	
	cout<<"Menu para empleados"<<endl;
	cout<<"1. Ingresar empleado"<<endl;
	cout<<"2. Modificar empleado"<<endl;
	cout<<"3. Eliminar empleado"<<endl;
	cout<<"4. Salir"<<endl;
	cout<<"\n\n Opcion: ";
	cin>>mn;
	switch(mn){
		
		case 1 :
			ingresar_empleado();
			main();
		break;
		
		case 2 :
			modificar_empleado();
			main();
		break;
		
		case 3 :
			delete_empleado();
			main();
		break;

	}	
	return 0;	
}
}
void buscar_indice(){
	FILE* archivo = fopen(nombe_archivo, "rb");
	
	int pos=0;
	cout<<"Que registro desea ver: ";
	cin>>pos;
	cout<<"------------------ "<<pos<<" ------------------"<<endl;
	fseek ( archivo,pos * sizeof(Empleado), SEEK_SET );
	
	Empleado empleado;
	
    fread ( &empleado, sizeof( Empleado), 1, archivo );

    	cout << "Codigo: " << empleado.codigo << endl;
        cout << "Nombre: " << empleado.nombre << endl;
        cout << "Apellido: " << empleado.apellido << endl;
        cout << "Puesto: " << empleado.puesto << endl;
        cout << "Sueldo: " << empleado.sueldo << endl;
        cout << "Bonificacion: " <<empleado.bonificacion << endl;
        cout << endl;
	
	fclose(archivo);

	
}
void abrir_empleado(){

	system("cls");
	FILE* archivo = fopen(nombe_archivo, "rb");
	if(!archivo) {
		archivo = fopen(nombe_archivo, "w+b");
	}
	Empleado empleado;
	int registro=0;
	fread ( &empleado, sizeof(empleado), 1, archivo );
	cout<<"__________________________________________________________________________________________________________________________________________________________________________________________________________________________"<<endl;
	cout << "id" <<"|"<< "CODIGO" <<"|"<< "NOMBRE"<<" "<<"  APELLIDO"<<" "<<" PUESTO"<<" "<<" SUELDO"<<" "<<"BONIFICACION"<<" "<<"SALARIO"<<endl;	
		do{
		cout<<"________________________________________________________________________________________________________________________________________________________________________________________________________________________"<<endl;
		cout << registro <<" |  "<< empleado.codigo <<" | "<< empleado.nombre<<" | "<<empleado.apellido<<" | "<<empleado.puesto<<" | "<<empleado.sueldo<<" | "<<empleado.bonificacion<<" | "<<empleado.salario<<endl;
        
        
		fread ( &empleado, sizeof(Empleado), 1, archivo );
		registro += 1;	
		} while (feof( archivo ) == 0);
		
    cout<<endl;
    
		fclose(archivo);
	}
	void ingresar_empleado(){
	
	char continuar;
	FILE* archivo = fopen(nombe_archivo, "ab"); // ab
	
	
		Empleado empleado;
		 string nombre,apellido,puesto;
		do{
			fflush(stdin);
			
		cout<<"Ingrese el Codigo:";
		cin>>empleado.codigo;
        cin.ignore();
        
		cout<<"Ingrese el Nombre:";
		getline(cin,nombre);
    	strcpy(empleado.nombre, nombre.c_str()); 
			
		cout<<"Ingrese el Apellido:";
		getline(cin,apellido);
		strcpy(empleado.apellido, apellido.c_str()); 
		
		cout<<"Ingrese el Puesto: ";
		getline(cin,puesto);
		strcpy(empleado.puesto, puesto.c_str());
		
		cout<<"Ingrese el Sueldo: ";
		cin>>empleado.sueldo;
		cin.ignore();
		
		cout<<"Ingrese la Bonificacion: ";
		cin>>empleado.bonificacion;
		cin.ignore();
		empleado.salario=empleado.bonificacion + empleado.sueldo;
		fwrite( &empleado, sizeof(Empleado), 1, archivo );
		
		cout<<"Desea Agregar otro Nombre s/n : ";
		cin>>continuar;
		} while((continuar=='s') || (continuar=='S') );
		
	
	fclose(archivo);
	/*abrir_empleado();
	buscar_indice();	
	buscar_codigo();
	*/
}
void modificar_empleado(){
	
	FILE* archivo = fopen(nombe_archivo, "r+b");
	
		int id;
		string nombre,apellido,puesto;	
    	Empleado empleado;
    
		cout << "Ingrese el ID que desea Modificar: ";
    		cin >> id;
    		fseek ( archivo, id * sizeof(Empleado), SEEK_SET );  // esto es lo que permite modificar en la posicion
	
		cout<<"Ingrese el Codigo:";
		cin>>empleado.codigo;
        cin.ignore();
        
		cout<<"Ingrese el Nombre:";
		getline(cin,nombre);
    	strcpy(empleado.nombre, nombre.c_str()); 
			
		cout<<"Ingrese el Apellido:";
		getline(cin,apellido);
		strcpy(empleado.apellido, apellido.c_str()); 
		
		cout<<"Ingrese el Puesto:";
		getline(cin,puesto);
		strcpy(empleado.puesto, puesto.c_str());
		
		cout<<"Ingrese el Sueldo:";
		cin>>empleado.sueldo;
		cin.ignore();
		
		cout<<"Ingrese la Bonificacion:";
		cin>>empleado.bonificacion;
		cin.ignore();
		empleado.salario=empleado.bonificacion + empleado.sueldo;
		
		fwrite( &empleado, sizeof(Empleado), 1, archivo );
		
	fclose(archivo);
	abrir_empleado();
		system("PAUSE");
}
void delete_empleado() 
{  	char continuar;
	do{
	
	 int codigo;
	cout << "Ingrese Codigo de empleado a eliminar: " << endl;
   cin>>codigo;
   Empleado a;
   ofstream fout ("temp.dat",ios::binary);
   ifstream fin ("archivo.dat",ios::binary);
  
  
   while(fin.read((char*)&a,sizeof(a)))
     if(a.retorna_codigo()!=codigo)
        fout.write((char*)&a,sizeof(a));
   fin.close();
   fout.close();
   remove("archivo.dat");
   rename("temp.dat","archivo.dat");
   cout<<"Desea Eliminar otro Codigo s/n : ";
		cin>>continuar;
		} while((continuar=='s') || (continuar=='S') );
		
}
void buscar_codigo(){
	
	FILE* archivo = fopen(nombe_archivo, "rb");
	
	int indice=0,pos=0,cod=0;
	cout<<"BUSCAR CODIGO: ";
	cin>>cod;
	Empleado empleado;
	
	fread ( &empleado, sizeof(Empleado), 1, archivo );
		
		do{
			
			if (empleado.codigo == cod){
			pos = indice;
			}
	
		fread ( &empleado, sizeof(Empleado), 1, archivo );
		indice += 1;
		} while (feof( archivo ) == 0);
		
	cout<<"------------------ "<<pos<<" ------------------"<<endl;
	fseek ( archivo,pos * sizeof(Empleado), SEEK_SET );

    fread ( &empleado, sizeof( Empleado ), 1, archivo );

    	cout << "Codigo: " << empleado.codigo << endl;
        cout << "Nombre: " << empleado.nombre << endl;
        cout << "Apellido: " << empleado.apellido << endl;
        cout << "Puesto: " << empleado.puesto << endl;
        cout << "Sueldo: " << empleado.sueldo << endl;
        cout << "Bonificacion: xx" <<empleado.bonificacion << endl;
        empleado.salario=empleado.bonificacion + empleado.sueldo;
        cout << endl;
	
	fclose(archivo);
	system("PAUSE");
}

