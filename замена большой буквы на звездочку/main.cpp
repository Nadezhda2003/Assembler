//�������� ���������, 7 ������
//���� ������������������ A=(ai), i=1..n, n<=100,  �����  ������ ����  ����������  ���������.

#include <iostream>
using namespace std;
int Min(int A[], int n)
{
    int min = A[0];
    for (int i = 1; i < n; i++)
        if (min > A[i])
            min = A[i];
    return min;
}
void ShowMinIndex(int A[], int n, int min)
{
    cout << "min elements index: " << endl;
    for (int i = 0; i < n; i++)
        if (A[i] == min)
            cout << i + 1 << ' ';
    cout << endl;
}

void print(int a) {
    cout << a << " ";
}


int main()
{
    int* a, * b, n;
    cout << "Enter the number of elements: ";
    cin >> n; // ���������� ��������� � ������� 
    a = new int[n];
    int k = 0; // ������ �������� 
    b = new int[n]; // ����� ��������� ������� 
    cout << "Enter the elements of array: ";
    for (int i = 0; i < n; i++)
        cin >> a[i]; // ������ �������� ������� 
    for (int i = 0; i < n; i++)
        b[i] = a[i]; // �������� �������� ������� 
    ShowMinIndex(a, n, Min(a, n));
    cout << "index assembler:\n";
    _asm {
        mov ecx, n // ���������� ��������� � ������� ��� 
        dec ecx // ��������� �� 1 
        for1 : push ecx // ����������� � ���� 
        mov esi, b // ����� ����� ������� � ������� esi
        for2 : mov eax, [esi] // ������ ������� ������� ����� � ������� ��� 
        if1 : cmp eax, [esi + 4]  // ���������� ����������� ������� � ��������� ������� � ������� esi 
        jle then // ������ �� ����� then, ���� ������ ��� ����� 
        xchg eax, [esi + 4] // ������ ������� 
        mov[esi], eax // �������� ������� ������� ����� � esi 
        then : add esi, 4 // ��������� � ���������� �������� 
        endf2 : loop for2 // ����, ���� ��� �� 0 
        pop ecx // ������ �� ����� 
        endf1 : loop for1 // ����, ���� ��� �� 0 
        mov esi, b // ����� �� ������ ������� �������(�����) 
        mov ebx, [esi] // ����� � ebx ������ ������� 
        mov edi, a // ����� �� ������ ������� ��������� ������� ����� � edi 
        mov ecx, n // ���������� ��������� ����� �  ��� 
        dec ecx // ��������� �� 1 
        m1 : inc k // ������ �������� ����������� �� 1 
        cmp[edi], ebx // ���������� ������� ������� � ���������� (�� � ebx) 
        jne dq// ������ �� ����� dq, ���� �� ����� 
        push ebx // ����������� � ���� ebx
        push edi // ����������� � ���� edi
        push ecx // ����������� � ���� ecx
        push k
        call print // �������� ������� �����
        pop edx
        pop ecx // ����������� �� ����� 
        pop edi // ����������� �� ����� 
        pop ebx // ����������� �� ����� 
        dq : add edi, 4 // ������� � ���������� �������� 
        loop m1 // ����, ���� ��� �� ���� 
    }
    return 0;
}