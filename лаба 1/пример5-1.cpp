#include <iostream>
using namespace std;
int main()
{
    int x, y, z;
    int l, k;
    int p1, p2;
    cout << "Enter the number =";
    cin >> x >> y;
    l = exp(y - 1);
    k = abs(y - tan(x));
    z = (3 + l) / (1 + (x*x)* k);
    cout << "Answer:" << z << endl;
    _asm
    {
        mov eax, l
        mov edx, 0
        mov ebx, 3
        add eax, ebx
        mov p1, eax
        mov eax, x
        mov edx, 0
        mul eax
        mul k
        mov ebx, 1
        add eax, ebx
        mov p2, eax
        mov eax, p1
        mov ebx, p2
        div ebx
        mov z, eax
    }
    cout << "asm1= " << z << endl;
    return 0;
}