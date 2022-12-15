/*�������� �������, 7 ������
�������: ������ ������������� ������������������ A=(ai), i=1..n, n<=100.   
������� ������� ������������������ � ��� �������, � ������� ��������������� �� �������� �������� ��������� ������������������.*/
#include <iostream>
#include <conio.h>
using namespace std;
int main() {
	int* a, * b;
	int n;
	setlocale(LC_ALL, "RUS");
	cout << "������� ����������� �������. n �� [1, 214483647]. n=";
	cin >> n;
	a = new int[n];
	b = new int[n];
	cout << "������� 1, ����� � ������ ������ �������� �������.\n������� 2, ����� �������� ������� ����������� ��������� �������.\n";
	if (!_kbhit()) {
		switch (_getch()) {
		case 49: cout << "������� �������� �������, ������� ����������� [0, 2147483647].\n";
			for (int i = 0; i < n; i++) {
				cin >> a[i];
				b[i] = i + 1;
			}
			break;
		case 50: for (int i = 0; i < n; i++) {
			a[i] = rand() % 100;
			b[i] = i + 1;
		} break;
		}
	}
	cout << "���������� ������\n";
	for (int i = 0; i < n; i++) cout << a[i] << " ";
	cout << endl;
	_asm {
		mov ecx, n
		dec ecx
		for1: push ecx
		mov esi, a
		mov edi, b
		for2: mov eax, [esi]
		mov edx, [edi]
		mov ebx, [esi+4]
		if1: cmp eax, ebx
		jge then
		xchg eax, [esi+4]
		mov [esi], eax
		xchg edx, [edi+4]
		mov [edi], edx
		then: add esi, 4
		add edi, 4
		endfor2: loop for2
		pop ecx
		endfor1: loop for1
	}
	cout << "�������� ������������������ �������� ��������� �������, ����� ��� �������� ��������� ������������������.\n";
	for (int i = 0; i < n; i++) cout << b[i] << " ";
	return 0;
}