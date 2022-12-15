/*Бажанова Надежда, 7 группа
Условие: f(x)=x^2, при x>=2
         f(x)=4, в остальных случаях*/
#include <iostream>
using namespace std;
int main() {
	int x;
	cout << "Enter the number = ";
	cin >> x;
	int res;
	if (x >= 2) res = x * x;
	else res = 4;
	cout << "Answer: " << res << endl;
	_asm {
		mov eax, x
		cmp eax, 2
		jge l0
		jl els
		l0: mul eax
		mov res, eax
		jmp end1
		els: mov res, 4
		jmp end1
		end1:
	}
	cout << "asm answer: " << res << endl;
	return 0;
}