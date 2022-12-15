/*Бажанова Надежда, 7 группа
Вариант 17*/
#include <iostream>
using namespace std;
int palindrom(int n) { //переворачивает число и его возвращает
	int D10 = 10;
	int res=0;
	_asm {
		mov eax, n
		m1: cmp eax, 0
		je end1
		xor edx, edx
		div D10
		mov ebx, eax
		mov eax, edx
		add eax, res
		mul D10
		mov res, eax
		mov eax, ebx
		jmp m1
		end1: mov eax, res
		xor edx, edx
		div D10
		mov res, eax
	}
	return res;
}
int izm(int a) {
	int d10 = 10;
	int d100 = 100;
	int res;
	_asm {
		mov eax, a
		xor edx, edx
		div d100
		mov ebx, edx
		mul d10
		mov res, eax
		mov eax, ebx
		xor edx, edx
		div d10
		add res, edx
	}
	return res;
}
int odn(int a) {
	int d10 = 10;
	int k=0;
	_asm {
		mov eax, a
		mov ebx, 9
		cmp eax, ebx
		jle end1
		inc k
		end1:
	}
	return k;
}
int main() {
	int* a, n;
	cout << "n= ";
	cin >> n;
	a = new int[n];
	cout << "enter the elemets of array ";
	for (int i = 0; i < n; i++) cin >> a[i];
	_asm {
		mov ecx, n
		mov esi, a
		m1 : push ecx
		mov ebx, [esi]
		push ebx
		call odn
		pop ebx
		cmp eax, 0
		je then
		push ebx
		call palindrom
		pop ebx
		cmp eax, ebx
		jne then
		mov ebx, [esi]
		push ebx
		call izm
		pop ebx
		mov[esi], eax
		then : add esi, 4
		pop ecx
		loop m1
	}
	for (int i = 0; i < n; i++) cout << a[i] << " ";
	return 0;
}