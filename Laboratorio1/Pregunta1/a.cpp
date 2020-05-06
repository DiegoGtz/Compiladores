#include <iostream>
#include <string>
#include <string.h>
#include <fstream>

using namespace std;


void Leer_Frase(string palabra){

	for(int i = 0; i < palabra.size(); i++){
		if(palabra[i] !=' '){cout<<palabra[i]<<endl;}
		
	}
}
int main()
{
	string palabra ="int temp";

	Leer_Frase(palabra);

;	return 0;
}