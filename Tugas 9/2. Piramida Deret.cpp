#include <iostream>
using namespace std;

int Geser(int a, int b){
	return a*b;
}

//Fungsi ini memberi spasi agar output lebih rapih. Batas hingga ribuan.
void GiveSpace(int n){
	if(n<10){
		cout << "   ";
	}
	else if(n>=10&&n<100){
		cout << "  ";
	}
	else{
		cout << " ";
	}
}

int main(){
	int n,a;
	cout << "Masukkan Jumlah Tabel: ";
	cin >> n;
	int table[n][n];
	for(int i = 1 ; i <= n ; i++){
		for(int u = 1; u <= n ; u++){
		cout << Geser(u,i);
		GiveSpace(Geser(u,i));	
		}
		cout << endl;
	}

	
}
