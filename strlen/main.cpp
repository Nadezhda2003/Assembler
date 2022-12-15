/*Бажанова Надежда, 7 группа
Программа strlen*/
#include <iostream>
#include <string>
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	int l, l1;
	string str1;
	cout << "Введите строку до 100 символов: ";
	getline(cin, str1);
	_asm {
		lea eax, str1
		push eax
		call strlen
		mov l, eax
		pop edx
	}
	cout << "Длина строки (вызов strlen): " << l << endl;
	_asm {
		xor esi, esi
		m1 : cmp str1[esi], '0'
		je end1
		inc esi
		jmp m1
		end1 : mov l1, esi
	}
	cout << "Длина строки (своя реализация): " << l1;
	return 0;
}