/*Бажанова Надежда, 7 группа
Условие: Найти количество повторений каждой цифры  у заданного натурального числа (не используя массивов)*/
#include <iostream>
using namespace std;
int main() {
	int a, a1;
	int d10 = 10;
	int z = 0, o = 0, t = 0, th = 0, f = 0, fi = 0, s = 0, se = 0, ei = 0, ni = 0;
	cout << "enter the number from 0 to 2147483647: ";
	cin >> a;
	_asm {
       mov eax, a
	   // находит кол-во каждой цифры в числе (14-69 строка)
	   m1: cmp eax, 0
	   je end_
	   xor edx, edx
	   div d10
	   mov a1, eax
	   cmp edx, 5
	   je end5
	   jl m2
	   jg els2
	   m2: cmp edx, 2
	   je end2
	   jl m3
	   jg els3
	   m3: cmp edx, 1
	   je end1
	   jl end0
	   els3: cmp edx, 3
	   je end3
	   jg end4
	   els2: cmp edx, 7
	   je end7
	   jl end6
	   jg els4
	   els4: cmp edx, 9
	   je end9
	   jl end8
	   end0: inc z
	   mov eax, a1
	   jmp m1
	   end1: inc o
	   mov eax, a1
	   jmp m1
	   end2: inc t
	   mov eax, a1
	   jmp m1
	   end3: inc th
	   mov eax, a1
	   jmp m1
	   end4: inc f
	   mov eax, a1
	   jmp m1
	   end5: inc fi
	   mov eax, a1
	   jmp m1
	   end6: inc s
	   mov eax, a1
	   jmp m1
	   end7: inc se
	   mov eax, a1
	   jmp m1
	   end8: inc ei
	   mov eax, a1
	   jmp m1
	   end9: inc ni
	   mov eax, a1
	   jmp m1
	   /* Часть программы ниже сравнивает кол - во цифр с 0, если == 0, 
	   то переходит к след.цифре, если != 0, то уменьшает эту переменную 
	   на 1 и мы получаем кол - во повторений*/
	   end_:
	   cmp z, 0
		   je g1
		   dec z
		 g1:  cmp o, 0
		   je g2
		   dec o
		  g2: cmp t, 0
		   je g3
		   dec t
		   g3: cmp th, 0 
		   je g4
		   dec th
		  g4: cmp f, 0
		   je g5
		   dec f
		  g5: cmp fi,0
		   je g6
		   dec fi
		  g6: cmp s, 0
		   je g7
		   dec s
		   g7: cmp se, 0
		   je g8
		   dec se
		   g8: cmp ei, 0
		   je g9
		   dec ei
		   g9: cmp ni, 0
		   je endp
		   dec ni
		endp:
    }
	cout <<"0: " << z << "; 1: " << o << "; 2: " << t << "; 3: " << th << "; 4: " << f << "; 5: " << fi << "; 6: " << s << "; 7: " << se << "; 8: " << ei << "; 9: " << ni;
	return 0;
	}