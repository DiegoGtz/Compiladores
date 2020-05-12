#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>	
#include <cctype>
#include <cstring>
#include <stdio.h>
using namespace std;
bool isMinus(char m){
	return m == '-';
}
bool isPoint(char m){
	return m == '.';
}
string Number_Recognition(string texto){
int state = 1;
int i = 0;

while (i < texto.size()){
	char symbol = texto[i];

	switch(state)
	{
		case 1:
			if(isdigit(symbol)){state = 2;}
			else if(isMinus(symbol)){state = 3;}
			else if(isPoint(symbol)){state = 5;}
			else if(isalpha(symbol)){state = 4;}
			else{return "Error";}
			break;
		case 2:
			if(isdigit(symbol)){state = 2;}
			else if(isPoint(symbol)){state = 5;}
			else{return "Error";}
			break;
		case 3:
			if(isdigit(symbol)){state = 2;}
			else{return "Error";}
			break;
		case 4:
			return "Error";
			break;
		case 5:
			if(isdigit(symbol)){state = 6;}
			break;
		case 6:
			if(isdigit(symbol)){state = 6;}
			else{return "Error";}
			break;
	}
	i++;
}
if (state == 2 or state == 6){return "Aceptado";}
else{return "Error";}
}
int main()
{	
	string texto = "-0.15";
	cout<<"El texto ingresado = "<<texto<<endl;
	cout<<Number_Recognition(texto);
	return 0;
}