/*Бажанова Надежда, 7 группа
Вариант 17*/
#include <iostream>
using namespace std;

int palindrom(int n) {
int D10 = 10;
int count = 0;
int res = 0, k;
int c1 = 0;
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
	end1 :
	mov ebx, count
		m4 : mov ecx, count
		cmp c1, ecx
		je end2
		sub ecx, ebx
		mov eax, 1
		cmp ecx, 0
		je m3
		m2 : mul D10
		loop m2
		m3 : xor edx, edx
		pop edx
		mul edx
		add res, eax
		dec ebx
		inc c1
		jmp m4
		end2 : mov eax, res
		cmp eax, n
		je t1
		mov k, 0
		jmp end3
		t1 : mov k, 1
		end3 :
}
return k;
}
int izm(int a) {
	int d10 = 10;
	int d100 = 100;
	int res;
	_asm {
	mov eax, a
	xor edx, edx
	div d100
	mul d10
	mov res, eax
	mov eax, a
	xor edx, edx
	div d10
	add res, edx
	}
	return res;
}
int odn(int a) {
	int d10 = 10;
	int k;
	_asm {
		mov ebx, 0
		mov eax, a
		xor edx, edx
		div d10
		cmp edx, 0
		je end1
		inc ebx
		end1: mov k, ebx
	}
	return k;
}
int main() {
	int* a, n;
	cin >> n;
	a = new int[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	_asm {
		mov esi, a
		mov ecx, n
		dec ecx
		m1: mov ebx, [esi]
		push ebx
		call odn
		pop ebx
		cmp eax, 0
		jne then
		mov ebx, [esi]
		push ebx
		call palindrom
		pop ebx
		cmp eax, 0
		je then
		mov ebx, [esi]
		push ebx
		call izm
		pop ebx
		mov [esi], eax
		then: add esi, 4
		loop m1
	}
	for (int i=0; i<n; i++) cout<<a[i]<<" ";
	return 0;
}