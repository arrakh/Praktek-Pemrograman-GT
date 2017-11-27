#include <iostream>
using namespace std;

int Mult(int a){
	return 2*a;
}
int main(){
	for(int i = 1; i <= 15; i++){
		cout << Mult(i) << " ";
	}
}
