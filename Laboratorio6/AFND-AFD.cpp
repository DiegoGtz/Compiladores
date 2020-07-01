//COMPILADORES-CSUNSA
//DiegoGTZ
//AFND a FND 
// Clausura E
#include<iostream>
#include<vector>
#include<string>
#include<tuple>
#include <algorithm>
#include <vector>
#include <tuple>
#include <fstream>
#include <list>
#include <map>
#include <stdlib.h>
using namespace std;
class Estado;

typedef tuple<Estado *,char, Estado *> Transicion;
typedef int IdEstado;
class Estado
{
public:
	int 				id;
	vector<Estado *> 	subEstados;
    vector<Transicion> 	transiciones;
    string 				cadenaSubConjunto;
public:
	Estado(int id){
		this->id = id;
	}
	Estado(int id, vector<Estado*> subEstados){
		this->id = id;
		vector<int> subConjunto;
		cadenaSubConjunto = "[";
		for(Estado* estado: subEstados){
			this->subEstados.push_back(estado);
			subConjunto.push_back(estado->id);
		}
		sort(subConjunto.begin(),subConjunto.end());

		for(int id :subConjunto ){
			cadenaSubConjunto += to_string(id) + " ";
		}
		cadenaSubConjunto.push_back(']');
	}
};

class Automata
{
public:
	Estado * 			Es_Inicial;
	vector<Estado* > 	Con_Estadodos;
	vector<Estado*>  	Es_aceptacion;
	vector<int> 		Entradas;
	vector<Transicion> 	Transiciones;

public:
	Automata(){};
	Automata(string _file){
	ifstream file(_file.c_str());
	string caracter = "";

	int estado = 0 ;
	while(file>>caracter){
		if(estado == 0){
			file>>caracter;
			//cout<<caracter<<endl;
			int m = stoi(caracter);
			for (int i = 0; i < m; i++)
			{
				file>>caracter;
				Con_Estadodos.push_back(new Estado(stoi(caracter)));
			}
			this->Es_Inicial = findEstado(0);
			//cout<<"Estado inicial"<<Es_Inicial->id<<endl;
			file>>caracter;
			estado++;
		}
		else if(estado == 1){
			//file>>caracter;
			//cout<<caracter<<endl;
			int num_Estados = stoi(caracter);
			for(int i = 0; i < num_Estados; i++){
				file>>caracter;
				Es_aceptacion.push_back(new Estado(stoi(caracter)));
			}
			file>>caracter;
			estado++;
		}
		else if(estado == 2 ){
			int num_Esntradas = stoi(caracter);
			for (int i = 0; i < num_Esntradas; i++)
			{
				file>>caracter;

				int token = stoi(caracter);
				Entradas.push_back(token);
			}
			file>>caracter;
			estado++;
		}
		else if(estado ==3){

			int num_Transiciones = stoi(caracter);

			for (int i = 0; i < num_Transiciones; i++)
			{
				file>>caracter;
				int id_1 = stoi(caracter);
				Estado* estado1 = findEstado(id_1);

				file>>caracter;
				int trans = stoi(caracter);

				file>>caracter;

				int id_2 = stoi(caracter);
				Estado* estado2 = findEstado(id_2);

				//cout<< estado1->id<<" "<<trans<<" "<<estado2->id<<endl;

				Transiciones.push_back(make_tuple(estado1,trans,estado2));
				estado1->transiciones.push_back(make_tuple(nullptr,trans,estado2));
			}			
		}

	}

	}
	Estado* findEstado(int id){
		for (Estado*res : Con_Estadodos)
		{
			if(res->id == id) return res;
		}
		return nullptr;
	}

	vector<Estado *> deleteRepeat(vector<Estado *> estadosV){
	    vector<Estado *> res;
	    vector<int> temp;
	    for(Estado * estado : estadosV){
	        temp.push_back(estado->id);
	    }
	    sort(temp.begin(), temp.end());
	    temp.erase(unique(temp.begin(),temp.end()),temp.end());
	    for(int id : temp){
	        res.push_back(findEstado(id));
	    }
	    return res;
	}

	vector<Estado* > E_clausura(Estado * estado){
		map<int, bool> E_visitado;
		list<Estado* > Pila;
		vector<Estado*> token;
		for(Estado * estado: Con_Estadodos)
		{
			E_visitado[estado->id] = false;
		}
		Estado * actual = nullptr;
    	Estado * estado1 = nullptr;
    	Estado * estado2 = nullptr;
    	int entrada;
    	token.push_back(estado);
    	Pila.push_front(estado);
    	while(!Pila.empty()){
    		actual = Pila.front();
    		Pila.pop_front();
    		E_visitado[actual->id] = true;
    		for(Transicion transicion : actual->transiciones){
    			tie(estado1,entrada,estado2) = transicion;
    			//cout<<"Entrada1 "<<entrada<<endl;	
    			if(entrada == -1 and !E_visitado[estado2->id]){
    				Pila.push_front(estado2);
    				token.push_back(estado2);
    			}
    		}

    	}
    	return token;		
	}

	vector<Estado *> E_clausura(vector<Estado*> _estados){
		vector<Estado*> v;
		for(Estado* estado : _estados){
			vector<Estado*> temp = E_clausura(estado);
			v.insert(v.begin(),temp.begin(),temp.end());
		}
		v = deleteRepeat(v);
		return v;
	}
	vector<Estado* > findTransiciones(vector<Estado* > _estados, int trans){
		vector<Estado*> v;
		Estado * r = nullptr;
    	Estado * s = nullptr;
    	int tran;
    	for(Estado* estado: _estados){
    		for (Transicion transicion : estado->transiciones)
    		{
    			tie(r,tran,s) = transicion;
    			if(tran == trans) v.push_back(s);
    		}
    	}
    	v= deleteRepeat(v);
    	return v;
	}
	Estado * findSub_Conjunto(vector<Estado* > subconjunto){
		if(subconjunto.empty()){
			return nullptr;
		}
		vector<int> subconjunto_ID;
		string comp = "[";
		for(Estado * estado : subconjunto){
			subconjunto_ID.push_back(estado->id);
		}
		sort(subconjunto_ID.begin(),subconjunto_ID.end());
		for(int id : subconjunto_ID){
			comp = comp + to_string(id) + " "; 
		}
		
		comp.push_back(']');
		//cout<<"Comp"<<comp<<endl;
		for(Estado* estado : Con_Estadodos){
			if(!estado->cadenaSubConjunto.empty()){
				if(estado->cadenaSubConjunto == comp) return estado;
			}
		}
		return nullptr;
	}
	bool Estado_Aceptacion(int id){
		for(Estado* estado : Es_aceptacion){
			if(estado->id == id)return true;
		}
		return false;
	}

	void OutFileAutomta(ostream & file, bool run){
	    file<<"Estados"<<endl;
	    file<<Con_Estadodos.size()<<endl;
	    for(Estado* estado : Con_Estadodos){
	    	if(run){
	    		file<<estado->id<<" "<<estado->cadenaSubConjunto<<endl;
	    	}
	    	else{
	    		file<<estado->id<<" ";
	    	}
	    }
	    if(!run){file<<endl;}
	    file<<"Inicial"<<endl;
	    file<<Es_Inicial->id<<endl;
	    file<<"Aceptacion"<<endl;	
	    file<<Es_aceptacion.size()<<endl;
	    for(Estado*estado : Es_aceptacion){file<<estado->id<<" ";}
	    file<<endl;
	    file<<"Entradas"<<endl;
	    file<<Entradas.size()<<endl;    
	    for(int c : Entradas){file<<c<<" ";}
	    file<<endl;
		file<<"Transiciones"<<endl;
		file<<Transiciones.size()<<endl;
		Estado* r = nullptr;
		Estado* s = nullptr;
		int c;
		for(Transicion  trans : Transiciones){
			tie(r,c,s) = trans;
			file<<r->id<<" "<<c<<" "<<s->id<<endl;
		}
	}
	void Graficar(string tipo)
	{
 		string name = tipo;
 		ofstream file(tipo +".dot");
 		file<<"digraph {\n";
		Estado* r = nullptr;
		Estado* s = nullptr;
		int c1;
		file<<"rankdir = LR;"<<endl;
		file<<"size = "<<'"'<<8<<',' <<'5'<<'"'<<endl;

		file<<"node [shape = doublecircle];"<<Es_aceptacion[0]->id<<';'<<endl;
		file<<"node [shape = point];" <<'i'<< ';'<<endl;
		file<<"node [shape = circle];"<<endl;	
		file<<"i->"<<Es_Inicial->id<<';'<<endl;


		for(Transicion  trans : Transiciones){
			tie(r,c1,s) = trans;
			file<<r->id<<"->"<<s->id<<"[	label = "<<c1<<"]"<<";\n";

		}
 		file<<"}";
 		file.close();
 		string comando = "dot -Tjpg " + name + ".dot -o" + name + ".jpg";
		const char * c  =  comando.c_str();
		system(c);

	}

};
class AFND_to_AFD
{
public:
	int 		tmp_Estado;
	Automata 	_ANFD;
	Automata 	AFD; 
public:
	AFND_to_AFD(string inFile, string outFile){
		Automata ANFD(inFile);
		this->_ANFD = ANFD;
		tmp_Estado = 0;
		list<Estado* > Pila;
		//cout<<"es inicial"<<ANFD.Es_Inicial->id<<endl;
		this->AFD.Es_Inicial = new Estado(tmp_Estado, ANFD.E_clausura({ANFD.Es_Inicial}));
		//cout<<"Estado inicial de AFD" << AFD.Es_Inicial->cadenaSubConjunto;
		this->AFD.Con_Estadodos.push_back(this->AFD.Es_Inicial);
		this->AFD.Entradas = ANFD.Entradas;
		//cout<<AFD.Entradas.size()<<endl;
		Pila.push_front(AFD.Con_Estadodos.back());
	    Estado * actual = nullptr;
	    Estado * temp = nullptr;

	    tmp_Estado++; 

	    while(!Pila.empty()){
	    	actual = Pila.front();
	    	//cout<<"Actual"<<actual->id<<endl;
	    	Pila.pop_front();

	    	for(int entrada : ANFD.Entradas){
	    		vector<Estado* > subConjunto = ANFD.E_clausura(ANFD.findTransiciones(actual->subEstados,entrada));
	    		//cout<<subConjunto[2]->id<<endl;
	    		if(!subConjunto.empty()){
	    			temp = AFD.findSub_Conjunto(subConjunto);
	    			//cout<<temp<<endl;
	    			if(temp == nullptr){
	    				temp = new Estado(tmp_Estado,subConjunto);
	    				tmp_Estado++;
	    				AFD.Con_Estadodos.push_back(temp);
	    				Pila.push_front(temp);
	    			}
	    			AFD.Transiciones.push_back(make_tuple(actual,entrada,temp));
	    			actual->transiciones.push_back(make_tuple(nullptr,entrada,temp));
	    		}
	    	}
	    }
	    Acc_E_Aceptacion();
	    ofstream out(outFile.c_str());
	    AFD.OutFileAutomta(out,true);
	    AFD.Graficar("AFD");
	    _ANFD.Graficar("AFND");
	}
	void Acc_E_Aceptacion(){
		for(Estado * estado : this->AFD.Con_Estadodos ){
			for(Estado * conj_estados : estado->subEstados){
				if(_ANFD.Estado_Aceptacion(conj_estados->id)){
					AFD.Es_aceptacion.push_back(estado);
					break;
				}
			}
		}

	}
	
};

int main()
{
	string 			inFile = "in.txt";
	string 			outFile = "OUT.txt";
	AFND_to_AFD 	prueba(inFile,outFile);
	return 0;
	
}