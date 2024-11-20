#include<iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;
#include "Cliente.h"
#include "Archivostxt.h"

Archivostxt arch;
int main (int argc, char *argv[]) {
	
	//RECORDATORIO  si me da tiempo:pon la libreria de lenguaje porque los txt se ven feos
	int opcion;
	do{
		
	cout<<"1.Ver listado de clientes"<<endl;
	cout<<"2.Ver listado de productos"<<endl;
	cout<<"3.Realizar pedido "<<endl;
	cout<<"4.Ver pedido de un cliente"<<endl;
	cout<<"5.Salir"<<endl;
	cin>>opcion;
	system("cls");
	switch(opcion){
		
	case 1:{
		
		arch.imprimirClientesDelArchivo();
		
		system("pause");
		system("cls");
		break;
	}
	case 2:{
		arch.imprimirProductosDelArchivo();
		system("pause");
		system("cls");
		break;
	}
	case 3:{
		
		arch.MatricularCliente();
		system("pause");
		system("cls");
		break;
	}
	case 4:{
			arch.verPedidoDeUnCliente();
			system("pause");
			system("cls");
			break;
		}
	case 5:{
			int opcion2;
			cout<<"Seguro que desea salir?"<<endl;
			cout<<"1Sí"<<endl;
			cout<<"2.No"<<endl;
			cin>>opcion2;
			switch(opcion2){
				case 1:{
				cout<<"Chaito"<<endl;
				break;
				}
				case 2:{
				opcion=0;
				cout<<"Usted seguira en el programa "<<endl;
				system("pause");
				system("cls");
				break;
				}
			}
			break;
		}
	}
	
	} while(opcion!=5);
	
	

	system("pause");
	system("cls");
	return 0;
}

