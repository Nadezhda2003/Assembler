/*Бажанова Надежда, 7 группа
Условие: Дано натуральное число n > 1. Определить длину  периода десятичной записи дроби 1/n.
Дополнительно: Период дроби равен периоду в последовательности остатков. Кроме того, в этой последовательности все 
периодически повторяющиеся все члены различны, а предпериод имеет длину не более n. 
Поэтому достаточно найти (n+1)-ый член последовательности остатков и затем минимальное k,
при котором (n+1+k)-ый член совпадает с (n+1)-ым. */
#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "RUS");
		int l = 0, r = 1;
		int l1 = 0, r1 = 1, k1 = 0, c1, d10=10;
		int c, n, k=0;
		cout << "Enter n: ";
		cin >> n; 
		while (l != n + 1) {
			r = (10 * r) % n;
			l++;
		}
		c = r;
		//c = (n+1)-ый член последовательности остатков  
		 r = (10 * r) % n;
		//r = (n+k+1)-ый член последовательности остатков  
		while (r != c) {
			r = (10 * r) % n;
			k++;
		}  
		if (c == r && r != 0) k++;
		cout << "Max period (C++): " << k << endl;
		_asm {
			mov eax, n
			inc eax
			mov ecx, eax
			mov eax, r1
			m1: cmp l1, ecx
			je m2
			mul d10
			xor edx, edx
			div n
			mov eax, edx
			inc l1
			jmp m1
			m2:  mov c1, eax
			mul d10
			xor edx, edx
			div n
			mov eax, edx
			m3: cmp c1, eax
			je m4
			mul d10
			xor edx, edx
			div n
			mov eax, edx
			inc k1
			jmp m3
			m4: cmp c1, eax
			jne end1
			cmp eax, 0
			je end1
			inc k1
			end1:
		}
		cout <<"Max period (Asm): "<< k1;
		return 0;
	}