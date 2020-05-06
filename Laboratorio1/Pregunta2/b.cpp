#include <iostream>
#include <string>
#include <string.h>
#include <fstream>

using namespace std;

void Lee_ArchivoTXT(){
	string FILE = "Texto.txt";
	ifstream read(FILE,std::ifstream::in);
	char c;
	if(read){
		while(read.get(c)){
			if( c !='\n' and c !=' '){ // si no consideramos tanto saltos de linea y espacio
										//Si consideramos los saltos no es necesario el condicional 	
				cout<<c<<endl;
			}
		}
	}
	else{
		cout<<"Archivo no encontrado"<<endl;
	}
}
int main()
{

	Lee_ArchivoTXT();	
	return 0;
}