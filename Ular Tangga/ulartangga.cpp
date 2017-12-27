#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include <Windows.h>
#include <String.h>

#define kiri -1
#define kanan 1

using namespace std;


//================= INISIALISASI VARIABEL =============================

bool menang = false;
int jumlahplayer;

//=====================================================================



//========================= COLORS =====================================

HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
int color(int a){
	switch(a){
		//WHITE
		case 0:
			SetConsoleTextAttribute(h,0x0001|0x0002|0x0004);
			break;
		//BLUE
		case 1:
			SetConsoleTextAttribute(h,0x0001|0x0008);
			break;
		//GREEN	
		case 2:
			SetConsoleTextAttribute(h,0x0002|0x0008);
			break;
		//RED
		case 3:
			SetConsoleTextAttribute(h,0x0004|0x0008);
			break;
		//CYAN	
		case 4:
			SetConsoleTextAttribute(h,0x0001|0x0002|0x0008);
			break;
		//YELLOW	
		case 5:
			SetConsoleTextAttribute(h,0x0002|0x0004|0x0008);
			break;
		//PINK	
		case 6:
			SetConsoleTextAttribute(h,0x0004|0x0001|0x0008);
			break;
		//DARK BLUE
		case 7:
			SetConsoleTextAttribute(h,0x0001);
			break;
		//DARK GREEN	
		case 8:
			SetConsoleTextAttribute(h,0x0002);
			break;
		//DARK RED
		case 9:
			SetConsoleTextAttribute(h,0x0004);
			break;
		//DARK CYAN	
		case 10:
			SetConsoleTextAttribute(h,0x0001|0x0002);
			break;
		//DARK YELLOW	
		case 11:
			SetConsoleTextAttribute(h,0x0002|0x0004);
			break;
		//DARK PINK	
		case 12:
			SetConsoleTextAttribute(h,0x0004|0x0001);
			break;
	}
}

//============================-o0o-=======================================



//============================= PLAYER ===================================

struct posisi{
	int x;
	int y;
};

struct player{
	
	int arah = kanan;
	posisi pos;
	string nama;
	bool menang = false;
	bool aktif = false;
	
};

player p[4];

//===============================-o0o-====================================



//=========================== DADU =======================================

int dadu(){
	return (rand()%6)+1;
}

//===========================-o0o-========================================



//============================ MAP =================================================================================================================================


char map[10][41] = {
	
'=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=',
'|','2','1',' ','|','2','2',' ','|','2','3',' ','|','2','4',' ','|','2','5',' ','|','2','6',' ','|','2','7',' ','|','2','8',' ','|','2','9',' ','|','3','0',' ',' ',
'|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ',' ',
'+','-',' ','-','+','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=',
'|','2','0',' ','|','1','9',' ','|','1','8',' ','|','1','7',' ','|','1','6',' ','|','1','5',' ','|','1','4',' ','|','1','3',' ','|','1','2',' ','|','1','1',' ','|',
'|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',
'=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','+','-',' ','-','+',
' ','1',' ','o','|','2',' ',' ','|','3',' ',' ','|','4',' ',' ','|','5',' ',' ','|','6',' ',' ','|','7',' ',' ','|','8',' ',' ','|','9',' ',' ','|','1','0',' ','|',
' ','o','o','o','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',
'=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','='

};


//=============================-o0o-=================================================================================================================================


//=========================== PAWN CHECK =================================

int pawncheck(){
	
	for(int i=0; i<4; i++){
		if(p[i].aktif == false){
			switch(i){
				case 0:
					map[7][3] = ' ';
					break;
				case 1:
					map[8][3] = ' ';
					break;
				case 2:
					map[8][2] = ' ';
					break;
				case 3:
					map[8][1] = ' ';
					break;			
			}
		}
	}
	
}

//========================================================================



//============================ PRINT =====================================


void print(){
	pawncheck();
	color(0);
	cout <<"                                    FINISH\n";
	for(int a=0; a<10; a++){
		for(int b=0; b<41; b++){
			
			int c = b;
			c = c % 4;
			//Set warna hijau
			if(        ((a==1)||(a==4)||(a==7))    && c==3){
				color(2);
			}
			//Set warna merah
			else if(   ((a==2)||(a==5)||(a==8))    && c==3){
				color(3);
			}
			//Set warna cyan
			else if(   ((a==2)||(a==5)||(a==8))    && c==2){
				color(4);
			}
			//Set warna kuning
			else if(   ((a==2)||(a==5)||(a==8))    && c==1){
				color(5);
			}
			//Set warna default
			else{
				color(0);
			}
			
			cout << map[a][b];
		}
		cout << endl;
	}
	
	cout<<"START\n\n";
	for(int i = 0; i < jumlahplayer; i++){
	color(i+2);
	cout<<"Player "<<i+1<<": " << p[i].nama << endl;
	}

}



//==============================-o0o-=====================================





int main(){

//======= RANDOM SEED ============
	srand((unsigned)time(0)); 
//================================
	
	color(11);
	cout << "=============="; color(5); cout << "-o0o-"; color(11); cout << "================\n";
	cout << "----- "; color(6); cout << "Welcome to Ular Tangga!"; color(11);  cout<< " -----\n";
	cout << "===================================\n\n";
	color(6);
	cout << "Masukkan jumlah pemain (Maksimal 4 pemain): ";
	cin >> jumlahplayer;
	if (jumlahplayer > 4){
		jumlahplayer = 4;
	}
	color(4);
	cout << "\nAnda mendaftarkan " << jumlahplayer << " pemain!\n";
	
	for(int i = 0; i < jumlahplayer; i++){
		color(i+2);
		cout <<"\nMasukkan nama player ke " << i + 1 <<endl;
		cin >> p[i].nama;
		p[i].aktif = true;
	}
	cout << endl;
	system("CLS");
	print();
	

}



