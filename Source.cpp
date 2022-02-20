#include<iostream>
using namespace std;

int PIN, a, b, c;
char YESNO;
void EnterPIN()
{
	cout << "Enter a 4 digit int PIN number: ";
	cin >> PIN;
}
void displayno()
{
	cout << PIN << " is not a valid PIN number: " << endl;
}

void displayyes()
{
	cout << PIN << " is a valid PIN number: " << endl;
}
void CONT()
{
	cout << "Do you want to try another PIN number(y/n)? ";
	cin >> YESNO;
}
int main()
{
	_asm
	{
	loop1:
		call EnterPIN;
		mov eax, PIN;
		mov ecx, 100;		// ecx = 1000
		cdq;				//PIN = edx:eax
		idiv ecx;			//a = eax, r = edx, n/1000
		mov a, eax;			//a = eax
		mov eax, edx;
		cdq;				//a = edx:eax
		mov ecx, 10;
		idiv ecx;			//edx:eax/ecx, b=eax, c= edx
		mov b, eax;
		mov c, edx;
		jmp T1;
	T1:
		cmp c, 0;
		jne next0;
	Even_1:
		call displayno;		 // If Odd Display Not Valid Pin
		jmp Des;			//Ask Cont
	Odd_1:
		call displayyes;	//If Even Diplay Valid Pin
		jmp Des;			//Ask Cont
	next0:
		cmp c, 2;			//Check #2
		jne next1;
		jmp Even_1;			//go to even
	next1:
		cmp c, 4;			//Check#4
		jne next2;
		jmp Even_1;			//go to even
	next2:
		cmp c, 6;			//check #6
		jne next3;
		jmp Even_1;			 //go to even
	next3:
		cmp c, 8;			//check #8
		jne next4;
		jmp Even_1;			//go to even
	next4:
		cmp c, 1;			//check #1
		jne next5;
		jmp Odd_1;			 //go to odd
	next5:
		cmp c, 3;			//check #3
		jne next6;
		jmp Odd_1;			 //go to odd
	next6:
		cmp c, 5;			//check#5
		jne next7;
		jmp Odd_1;			//go to odd
	next7:
		cmp c, 7;			//check #7
		jne next8;
		jmp Odd_1;			//go to odd
	next8:
		cmp c, 9;			//check #7
		je Odd_1;			//go to odd
	Des:
		call CONT;			//Ask to Cont
		cmp YESNO, 'y';		//If yes jump to loop1
		jne finish;			//if not then finish
		jmp loop1;
	finish:
	}
	system("pause");
}
/*-----------Outputs----------------------------------
Programmer: Tauney Mack
Enter a 4 digit int PIN number: 2142
2142 is not a valid PIN number:
Do you want to try another PIN number(y/n)? y
Enter a 4 digit int PIN number: 2833
2833 is a valid PIN number:
Do you want to try another PIN number(y/n)? n
Press any key to continue . . .
---------------------------------------------------------*/


