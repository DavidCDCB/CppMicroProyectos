/*
Uso de vector y list
https://julioecheverri.wordpress.com/2014/07/22/la-clase-vector-y-sus-metodos-mas-importantes-en-cpp-c/
https://riptutorial.com/es/cplusplus/topic/511/std----vector
https://es.wikibooks.org/wiki/Programaci%C3%B3n_en_C%2B%2B/Biblioteca_Est%C3%A1ndar_de_Plantillas/Vectores
https://es.wikibooks.org/wiki/Programaci%C3%B3n_en_C%2B%2B/Librer%C3%ADa_Est%C3%A1ndar_de_Plantillas/Listas
https://es.stackoverflow.com/questions/10985/como-acceder-a-un-elemento-dentro-de-una-lista

Documentacion de list y vector
http://www.cplusplus.com/reference/vector/vector/
http://www.cplusplus.com/reference/list/list/

Documentacion clase string
https://julioecheverri.wordpress.com/2014/07/23/el-tipo-string-y-sus-metodos-mas-importantes-en-c/
http://www.cplusplus.com/reference/string/string/
*/

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <fstream>
#include <math.h>

using namespace std;

void verArr(vector<int> arr);
void print(string msg);
void Hanoi(int n,string o,string a,string d,vector<int> lA, vector<int> lB,vector<int> lC);
void Mov(string ori,string des);
vector<int> cArr(int size,bool cer);

vector<int> lA,lB,lC;
int nTo=10;//NUMERO DE DISCOS 64;
long nMov=0,movMax=0;
string buffer="";

void verArr(vector<int> arr){
	for (int i=0;i<arr.size();i++){//uso de ForEach
		if(arr[i]!=0){
			cout << "|" << arr[i] ;
		}else{
			cout << "-" ;
		}		
	}
	cout << endl;
}

void mArr(){
	//system("cls");
	verArr(lA);
	verArr(lB);
	verArr(lC);
	cout << "Movimientos restantes:" << (movMax-nMov) << endl;
	cout << "\n\n";	
}

int main(int argc, char** argv) {
	unsigned t0, t1;
	ofstream file;
	file.open("solucion.txt");
	print("Torres de Hanoi");
	print("Ingrese numero de discos:");
	cin >> nTo;
	system("color 4F");
	
	movMax=pow(2,nTo)-1;
	
	lA=cArr(nTo,false);
	lB=cArr(nTo,true);
	lC=cArr(nTo,true);
	
	t0=clock();
	
	mArr();
	print("\nProcesando...");
	Hanoi(nTo,"A","B","C",lA,lB,lC);
	mArr();
	t1 = clock();
	double time = (double(t1-t0)/CLOCKS_PER_SEC);
	print("Costo de tiempo: "+to_string(time));
	print("Numero de movimientos: "+to_string(nMov));
	file << buffer;
	file.close();
	system("color 0a");
	system("pause");
	return 0;
}

void Hanoi(int n,string o,string a,string d,vector<int> lA, vector<int> lB,vector<int> lC){
	//buffer+=o+a+d+"\n";
	if(n==1){
		Mov(o,d);
		//buffer+=o+"->"+d+"\n";
		//mArr();
	}else{
		Hanoi(n-1,o,d,a,lA,lC,lB);
		Mov(o,d);
		//buffer+=o+"->"+d+"\n";
		//mArr();
		Hanoi(n-1,a,o,d,lB,lA,lC);
	}
	
}

int rArr(vector<int> arr,int ind){
	if(arr[0]!=0){
		for (int i=arr.size()-1;i>=0;i--){
			if(arr[i]!=0){
				return i;
			}	
		}
	}
	return -1;
}


void Mov(string ori,string des){
	nMov++;
	
	if(ori=="A" && des=="C"){
		lC[rArr(lC,0)+1]=(lA[rArr(lA,0)]);
		lA[rArr(lA,0)]=0;
		return;
	}

	if(ori=="A" && des=="B"){
		lB[rArr(lB,0)+1]=(lA[rArr(lA,0)]);
		lA[rArr(lA,0)]=0;
		return;
	}

	if(ori=="B" && des=="A"){
		lA[rArr(lA,0)+1]=(lB[rArr(lB,0)]);
		lB[rArr(lB,0)]=0;
		return;
	}

	if(ori=="B" && des=="C"){
		lC[rArr(lC,0)+1]=(lB[rArr(lB,0)]);
		lB[rArr(lB,0)]=0;
		return;
	}

	if(ori=="C" && des=="A"){
		lA[rArr(lA,0)+1]=(lC[rArr(lC,0)]);
		lC[rArr(lC,0)]=0;
		return;
	}

	if(ori=="C" && des=="B"){
		lB[rArr(lB,0)+1]=(lC[rArr(lC,0)]);
		lC[rArr(lC,0)]=0;
		return;
	}

}

vector<int> cArr(int size,bool cer){
	int dat=0;
	vector<int> arr;
	
	if(cer==false){
		dat=size;
		arr.clear();
		
		for (int i=0;i<size;i++){
			arr.push_back(dat);
			dat--;
		}
	}else{
		arr.clear();
		for (int i=0;i<size;i++){
			arr.push_back(0);
		}
	}
	return arr;
}

void print(string msg){
	cout << msg << endl;
}

