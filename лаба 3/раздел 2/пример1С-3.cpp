/*Бажанова Надежда, 7 группа
Условие: Заданы три целых числа, которые задают некоторую дату. Определить номер дня недели по заданной дате.*/
#include <iostream>
using namespace std;
int main() {
	int k, m, N, q, r, s, b, D;
	cout << "DATE FORMAT: **.**.****, when the date and/or month consists of\n a single digit: *.*.**** \nenter the day: ";
	cin >> k;
	cout << "enter the month: ";
	cin >> m;
	cout << "enter the year: ";
	cin >> N;
	_asm {
		mov eax, 14
		mov ecx, 12
		sub eax, m
		xor edx, edx
		div ecx
		mov q, eax
		mov eax, N
		sub eax, q
		mov r, eax
		mov eax, q
		mul ecx
		add eax, m
		sub eax, 2
		mov s, eax
		mov eax, 7000
		add eax, k
		add eax, r
		mov b, eax
		mov eax, r
		mov ecx, 4
		xor edx, edx
		div ecx
		add b, eax
		mov eax, r
		mov ecx, 100
		xor edx, edx
		div ecx
		sub b, eax
		mov eax, r
		mov ecx, 400
		xor edx, edx
		div ecx
		add b, eax
		mov eax, s
		mov ecx, 31
		mul ecx
		mov ebx, 12
		xor edx, edx
		div ebx
		add eax, b
		mov ecx, 7
		xor edx, edx
		div ecx
		cmp edx, 0
		je m1
		jne end1
		m1: add edx, 7
		jmp end1
		end1: mov D, edx
	}
	cout <<"1-Monday, 2-Tuesday, 3-Wednesday, 4-Thursday, 5-Friday, 6-Saturday, 7-Sunday\nAnswer: "<< D;
	return 0;
}