#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
using namespace std;

/*
			================
			Guess The Number
			================
		
		Objective:	Menebak Angka
		Win:		Berhasil Menebak Angka
		Lose:		Gagal Menebak Angka dalam 3 kali percobaan
*/


int Random(int limit){
	srand((unsigned)time(0)); 
	return (rand()%limit)+1;
}

void NumCheck(int input, int num){
	if(input > num){
		cout << "That number is bigger than the number i'm thinking";
	}
	if(input < num){
		cout << "That number is smaller than the number i'm thinking";
	}
}

void ChangeColor(){
	system("color 0c");
	sleep(1);
	system("color 0b");
}

int main(){
	//bool Game = true;
	//while(Game){
		system("color 0f");
		cout << "GUESS THE NUMBER!!!" << endl << endl;
		int num, input, difficulty, limit;
		int health = 0;
		char yesno;
		bool guess = false;
		cout << "Choose Difficulty" << endl <<
		"1. Easy" << endl <<
		"2. Hard" << endl <<
		"3. Insane" << endl <<
		"Enter the number of the Difficulty" << endl;
	
		while (difficulty != 1 && difficulty != 2 && difficulty != 3){
			cin >> difficulty;
			switch(difficulty){
				case 1 : limit = 10;
						 health = 3; break;
				case 2 : limit = 100;
						 health = 5; break;
				case 3 : limit = 1000;
						 health = 7; break;	
			}
			
		}	
		system("color 0b");
		num = Random(limit);
		//cout << endl << num << endl;
		cout << endl << "I'm thinking of a number between 0 - "<< limit << endl;
		while(!guess && health > 0){
			cout << endl << "Number of tries left: " << health;
			cout << endl << "Guess the number im thinking" << endl;
			cout << "Input Number: ";
			cin >> input;
			if(input == num){
				guess = true;
				cout << endl << "That's the correct number!";
				system("color 0a");
			}
			else{
				health--;
				cout << endl << "That's the wrong number" << endl;
				NumCheck(input, num);
				ChangeColor();
				cout << endl;
			}
		}
		cout << endl << "The Number i was thinking is: " << num << endl;
	//	cout << "Do you want to play again? (Y/N): ";
	//	cin >> yesno;
	//	if(yesno == 'y'){
	//		Game = true;
	//	}
	//	if(yesno == 'n'){
	//		Game == false;
	//	}
	//}
}
