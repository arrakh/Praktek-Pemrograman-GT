#include <iostream>
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

void forward(int n){
	for(int i=n ; i > 0; i--){
		for(int o=1 ; o <= n ; o++){
			cout << i;
			GiveSpace(i);
		}
		cout << endl;
	}	
}

void backward(int n){
	for(int a=2 ; a <= n; a++){
		for(int b=1 ; b <= n ; b++){
			cout << a;
			GiveSpace(a);
		}
		cout << endl;
	}
}

int main (){
	int n;
	cout << "Masukkan Angka N: ";
	cin >> n;
	forward(n);
	backward(n);
	
}
