/*�������� �������, 7 ������
�������:���� ����������� ����� � � b, ������ b >  0.  ����� �������  �  �������  ���  ������� � �� b, �������� ���� 
� ������ ������� � �� ��������� �������� div � mod, �� �����������  �������  ��  2  ������  �����;  
�����  �����  �� ������ ������������C1*log(a/b) + C2 ��� ��������� �������� C1, C2.*/
#include <iostream>
using namespace std;
int main() {
	int a, b, b1, q, r;
	int d2 = 2;
	setlocale(LC_ALL, "RUS");
	cout << "����� ������� � ������� ��� ������� a/b.\n������� �: ";
	cin >> a;
	cout << "������� b:";
	cin>> b;
	_asm {
		mov ebx, b
		mov b1, ebx
		mov eax, b1
		mov ecx, a
		m1 : cmp eax, ecx
		jg m2
		mul d2
		jmp m1
		m2 : mov r, ecx
		mov q, 0
		m4 : cmp eax, ebx
		je m3
		xor edx, edx
		div d2
		mov b1, eax
		mov eax, q
		mul d2
		mov q, eax
		mov eax, b1
		cmp r, eax
		jl m4
		sub r, eax
		inc q
		jmp m4
		m3:
	}
	cout << "�������: "<<q << endl;
	cout<<"�������: " << r;
	return 0;
}