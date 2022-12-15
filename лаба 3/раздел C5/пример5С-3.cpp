/*Бажанова Надежда, 7 группа
Условие: Даны натуральные числа n и k, n > 1.  Напечатать  k десятичных знаков числа 1/n.
(При наличии двух десятичных разложений  выбирается то из них, которое не содержит девятки в периоде.) 
Программа должна использовать только целые переменные.*/
#include <iostream>
using namespace std;
void print(int a) {
	cout << a;
}
int main() {
	int a, k1;
	int n, k, d10 = 10;
	setlocale(LC_ALL, "RUS");
	cout << "Введите знаменатель дроби 1/n. n принадлежит промежутку (1, 2147483647]: n=";
	cin >> n;
	cout << "Введите кол-во знаков после запятой, которые нужно вывести.\nk принадлежит (0, 2147483647]. k=";
	cin >> k;
	cout << "Первые "<<k<<" десятичных знаков числа 1/"<<n<<": ";
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