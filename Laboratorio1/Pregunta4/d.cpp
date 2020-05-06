#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <cctype>
#include <cstring>
using namespace std;

const char operadores[5] = {'+','-','*','/',':'};
bool es_operador(char operadores1)
{
  for(int i = 0;i<8;i++)
      {
          if(operadores[i]== operadores1)
          {
              return true;
          }
      }
      return false;
}
void Analizador(){
  string FILE = "Texto2.txt";
  ifstream read(FILE,std::ifstream::in);
  char c;
  char token;
  string palabra ;
  string numero ;
  string operador;
  if(read){
    while(read.get(c)){
      if(c == '\n' || c ==' '){
        if(!palabra.empty()){cout<<"Encontramos una palabra  ---> " + palabra<<endl;}
        if(!numero.empty()){cout<<"Encontramos un numero     ---> " + numero<<endl;}
        if(!operador.empty()){cout<<"Encontramos un operador ---> " + operador<<endl;}
        palabra = "";
        numero = "";
        operador = "";
      }
      else{
        if(isalpha(c)) palabra += c; 
        else if( isdigit(c)) numero +=c;
        else if(es_operador(c)) operador += c;
      }
    }
  }
  else{
    cout<<"Archivo no encontrado "<<endl;
  }
}

int main()
{
  Analizador();
  return 0 ;
}