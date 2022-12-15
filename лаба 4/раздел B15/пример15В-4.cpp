/*Бажанова Надежда, 7 группа
Условие: Задана  последовательность   A=(ai),  i=1..n, n<=100.
Найти элемент, который повторяется наибольшее количество  раз и количество его повторений.*/
#include <iostream>
#include <conio.h>
using namespace std;
int main () {
	int* a;
	int n, d4=4, imax=0, max=0, x;
	setlocale(LC_ALL, "Rus");
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
	_asm {
		mov ecx, n
		dec ecx
		for1 : push ecx
		mov esi, a
		for2 : mov eax, [esi]
		mov ebx, [esi + 4]
		if1 : cmp eax, ebx
		jle then
		xchg eax, [esi + 4]
		mov[esi], eax
		then : add esi, 4
		endf2 : loop for2
		pop ecx
		endf1: loop for1
		//
		mov esi, a
		mov ebx, 0
		mov ecx, n
		dec ecx
		m1: mov edx, [esi+4]
		cmp [esi], edx
		je m2
		cmp imax, ebx
		jge n1
		mov imax, ebx
		mov eax, [esi]
		mov max, eax
		n1: xor ebx, ebx
		jmp m3
		m2: inc ebx
		m3: add esi, 4
		loop m1
	}
	cout << "Максимальное кол-во повторений у числа " << max << ". Кол-во его повторений " << imax;
	return 0;
}