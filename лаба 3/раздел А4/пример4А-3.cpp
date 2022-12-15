/*Бажанова Надежда, 7 группа
Условие: Задано натуральное число. Проверить, является ли заданное натуральное число палиндромом.*/
#include <iostream>
using namespace std;
int main() {
	int n;
	int D10 = 10;
	cout << "enter the number from 0 to 2147483647: ";
	cin >> n;
	int count = 0;
	int res = 0, k;
	int c1=0;
	_asm {
		mov eax, n
		m1 : cmp eax, 0
		je end1
		xor edx, edx
		mov ebx, D10
		div ebx
		push edx
		inc count
		jmp m1
		end1: 
		mov ebx, count
			m4: mov ecx, count
			cmp c1, ecx
			je end2
		sub ecx, ebx
			mov eax, 1
		cmp ecx, 0
		je m3
		m2: mul D10
		loop m2
		m3: xor edx, edx
		pop edx
		mul edx
		add res, eax
		dec ebx
		inc c1
		jmp m4
			end2: mov eax, res
			cmp eax, n
			je t1
			mov k, 0
			jmp end3
			t1: mov k, 1
			end3:
	}
	cout <<" 1 - a palindrome, 0 - not a palindrome.\nAnswer: " << k;
	return 0;
}