/*�������� �������, 7 ������
�������: ���� ����������� ����� n � k, n > 1.  ����������  k ���������� ������ ����� 1/n.
(��� ������� ���� ���������� ����������  ���������� �� �� ���, ������� �� �������� ������� � �������.) 
��������� ������ ������������ ������ ����� ����������.*/
#include <iostream>
using namespace std;
void print(int a) {
	cout << a;
}
int main() {
	int a, k1;
	int n, k, d10 = 10;
	setlocale(LC_ALL, "RUS");
	cout << "������� ����������� ����� 1/n. n ����������� ���������� (1, 2147483647]: n=";
	cin >> n;
	cout << "������� ���-�� ������ ����� �������, ������� ����� �������.\nk ����������� (0, 2147483647]. k=";
	cin >> k;
	cout << "������ "<<k<<" ���������� ������ ����� 1/"<<n<<": ";
	_asm {
		mov eax, 1
		mov ecx, k
		m1 : mul d10
		xor edx, edx
		div n
		mov a, edx
		mov k1, ecx
		push eax
		call print
		pop edx
		mov eax, a
		mov ecx, k1
		loop m1
	}
	return 0;
}