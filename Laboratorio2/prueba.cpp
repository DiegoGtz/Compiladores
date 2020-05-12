#include <map>
#include <vector>
#include <string>
#include <iostream>

typedef std::map<std::string, int> col_val_map;
typedef std::vector<col_val_map> table;

int main(){
  table t(3);

  std::string col = "Width";
  t[0][col] = 5;
  t[0][col] = 10;
  t[0][col] = 42;
  col = "Height";

  t[1][col] = 20;
  t[1][col] = 3;
  t[1][col] = 1337;


  col = "Random";

  t[2][col] = 2;
  t[2][col] = 10;
  t[2][col] = 0;

  std::cout << "\t\tWidth\t\tHeigth\t\tRandom\n";
  for(int i=1; i <= 3; ++i){
    std::cout << i << "\t\t" << t[i-1]["Width"]
                   << "\t\t" << t[i-1]["Height"]
                   << "\t\t" << t[i-1]["Random"]
                   << "\n";
  }
}



        switch(c){
          case 0:
            t[c][col1] = numero;
            
            numero="";
            break;
          case 1:
            t[c][col2] = numero;
            
            numero="";
            break;
          case 2:
            t[c][col3] = numero;
            
            numero="";
            break;
          case 3:
            t[c][col4] = numero;
            
            numero="";
            break;
          case 4:
            t[c][col5] = numero;
            
            numero="";
            break;
        }