#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
using namespace std;



void Write(int m,ofstream& file){
  char m2;
  m2 = m;
  //cout<<m<<" ";
  file<< m2;
}
void Cesar_Cifrado(){
  string FILE = "Texto.txt";
  ifstream read(FILE,std::ifstream::in);
  int trans = 3;
  char c;
  if(read){
    ofstream file2;
    file2.open("CesarCifrado.txt",ios::out);
    while(read.get(c)){
      if ((c>='A')&&(c<='Z'))
      {
          c=((c+trans-'A')%('Z'-'A'+1))+'A';
      }
      else if ((c>='a')&&(c<='z'))
                {
                    c=(c+trans-'a')%('z'-'a'+1)+'a';
                }
      Write(c,file2);
        }
  }
  else{
    cout<<"Archivo no encontrado"<<endl;
  }
  read.close();
}

void Decifrado_Cesar(){

  string FILE = "CesarCifrado.txt";
  ifstream read(FILE,std::ifstream::in);
  int trans = 3;
  char c;
  if(read){

    ofstream file2;
    file2.open("DesifradoCesar.txt",ios::out);
    while(read.get(c)){
      if ((c>='A')&&(c<='Z'))
      {
          c=((c-trans-'A')%('Z'-'A'+1))+'A';
      }
      else if ((c>='a')&&(c<='z'))
                {
                    c=(c-trans-'a')%('z'-'a'+1)+'a';
                }
      Write(c,file2);
        }
  
  }
  else{
    cout<<"Archivo no encontrado"<<endl;
  }
  read.close();


}

int main()
{

  Cesar_Cifrado();

  //Decifrado_Cesar();
}
