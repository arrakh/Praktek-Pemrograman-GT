#include <iostream>
using namespace std;

int Multiply(int a, int b){
	return a*b;
}

//Fungsi ini memberi spasi agar output rapih
void GiveSpace(int n){
	if(n<10){
		cout << "   ";
	}
	else if(n>=10&&n<100){
		cout << "  ";
	}
	else{
		cout <<" ";
	}
}

int main(){
	int n;
	cout << "Masukkan Jumlah Tabel: ";
	cin >> n;
	int table[n][n];
	for(int i=1; i<=n ; i++){
		for(int o=1; o<=i ; o++){
			cout << Multiply(o,i);
			GiveSpace(Multiply(o,i));
		}
		cout << endl;
	}
}
