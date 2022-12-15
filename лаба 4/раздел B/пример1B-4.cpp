/*Бажанова Надежда, 7 группа
Условие: Дан A=(ai) ,  i=1..n,  (n<=10), массив  и число b. Переставить  числа  в массиве  таким  образом, чтобы сначала шли  элементы,  
меньшие или равные b, а лишь затем большие b.*/
#include <iostream>
#include <conio.h>
using namespace std;
int main() {
	int* a;
	int n, b, c;
	setlocale(LC_ALL, "RUS");
	cout << "Введите размерность массива. n из [1, 2147483647]. n=";
	cin >> n;
	a = new int[n];
	cout << "Нажмите 1, чтобы в ручную ввести элементы массива.\nНажмите 2, чтобы элементы массива запомнились случайным образом.\n";
	if (!_kbhit()) {
		switch (_getch()) {
		case 49: cout << "Введите элементы массива, которые принадлежат [0, 2147483647].\n";
			for (int i = 0; i < n; i++) cin >> a[i];
			break;
		case 50: for (int i = 0; i < n; i++) a[i] = rand() % 100; break;
		}
	}
	cout << "Полученный массив\n";
	for (int i = 0; i < n; i++) cout << a[i] << " ";
	cout << endl;
	cout << "Введите число, относительно которого нужно отсортировать массив.\nb из [0, 2147483647]. b=";
	cin >> b;
	_asm {
		mov esi, a
		mov edi, a
		mov ecx, n
		dec ecx
		m1 : add edi, 4
		loop m1
		mov ebx, b
		mov ecx, n
		mov eax, 0
		n1 : cmp eax, ecx
		je end1
		cmp[esi], ebx
		jg n2
		inc eax
		add esi, 4
		jmp n1
		n2 : cmp[edi], ebx
		jl n3
		dec ecx
		sub edi, 4
		jmp n1
		n3 : mov c, eax
		mov eax, [esi]
		mov edx, [edi]
		mov[esi], edx
		mov[edi], eax
		mov eax, c
		inc eax
		dec ecx
		add esi, 4
		sub edi, 4
		jmp n1
		end1 :
	}
	cout << "Отсортированный массив относительно " << b << ":\n";
	for (int i = 0; i < n; i++) cout << a[i] << " ";
	return 0;
}