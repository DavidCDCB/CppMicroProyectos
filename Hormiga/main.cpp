#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <fstream>
#include<windows.h>

//si está en blanca deja una negra avanza y 90 iz
//si está en negra deja una negra avanza y 90 de

using namespace std;

void vMatriz(void);

int dimMatriz=25;
string matriz[25][25];
string pos;
int ci=12,cj=12;

int verificar(int v){
	if(v>=0 && v<dimMatriz){
		return v;
	}else{
		if(v<0) return dimMatriz-1;
		if(v=dimMatriz) return 0;
	}
	return v;
}

void movimiento(){
	
	if(pos=="d"){
		if(matriz[ci][cj]=="0"){
			matriz[ci][cj]="1";
			pos="a";
		}else{
			matriz[ci][cj]="0";
			pos="r";
		}
		cj=verificar(cj+1);
		
	}else
	
	if(pos=="a"){
		if(matriz[ci][cj]=="0"){
			matriz[ci][cj]="1";
			pos="i";
		}else{
			matriz[ci][cj]="0";
			pos="d";
		}
		ci=verificar(ci-1);
		
	}else
	
	if(pos=="i"){
		if(matriz[ci][cj]=="0"){
			matriz[ci][cj]="1";
			pos="r";
		}else{
			matriz[ci][cj]="0";
			pos="a";
		}
		cj=verificar(cj-1);
	}else
	
	if(pos=="r"){
		if(matriz[ci][cj]=="0"){
			matriz[ci][cj]="1";
			pos="i";
		}else{
			matriz[ci][cj]="0";
			pos="d";
		}
		ci=verificar(ci+1);
	}
	
	vMatriz();
}

void print(string msg){
	cout << msg << endl;
}

void cMatriz(){
	for (int i=0;i<dimMatriz;i++){
		for (int j=0;j<dimMatriz;j++){
			matriz[i][j]="0";
		}
	}
}

void clear() {
    COORD topLeft  = { 0, 0 };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(
        console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    FillConsoleOutputAttribute(
        console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
        screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    SetConsoleCursorPosition(console, topLeft);
}


void vMatriz(){
	string cad="";
	cad+="----------------------------------------------------\n";
	//cout << "----------------------------------------------------" << endl;
	for (int i=0;i<dimMatriz;i++){
		//cout << "|";
		cad+="|";
		for (int j=0;j<dimMatriz;j++){
			if(i==ci && j==cj){
				cad+="* ";
				//cout << "*" << " " ;
			}else{
				if(matriz[i][j]=="0"){
					//cout << "  ";
					cad+="  ";
				}else 
				if(matriz[i][j]=="1"){
					cad+=static_cast<char>(178);
					cad+=static_cast<char>(178);
					//printf("%c%c",178,178);
				}
			}
		}
		cad+="|\n";
		//cout << "|" << endl;
	}
	//cout << "----------------------------------------------------" << endl;
	cad+="----------------------------------------------------\n";
	
	
	cout << cad;
	Sleep(50);
	clear();
}

string setPos(){
	srand((int) time(0));
	int p = rand()%(4);
	string dir[4]={"r","d","a","i"};
	return dir[p];
}

void setCoo(){
	srand((int) time(0));
	ci=rand()%(dimMatriz-1);
	cj=rand()%(dimMatriz-1);
}

int main(int argc, char** argv) {
	int nCel=0;
	system("color f0");
	cMatriz();	
	srand((int) time(0));
	cout << "Ingrese numero de celdas pre-marcadas: ";
	cin >> nCel;
	pos=setPos();
	setCoo();
	
	for (int j=0;j<nCel;j++){
		matriz[rand()%(dimMatriz)][rand()%(dimMatriz)]="1";
	}
	
	while(true){
		movimiento();
	}
	
	return 0;
}

