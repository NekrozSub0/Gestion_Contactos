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
	cout<<"Ingrese una opcion"<<endl;
	cout<<"a) Agregar un contacto"<<endl;
	cout<<"b) Eliminar un contacto"<<endl;
	cout<<"c) Mostrar lista de contactos registrados"<<endl;
	cout<<"d) Mostrar contactos existentes, ordenado por correo"<<endl;
	cout<<"e) Salir del programa"<<endl;
	cin>>menu_opcion;
	switch (menu_opcion){
		case 'a':
			
			break;
		case 'b':
			
			break;
		case 'c':
			
			break;
		case 'd':
			
			break;
		case 'e':
			
			break;	
		default:
			break;
	}
	return 0;
}