/*Бажанова Надежда, 7 группа
Условие: Определить является ли заданное  натуральное число простым.*/
#include <iostream>
using namespace std;

int main() {
    int a;
    cout << "enter the number from 0 to 2147483647: ";
    cin >> a;
    int a1;
    int k = 1;
    _asm {
        mov eax, a
        cmp eax, 1
        jle k1 
        mov ebx, 2
        m1: mov eax, a1
        xor edx, edx
        div ebx
        cmp eax, ebx
        jle end1
        cmp edx, 0
        je k1
        inc ebx
        jmp m1
        k1 : mov k, 0
        end1 :
    }
    cout << "0 - not prime, 1- prime.\nAnswer: " << k;
}