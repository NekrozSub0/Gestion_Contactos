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
int totalcontactos=0;

void agregarContacto(){
	if(totalcontactos>=TAM){
		cout<<"Limite alcanzado"<<endl;
		return;
	}
	
	cin.ignore();
	contactoEmail est;
	cout<<"Ingrese el nombre completo: ";
	getline(cin,est.nombre);
	cout<<"Ingrese el sexo (M (Masculino), F (Femenino)): ";
	cin>>est.sexo;
	cout<<"Ingrese la edad: ";
	cin>>est.edad;
	cin.ignore();
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
	
	numcontactos[totalcontactos]=est;
	totalcontactos++;
}

void eliminarContacto(){
	cin.ignore();
	string nombre;
	cout<<"Ingrese el contacto a eliminar: ";
	getline(cin, nombre);
	bool resultado=false;
	
	int n=TAM;
	for(int i=0;i<totalcontactos;i++){
		if(numcontactos[i].nombre==nombre){
			for(int j=i;j<totalcontactos-1;j++){
				numcontactos[j]=numcontactos[j+1];
			}
			totalcontactos--;
			resultado=true;
			cout<<"Contacto "<<nombre<<" eliminado"<<endl<<endl;
			break;
		}
	}
	if(resultado==false){
		cout<<"Contando no ubicado"<<endl<<endl;
	}
}

void listaContactos(){
	cout<<"LISTA DE CONTACTOS REGISTRADOS"<<endl<<endl;
	for(int i=0;i<totalcontactos;i++){
		cout<<"Nombre: "<<numcontactos[i].nombre<<endl;
		cout<<"Sexo: "<<numcontactos[i].sexo<<endl;
		cout<<"Edad: "<<numcontactos[i].edad<<endl;
		cout<<"Telefono: "<<numcontactos[i].telefono<<endl;
		cout<<"Email: "<<numcontactos[i].email<<endl;
		cout<<"Nacionalidad: "<<numcontactos[i].nacionalidad<<endl<<endl;
	}
}

string dominiodelcorreo(string email){
	size_t pos=email.find('@');
	if (pos != string::npos){
		return email.substr(pos +1);
	}
	return "";
}

void listaContactosOrdenados(){
	for(int i=0;i<totalcontactos-1;i++){
		for(int j=0;j<totalcontactos-i-1;j++){
			string dominio1=dominiodelcorreo(numcontactos[j].email);
			string dominio2=dominiodelcorreo(numcontactos[j+1].email);
			if(dominio1>dominio2){
				contactoEmail aux=numcontactos[j];
				numcontactos[j]=numcontactos[j+1];
				numcontactos[j+1]=aux;
			}
		}
	}
	cout<<"LISTA DE CONTACTOS ORDENADOS POR CORREO"<<endl<<endl;
	listaContactos();
}

int main(){
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