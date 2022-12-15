/*Бажанова Надежда, 7 группа
Условие: Даны  два неубывающих массива X=(xi),i=1..n, n<=10,  и Y=(yi),i=1..m, m<=10.
Найти  количество  общих элементов в этих массивах (т. е. количество тех целых t, для которых  t = xi = yj  для некоторых i и j).
(Число действий порядка m+n.)*/
#include <iostream>
#include <conio.h>
using namespace std;
int main() {
	int n, m;
	int* a, * b;
	int l = 0, k = 0, res = 0;
	setlocale(LC_ALL, "RUS");
	cout << "Введите размерность первого массива. n из [1, 10]. n=";
	cin >> n;
	a = new int[n];
	cout << "Введите элементы первого массива, которые принадлежат [0, 2147483647].\n";
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << "Введите размерность второго массива. m из [1, 10]. m=";
	cin >> m;
	b = new int[m];
	cout << "Введите элементы второго массива, которые принадлежат [0, 2147483647].\n";
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	_asm {
		mov eax, n
		mov ecx, m
		mov esi, a
		mov edi, b
		wh1 : cmp k, eax
		je end1
		cmp l, ecx
		je end1
		if1 : mov ebx, [edi]
		cmp [esi], ebx
		jge else1
		inc k
		add esi, 4
		jmp wh1
		else1 :cmp [esi], ebx
		jle else2
		inc l
		add edi, 4
		jmp wh1
		else2 : inc k
		inc l
		inc res
		add esi, 4
		add edi, 4
		jmp wh1
		end1 :
	}
	cout << "Кол-во общих элементов: " << res;
	return 0;
}