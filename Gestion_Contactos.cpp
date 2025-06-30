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

const int TAM=5;
contactoEmail numcontactos[TAM];

void agregarContacto(){
	cin.ignore();
	
	contactoEmail est;
	cout<<"Ingrese el nombre completo: ";
	getline(cin,est.nombre);
	cout<<"Ingrese el sexo (M (Masculino), F (Femenino)): ";
	cin>>est.sexo;
	cout<<"Ingrese la edad: ";
	cin>>est.edad;
	cout<<"Ingrese el telefono: ";
	getline(cin,est.telefono);
	cout<<"Ingrese el email: ";
	getline(cin,est.email);
	cout<<"Ingrese la nacionalidad: ";
	getline(cin,est.nacionalidad);
	
	cout<<endl<<"CONTACTO AÑADIDO"<<endl;
	cout<<"Nombre: "<<est.nombre<<endl;
	cout<<"Sexo: "<<est.sexo<<endl;
	cout<<"Edad: "<<est.edad<<endl;
	cout<<"Telefono: "<<est.telefono<<endl;
	cout<<"Email: "<<est.email<<endl;
	cout<<"Nacionalidad: "<<est.nacionalidad<<endl<<endl;
}

void eliminarContacto(){
	cin.ignore();
	
	string nombre;
	cout<<"Ingrese el contacto a eliminar: ";
	getline(cin, nombre);
	bool resultado=false;
	
	int n=TAM;
	for(int i=0;i<n;i++){
		if(numcontactos[i].nombre==nombre){
			for(int j=i;j<n-1;j++){
				numcontactos[j]=numcontactos[j+1];
			}
			n--;
			resultado=true;
			cout<<"Contacto "<<nombre<<" eliminado"<<endl;
			break;
		}
	}
	if(resultado=false){
		cout<<"Contando no ubicado"<<endl;
	}
}

void listaContactos(){
	if(numcontactos==0){
		cout<<"No hay contactos registrados"<<endl;
		return;
	}
	int n=TAM;
	for(int i=0;i<n;i++){
		cout<<"LISTA DE CONTACTOS REGISTRADOS"<<endl;
		cout<<"Nombre: "<<numcontactos[i].nombre<<endl;
		cout<<"Sexo: "<<numcontactos[i].sexo<<endl;
		cout<<"Edad: "<<numcontactos[i].edad<<endl;
		cout<<"Telefono: "<<numcontactos[i].telefono<<endl;
		cout<<"Email: "<<numcontactos[i].email<<endl;
		cout<<"Nacionalidad: "<<numcontactos[i].nacionalidad<<endl<<endl;
	}
}

void listaContactosOrdenados(){
}

int main(){
	const int TAM=0;
	char menu_opcion;
	do{
	cout<<"INGRESE UNA OPCION"<<endl;
	cout<<"a) Agregar un contacto"<<endl;
	cout<<"b) Eliminar un contacto"<<endl;
	cout<<"c) Mostrar lista de contactos registrados"<<endl;
	cout<<"d) Mostrar contactos existentes, ordenado por correo"<<endl;
	cout<<"e) Salir del programa"<<endl<<endl;
	cin>>menu_opcion;
	switch (menu_opcion){
		case 'a':
			//Agregar un contacto
			agregarContacto();
			break;
		case 'b':
			//Eliminar un contacto
			eliminarContacto();
			break;
		case 'c':
			//Mostrar lista de contactos registrados
			listaContactos();
			break;
		case 'd':
			//Mostrar contactos existentes, ordenado por correo
			listaContactosOrdenados();
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