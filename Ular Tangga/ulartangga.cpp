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
int giliran = 1;
int roll;
char bebas;

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
//Inisialisasi 4 player
player p[4];


//===============================-o0o-====================================



//=========================== DADU ========================================

//Ini fungsi dadu berdasarkan random, akan men return nilai random sampai 6
int dadu(){
	return (rand()%6)+1;
}

//===========================-o0o-=========================================



//============================ MAP =================================================================================================================================


//Ini adalah char berisi map, ditaruh diluar main agar dapat di akses oleh segala fungsi
char map[10][41] = {
	
'/','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=',
'|','2','1',' ','|','2','2',' ','|','2','3',' ','|','2','4',' ','|','2','5',' ','|','2','6',' ','|','2','7',' ','|','2','8',' ','|','2','9',' ','|','3','0',' ',';',
'|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ',';',
'+','-',' ','-','+','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','+',
'(','2','0',' ','|','1','9',' ','|','1','8',' ','|','1','7',' ','|','1','6',' ','|','1','5',' ','|','1','4',' ','|','1','3',' ','|','1','2',' ','|','1','1',' ','|',
'(',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',
'+','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','+','-',' ','-','+',
' ','1',' ','o','|','2',' ',' ','|','3',' ',' ','|','4',' ',' ','|','5',' ',' ','|','6',' ',' ','|','7',' ',' ','|','8',' ',' ','|','9',' ',' ','|','1','0',' ',')',
' ','o','o','o','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ',')',
'=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','/'



};


//=============================-o0o-=================================================================================================================================


//=========================== PAWN CHECK =================================

//Fungsi ini mengecek apakah player itu aktif. jika tidak, maka fungsi ini mematikan bidak player
int pawncheck(){
	
	for(int i=0; i<4; i++){
		if(p[i].aktif == false){
			map[p[i].pos.y][p[i].pos.x] = ' ';
		}
	}
	
}

//========================================================================



//============================ PRINT =====================================

//Fungsi ini mem-print seluruh isi map dengan  fungsi for
void print(){
	system("CLS");
	pawncheck();
	color(0);
	cout <<"                                    FINISH\n";
	for(int a=0; a<10; a++){
		for(int b=0; b<41; b++){
			//Kode dibawa ini memasukkan "setiap kelipatan" pada variabel c dan d
			int c = b%4;
			int d = a%3;
			//Set warna hijau
			if(d==1 && c==3){
				color(2);
			}
			//Set warna merah
			else if(d==2 && c==3){
				color(3);
			}
			//Set warna cyan
			else if(d==2 && c==2){
				color(4);
			}
			//Set warna kuning
			else if(d==2 && c==1){
				color(5);
			}
			//Set warna default
			else{
				color(11);
			}
			//Kode dibawah ini mem-print isi map sesuai baris ke - a, kolom ke - b.
			cout << map[a][b];
		}
		cout << endl;
	}
	color(0);
	cout<<"START\n\n";
	//Kode dibawah ini menjabarkan player - player yang sedang bermain
	for(int i = 0; i < jumlahplayer; i++){
	color(i+2);
	cout<<"Player "<<i+1<<": " << p[i].nama << endl;
	}

}



//==============================-o0o-=====================================



//============================= GERAK ====================================

//Fungsi ini menggerakkan bidak player
void gerak(int a){
	//Di loop sebanyak angka dadu
	for(int i = 0; i < roll; i++){
		//Set posisi bidak menjadi kosong
		map[p[a].pos.y][p[a].pos.x] = ' ';
		//Jika di kiri / kanan bidak terdapat karakter ( / ), maka naikkan ke atas
		if(  (map[p[a].pos.y][p[a].pos.x+(4-(p[a].pos.x%4))] == ')')  ||  (map[p[a].pos.y][p[a].pos.x-(p[a].pos.x%4)] == '(')      ){
			//Set petak di atas menjadi bidak player
			map[p[a].pos.y-3][p[a].pos.x] = 'o';
			//Set posisi y baru dan set arah baru
			p[a].pos.y = p[a].pos.y - 3;
			p[a].arah = p[a].arah * (-1);
		}
		//Jika di kiri / kanan bidak terdapat karakter ; , maka balikkan arah bidak, jalankan, lalu balikkan arahnya lagi
		else if(  (map[p[a].pos.y][p[a].pos.x+(4-(p[a].pos.x%4))] == ';')  ||  (map[p[a].pos.y][p[a].pos.x-(p[a].pos.x%4)] == ';')      ){
			p[a].arah = p[a].arah * -1;
			for(int j=i; j<roll; j++){
				map[p[a].pos.y][p[a].pos.x] = ' ';
				map[p[a].pos.y][p[a].pos.x+(4*p[a].arah)] = 'o';
				p[a].pos.x = p[a].pos.x + (4*p[a].arah);
			}
			p[a].arah = p[a].arah * -1;
			i = roll;
			
		}
		//Jika tidak terdapat karakter apa apa maka jalankan sesuai arah
		else{
			map[p[a].pos.y][p[a].pos.x+(4*p[a].arah)] = 'o';
			p[a].pos.x = p[a].pos.x + (4*p[a].arah);	
		}

		print();
	}
}

//========================================================================



//=========================================== CHECK MENANG ======================================

//Fungsi ini mengecek jika di kanan / kiri posisi player terdapat karakter ; , maka game berakhir
void checkmenang(){
	if(  (map[p[giliran-1].pos.y][p[giliran-1].pos.x+(4-(p[giliran-1].pos.x%4))] == ';')  ||  (map[p[giliran-1].pos.y][p[giliran-1].pos.x-(p[giliran-1].pos.x%4)] == ';')      ){
		p[giliran-1].menang = true;
		menang = true;	
	}
}

//===============================================================================================



int main(){

//======= RANDOM SEED ============
	srand((unsigned)time(0)); 
//================================

	color(6);
	cout << "Masukkan jumlah pemain (Maksimal 4 pemain): ";
	cin >> jumlahplayer;
	if (jumlahplayer > 4){
		jumlahplayer = 4;
	}
	color(4);
	cout << "\nAnda mendaftarkan " << jumlahplayer << " pemain!\n";
	//Untuk memasukkan nama player
	for(int i = 0; i < jumlahplayer; i++){
		color(i+2);
		cout <<"\nMasukkan nama player ke " << i + 1 <<endl;
		cin >> p[i].nama;
		p[i].aktif = true;
	}
// Ini inisialisasi koordinat awal
//==============
p[0].pos.x = 3;
p[0].pos.y = 7;
p[1].pos.x = 3;
p[1].pos.y = 8;
p[2].pos.x = 2;
p[2].pos.y = 8;
p[3].pos.x = 1;
p[3].pos.y = 8;
//==============

	cout << endl;
	do{
		print();
		color(giliran+1);
		cout << "\nSekarang giliran " << p[giliran-1].nama <<"!";
		color(0);
		cout << "\nSilahkan ketik apapun untuk mengocok dadu!";
		cin >> bebas;	
		cout << "\n Mengocok dadu";
		usleep(100); cout << '.'; usleep(100); cout << '.'; usleep(100); cout << '.'; usleep(100); 
		roll = dadu(); color(0);
		cout << "\n\nKamu mendapatkan angka "; color(6); cout << roll; 
		sleep(1); cout << "\n\nMengerakkan...";
		gerak(giliran-1);
		checkmenang();
		//Jika belum menang, maka giliran akan tetap dilanjutkan
		if(!menang){
		
			if(giliran == jumlahplayer){
				giliran = 1;
			}
			else{
				giliran = giliran + 1;
			}
		}
	
		
	
	}while(!menang);
	system("CLS");
	color(0);
	cout << "SELAMAT, ";
	color(giliran+1);
	cout << p[giliran-1].nama;
	color(0);
	cout << " MENANG!!";

}



