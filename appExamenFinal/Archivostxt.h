class Archivostxt{
private:
	//Hacer una clase para guardar en el binario
	string nombreCliente;
	char nombreProducto[25];
	int numProducto;
public:
	
	//Setter
	void setNombreProducto(string nombre){
		strncpy(nombreProducto, nombre.c_str(), sizeof(nombreProducto) - 1);
		nombreProducto[sizeof(nombreProducto) - 1] = '\0';
	}
	//getter
	//metodos de calculo
	void imprimirClientesDelArchivo() {
		ifstream archClientes("Clientes.txt");  
		if (archClientes.fail()) {
			cout << "No se pudo abrir el archivo." <<endl;
		}
		int id;
		string nombre;
		string tele;
		string direccion;
		while (archClientes>> id >>nombre>>tele>>direccion) {
			cout<<"id: "<<id<<" nombre: "<<nombre <<" telefono: "<<tele<<" Direccion "<<direccion<<endl;
		}
		
		archClientes.close();  
		}
			
	void imprimirProductosDelArchivo() {
		ifstream archProductos("Productos.txt",ios::in);  
		if (archProductos.fail()) {
			cout << "No se pudo abrir el archivo Productos.txt" <<endl;
		} else {
			int id;
			string nombre;
		
			while (archProductos>>id>>nombre) {
					cout <<"id:"<<id<<" nombre: "<<nombre<<endl;
			}
		}
		archProductos.close();  
	}	
	
	void MatricularCliente(){/////METODO DE MATRICULARCLIENTE
		int idCliente;
		cout<<"Digite la identificacion del cliente: "<<endl;
		cin>>idCliente;
		if(existeCliente(idCliente)==true){
			int IdProducto;
			otraVez:
			cout<<nombreCliente<<" Que producto desea elegir??? "<<endl;
			cin>>IdProducto;
			if(existeProducto(IdProducto)==true){
				cout<<nombreProducto<<" se procedera a guardarse en la base de datos "<<endl;
				ofstream nuevoDatoCliente(nombreCliente+".txt",ios::binary|ios::app);
				nuevoDatoCliente.write(reinterpret_cast<char *>(&numProducto), sizeof(numProducto));
				nuevoDatoCliente.write(reinterpret_cast<char *>(&nombreProducto), sizeof(nombreProducto));
				nuevoDatoCliente.close();
				int decision;
				cout<<nombreCliente<<" desea seguir comprando?"<<endl;
				cout<<"1.Si"<<endl;
				cout<<"2.No"<<endl;
				cin>>decision;
				switch(decision){
				case 1:{
					goto otraVez;
				}
				case 2:{
						cout<<"Chaito,que metodo,parece corto pero es un metodo que llama a otros"<<endl;
						break;
					}
				default:{
							cout<<"Digite correctamente,sí?"<<endl;
							break;
						}
				}
			}
			
		}else{cout<<"Dicho cliente no existe"<<endl;}
	 
	}
	void verPedidoDeUnCliente(){
		string nombreArch;
		cout<<"Digite el nombre del cliente(En mayuscula porfis)"<<endl;
		cin>>nombreArch;
		ifstream ClienteLectura(nombreArch+".txt",ios::in); 
		if (!ClienteLectura) //operador sobre cargado
		{
			cout << "Dicha persona no ha realizado pedidos" << endl;
			system("pause");
			
		}else{
			cout<<"Productos pedidos por "<<nombreArch<<endl;
			char nombreLProducto[25];
			ClienteLectura.seekg(0);
			ClienteLectura.read(reinterpret_cast<char *>(&numProducto), sizeof(numProducto));
			ClienteLectura.read(reinterpret_cast<char *>(&nombreLProducto), sizeof(nombreLProducto));
			while (!ClienteLectura.eof()){
				if (ClienteLectura.good())
				{
					cout<<numProducto<<" ";
					for(int i=0;i<25;i++){
					cout<<nombreLProducto[i];
					}
					cout<<endl;
					
				}
				ClienteLectura.read(reinterpret_cast<char *>(&numProducto), sizeof(numProducto));
				ClienteLectura.read(reinterpret_cast<char *>(&nombreLProducto), sizeof(nombreLProducto));
			}
			
			ClienteLectura.close();
			cout << "Productos recuperadas del archivo del binario." << endl;
		}
	}	
	//Metodos de confirmacion-------------------------------------------------
	bool existeCliente(int idCliente){
		ifstream archClientes("Clientes.txt");  
		if (archClientes.fail()) {
			cout << "No se pudo abrir el archivo." << std::endl;
			return false;
		}else{
		int id;
		string nombre;
		string tele;
		string direccion;
		while (archClientes>> id >>nombre>>tele>>direccion) {
			if(idCliente==id){
				cout<<"id: "<<id<<" nombre: "<<nombre <<" telefono: "<<tele<<" Direccion "<<direccion<<endl;
				cout<<"Existe este cliente"<<endl;
				nombreCliente=nombre;
				return true;
			}
		}
		return false;
		cout<<"El cliente no existe"<<endl;
		}
		archClientes.close(); 
		return false;
	}	
		//Para producto
	bool existeProducto(int idProducto){
		ifstream archProductos("Productos.txt",ios::in);
		if (archProductos.fail()) {
			cout << "No se pudo abrir el archivo Productos.txt" <<endl;
		} else {
			int id;
			string nombre;
			while (archProductos>>id>>nombre) {
				if(id==idProducto){
				cout <<"id: "<<id<<" nombre: "<<nombre<<endl;
				cout<<"El producto existe "<<endl;
				setNombreProducto(nombre);
				numProducto=id;
				return true;
				}
			}
			cout<<"El producto no existe"<<endl;
			return false;
		}
		archProductos.close();  
	}
		
			
			
			
			
	
};
