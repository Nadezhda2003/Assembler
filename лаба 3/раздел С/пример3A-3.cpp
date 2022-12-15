/*Бажанова Надежда, 7группа
Условие: Найти НОД и НОК двух натуральных чисел a и b.
Дополнение: программа работает и для отрицательных чисел*/
#include <iostream>
#include <conio.h>
using namespace std;
int nod(int a, int b) {
	_asm {
		mov eax, a
		mov ebx, b
		m1: cmp eax, 0
		jle end1
		cmp ebx, 0
		jle end1
		cmp eax, ebx
		jge m2
		jl m3
		m2: xor edx, edx
		div ebx
		mov eax, edx
		jmp m1
		m3: xor edx, edx
		mov ecx, eax
		mov eax, ebx
		mov ebx, ecx
		div ebx
		mov eax, edx
		jmp m1
		end1: cmp a, 0
		je end2
		mov a, eax
		end2: mov a, ebx
	}
	return a;
}
int nok(int a, int b) {
	int res, c;
	c = nod(a, b);
	_asm {
		mov eax, a
		xor edx, edx
		div c
		mul b
		mov res, eax
	}
	return res;
}
int main (){
	int a, b;
	cout << "enter two numbers from 0 to 2147483647: ";
	cin >> a >> b;
	cout << "press 1 to see the NOD, press 2 to see the NOK;\npress ENTER to finish the program";
	while (!_kbhit()) { //ожидание нажатия клавиши
		switch (_getch()) {//считывает символ на нажатой клавише
		case 49: cout << "\n\nNOD: " << nod(a, b); 
			cout << "\n\npress 1 to see the NOD, press 2 to see the NOK;\npress ENTER to finish the program";
			break;
		case 50: cout << "\n\nNOK: " << nok(a, b);
			cout << "\n\npress 1 to see the NOD, press 2 to see the NOK;\npress ENTER to finish the program";
			break;
		case 13: return 0;
		}
	}
}