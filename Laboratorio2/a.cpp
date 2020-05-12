#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>	
#include <cctype>
#include <cstring>

using namespace std;

void Diagrama_Transicion(int estado,string entrada)
{
	int _Estado = estado;
	char simbolo =  entrada[0];

	for (int i = 0; i < entrada.size()-1; ++i)
	{
		simbolo = entrada[i];
		if(_Estado != 3 ){
			if (isdigit(simbolo) ){_Estado = 2 ;}
			else if(isalpha(simbolo)){_Estado = 3 ;}
			else {
				cout<<"Error ";
			}
			if(isalpha(simbolo)){_Estado = 3;}
			else if(isdigit(simbolo)){_Estado = 3;}
			else {
				cout<<"Error";
			}	
		}

				
	}
	if(_Estado != 3 ){
		cout<<"error";
	}
} 
string Diagrama_Transicion(string entrada)
{
	int _Estado = 1	;
	char simbolo =  entrada[0];

	for (int i = 0; i < entrada.size()-1; ++i)
	{
		simbolo = entrada[i];
		switch(_Estado)
		{
			case 1 : 
				if (isdigit(simbolo) ){
					_Estado = 2 ;	
				}else if(isalpha(simbolo)){
					_Estado = 3 ;
				}else{
					return "Erorr";
				}
				break;
			case 2 :
				return "Erorr"; 
				break;
			case 3 : 
				if(isalpha(simbolo)){
					_Estado = 3;
					
				}else if(isdigit(simbolo)){
					_Estado = 3;
					
				}else{
					creturn "Erorr";
				}
				break;
		}			
	}
	if(_Estado != 3 ){
		return "Erorr" ;
	}
	return "Acepto";
} 



int main()
{
	string palabra ="1Perrito";

	Diagrama_Transicion(palabra);
	
	return 0;
}