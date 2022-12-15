/*Бажанова Надежда, 7 группа
Условие: Можно ли коробку размером A x B x C упаковать в посылку размером X x Y x Z? 
При упаковке каждая грань коробки должна быть параллельна какой-то грани посылки.
Дополнение: Считала,что если размер коробки и посылки совпадают, то коробка не влезет в посылку.*/
#include <iostream>
using namespace std;
int main() {
	int a, b, c, x, y, z;
	int res;
	cout << "enter the size of the box: ";
	cin >> a >> b >> c;
	cout << "enter the package size: ";
	cin >> x >> y >> z;
	if ((a < x && b < y && c < z) || (a < x && b < z && c < y) || (a < y && b < x && c < z) || (a < y && b < z && c < y) || (a < z && b < x && c < y) || (a < z && b < y && c < x))
		res = 1;
	else res = 0;
	cout << "0 - no, 1 - yes: " << res << endl;
	_asm {
		mov eax, a;
		mov ebx, b;
		mov edx, c;
		cmp eax, x
		jl sr1x
		jge els1x
			sr1x: cmp ebx, y
			jl sr2x
			jge els2x
			sr2x: cmp edx, z
			jl ans1
			jge ans2
			els2x: cmp ebx, z
			jl sr3x
			jge els3x
			sr3x: cmp edx, y
			jl ans1
			jge ans2
			els3x: jmp ans2
		els1x: cmp eax, y
			jl sr1y
			jge els1y
			sr1y: cmp ebx, x
			jl sr2y
			jge els2y
			sr2y: cmp edx, z
			jl ans1
			jge ans2
			els2y: cmp ebx, z
			jl sr3y
			jge els3y
			els3y: jmp ans2
			sr3y: cmp edx, x
			jl ans1
			jge ans2
		els1y: cmp eax, z
			jl sr1z
			jge els1z
			sr1z: cmp ebx, x
			jl sr2z
			jge els2z
			sr2z: cmp edx, y
			jl ans1
			jge ans2
			els2z: cmp ebx, y
			jl sr3z
			jge els3z
			sr3z: cmp edx, x
			jl ans1
			jge ans2
			els3z: jmp ans2
			els1z: jmp ans2
		ans1: mov res, 1
		jmp end1
		ans2: mov res, 0
		jmp end1
		end1:
	}
	cout << "asm answer: " << res << endl;
	return 0;
}