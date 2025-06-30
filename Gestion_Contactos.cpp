#include <iostream>
#include <string>
using namespace std;

struct contactoEmail{
	string nombre;
	char sexo;
	int edad;
	string telefono;
	string email;
	string nacionalidad;
};
	
int main(){
	char menu_opcion;
	do{
	cout<<"Ingrese una opcion"<<endl;
	cout<<"a) Agregar un contacto"<<endl;
	cout<<"b) Eliminar un contacto"<<endl;
	cout<<"c) Mostrar lista de contactos registrados"<<endl;
	cout<<"d) Mostrar contactos existentes, ordenado por correo"<<endl;
	cout<<"e) Salir del programa"<<endl<<endl;
	cin>>menu_opcion;
	switch (menu_opcion){
		case 'a':
			//Agregar un contacto
			
			break;
		case 'b':
			//Eliminar un contacto
			
			break;
		case 'c':
			//Mostrar lista de contactos registrados
			
			break;
		case 'd':
			//Mostrar contactos existentes, ordenado por correo
			
			break;
		case 'e':
			//Salir del programa
			cout<<"Programa finalizado"<<endl;
			break;	
		default:
			//Repetir menu hasta elegir una opcion
			cout<<"ERROR: Eliga una opcion del menu (a, b, c, d, e)"<<endl<<endl;
			break;
	}
	}while (menu_opcion!='e');
	return 0;
}