#include<iostream>
#include<iomanip> //Library tambahan untuk menggunakan fungsi setw()
using namespace std;

//Fungsi ini memberi spasi agar output lebih rapih. Batas hingga ribuan.
//(int n) mengecek angka yang di input dan memberikan spasi berdasarkan angka
//Jumlah spasi dapat di atur sesuai puluhan / ratusan input
void GiveSpace(int n){
	if(n<10){
		cout << "  ";
	}
	else if(n>=10&&n<100){
		cout << " ";
	}
	else{
		cout << "";
	}
}

main() {
	int n;
	cout << "Masukkan Angka: ";
	cin >> n;
	for(int i = 1; i <= 10; i++) {
		for(int j = 0; j < i; j++) {
			cout<< n + j;
			GiveSpace(n+j);
		}
		cout<<endl;
		n += 2;
	}
}
