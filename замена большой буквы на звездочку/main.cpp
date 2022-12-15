//Баранова Анастасия, 7 группа
//Дана последовательность A=(ai), i=1..n, n<=100,  Найти  номера всех  наименьших  элементов.

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
    cin >> n; // количество элементов в массиве 
    a = new int[n];
    int k = 0; // индекс элемента 
    b = new int[n]; // копия исходного массива 
    cout << "Enter the elements of array: ";
    for (int i = 0; i < n; i++)
        cin >> a[i]; // вводим элементы массива 
    for (int i = 0; i < n; i++)
        b[i] = a[i]; // копируем элементы массива 
    ShowMinIndex(a, n, Min(a, n));
    cout << "index assembler:\n";
    _asm {
        mov ecx, n // количество элементов в регистр есх 
        dec ecx // уменьшаем на 1 
        for1 : push ecx // заталкиваем в стек 
        mov esi, b // кладём копию массива в регистр esi
        for2 : mov eax, [esi] // первый элемент массива кладём в регистр еах 
        if1 : cmp eax, [esi + 4]  // сравниваем последующий элемент с элементом массива с адресом esi 
        jle then // прыжок на метку then, если меньше или равно 
        xchg eax, [esi + 4] // меняем местами 
        mov[esi], eax // нынешний элемент массива кладём в esi 
        then : add esi, 4 // переходим к следующему элементу 
        endf2 : loop for2 // цикл, пока есх не 0 
        pop ecx // достаём из стека 
        endf1 : loop for1 // цикл, пока есх не 0 
        mov esi, b // адрес на первый элемент массива(копии) 
        mov ebx, [esi] // кладём в ebx первый элемент 
        mov edi, a // адрес на первый элемент исходного массива кладём в edi 
        mov ecx, n // количество элементов кладём в  есх 
        dec ecx // уменьшаем на 1 
        m1 : inc k // индекс элемента увеличиваем на 1 
        cmp[edi], ebx // сравниваем текущий элемент с наименьшим (он в ebx) 
        jne dq// прыжок на метку dq, если не равно 
        push ebx // заталкиваем в стек ebx
        push edi // заталкиваем в стек edi
        push ecx // заталкиваем в стек ecx
        push k
        call print // вызываем функцию принт
        pop edx
        pop ecx // выталкиваем из стека 
        pop edi // выталкиваем из стека 
        pop ebx // выталкиваем из стека 
        dq : add edi, 4 // переход к следующему элементу 
        loop m1 // цикл, пока есх не ноль 
    }
    return 0;
}