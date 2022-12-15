/*Бажанова Надежда, 7 группа
Условие:Дано натуральное n. Подсчитать  количество  решений неравенства  x*x + y*y < n в натуральных (неотрицательных целых)
числах, не используя действий с вещественными числами.*/
#include <iostream>
using namespace std;
int main() {
	int k = 0, s = 0, l = 0, t = 0;
	int a;
	int n;
	cout << "enter n for x*x+y*y<n. n=";
	cin >> n;
	_asm {
		mov ecx, s
		mov ebx, n
		m1: mov eax, k
		mul k
		cmp eax, ebx
		jge end1
		mov a, eax
		mov l, 0
		mov t, 0
		m2: mov eax, l
		mul l
		add eax, a
		cmp eax, ebx
		jge m3
		inc l
		inc t
		jmp m2
		m3: inc k
		add ecx, t
		jmp m1
		end1: mov s, ecx
	}
	cout <<"number of solutions to the inequality: "<< s;
	return 0;
}