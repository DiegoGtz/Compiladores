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


_Tabla Leer_Tabla(){

string col1,col2,col3,col4,col5;
col1 = "Digito";
col2 = "Letra";
col3 = "Punto";
col4 = "Signo";
col5 = "FDC";
string line;
ifstream myfile("Tabla.txt");
string numero = "";
int num;
_Tabla t(6) ;

  t[0][col1] = '2';
  t[1][col1] = '2';
  t[2][col1] = '2';
  t[3][col1] = "error";
  t[4][col1] = '5';
  t[5][col1] = '5';


  t[0][col2] = '4';
  t[1][col2] = "error";
  t[2][col2] = "error";
  t[3][col2] = "error";
  t[4][col1] = "error";
  t[5][col1] = "error";

  t[0][col3] = '5';
  t[1][col3] = '5';
  t[2][col3] = "error";
  t[3][col3] = "error";
  t[4][col1] = "error";
  t[5][col1] = "error";

  t[0][col4] = '3';
  t[1][col4] = "error";
  t[2][col4] = "error";
  t[3][col4] = "error";
  t[4][col1] = "error";
  t[5][col1] = "error";

  t[0][col5] = "error";
  t[1][col5] = "aceptar";
  t[2][col5] = "error";
  t[3][col5] = "error";
  t[4][col5] = "error";
  t[5][col5] = "aceptar";


/*if(myfile.is_open()){
	while(getline(myfile,line)){

		int c = 0;
		for (int i = 0; i < line.size(); i++)
		{
			if(line[i] == ';'){

			 	switch(c){
			 		case 0:
			 			t[c][col1] = numero;
			 			cout<<"C : "<<c<<col1<<endl;
						cout<<"letra : "<< numero<<endl;
			 			numero="";
			 			break;
			 		case 1:
			 			t[c][col2] = numero;
			 			cout<<"C : "<<c<<col2<<endl;
						cout<<"letra : "<< numero<<endl;
			 			numero="";
			 			break;
			 		case 2:
			 			t[c][col3] = numero;
			 			cout<<"C : "<<c<<col3<<endl;
						cout<<"letra : "<< numero<<endl;	
			 			numero="";
			 			break;
			 		case 3:
			 			t[c][col4] = numero;
			 			cout<<"C : "<<c<<col4<<endl;
						cout<<"letra : "<< numero<<endl;	
			 			numero="";
			 			break;
			 		case 4:
			 			t[c][col5] = numero;
			 			cout<<"C : "<<c<<col5<<endl;
						cout<<"letra : "<< numero<<endl;	
			 			numero="";
			 			break;
			 	}
			 c++;	
			}else{
				numero+= line[i];
			}
			

		}
		c = 0; 
	}
	return t;
}
else{
	cout<<"Error";

}
*/
return t;
}


string _Tabla_Transicion( _Tabla t,string text){

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

int main()
{
	_Tabla t = Leer_Tabla();

	cout << "\t\tDigito\t\tLetra\t\tPunto\t\tSigno\t\tFDC\n";
  	for(int i=1; i <= 5; ++i){
    	cout << i << "\t\t" << t[i-1]["Digito"]<< "\t\t" << t[i-1]["Letra"]<< "\t\t" << t[i-1]["Punto"]<< "\t\t" << t[i-1]["Signo"]<< "\t\t" << t[i-1]["FDC"]<< "\n";
    }
	//Leer_Tabla();
	return 0;
}