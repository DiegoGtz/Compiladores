#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>	
#include <cctype>
#include <cstring>
#include <stdio.h>

using namespace std;

typedef map<std::string, string> col_val_map;
typedef vector<col_val_map> _Tabla;


string _Tabla_Transicion( string text){
  _Tabla t(3);
  string col = "Digito";
  t[0][col] = '2';
  t[1][col] = "error";
  t[2][col] = '3';

  col = "Letra";
  t[0][col] =  '3';
  t[1][col] =  "error";
  t[2][col] =  '3';

  col = "FDC";
  t[0][col] = "error";
  t[1][col] = "error";
  t[2][col] =  "aceptar";

string state ="1";
int i = 0;

string _in;

//cout<<"Tamanio"<<text.size()<<endl;
while(state != "aceptar" && i!=text.size() ){
	//cout<<"i = "<<i<<endl;
	char symbolo = text[i]; 
	//cout<<symbolo<<endl;
	
	if (isdigit(symbolo)){_in = "Digito"; }
	else if (isalpha(symbolo)){_in = "Letra";}
	else if ( i == text.size()-1){
		_in = "FDC";
	}
	else {
		//cout<<"sss"<<symbolo<<endl;
		return "error3";
	}
	char n = state[0];
	if(isdigit(n)){
		int mm = n - '0';
		state =  t[mm-1][_in];
	}
	if (state == "error"){
		return "error4";
	}
	i++;
}
return "aceptar";
}

int main(){
  string m = _Tabla_Transicion("aaa");
  cout <<m;
}