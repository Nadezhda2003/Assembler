/*Бажанова Надежда, 7 группа
Условие: В представлении десятичного  целого  числа в n-ой системе счисления (2<=n<=9) найти количество цифр */
#include <iostream>
#include <conio.h>
using namespace std;
bool tr = true;
int provercaconvert(int n, int base) {
    int res=0, count=0, D10=10;
    _asm {
        mov eax, n
        mov ebx, base
        m1: cmp eax, 0
        jle end1
        xor edx, edx
        div ebx
        push edx
        inc count
        jmp m1
        end1: mov ecx, count
        cmp ecx, 0
        je end2
        mov eax, 0
        m2: xor ebx, ebx
        pop ebx
        add eax, ebx
        cmp ecx, 1
        je end2
        mul D10
        loop m2
        end2: mov res, eax
    }
    return res;
}
int convert(int n, int base) {
    int count = 0;
    _asm {
        mov eax, n
        mov ebx, base
        m1 : cmp eax, 0
        jle end1
        xor edx, edx
        div ebx
        inc count
        jmp m1
        end1:
    }
    return count;
}
void menu1() {
    cout << "\nВыберите систему счисления, в которую нужно перевести, и нажмите:\n";
    cout << "  2-двоичная с/с;      3-троичная;     4-четвертичная с/с;   5-пятеричная с/с;\n6-шестеричная с/с;  7-семеричная с/с;  8-восьмеричная с/с;  9-девятиричная с/с.\n";
    cout << "Или нажмите:\nESCAPE, чтобы завершить программу;  SPACE, чтобы ввести новое число.\n";
}
void menu2() {
    cout << "\nHажмите:\nBACKSPACE, чтобы сделать проверку перевода;\nENTER, чтобы вернуться в главное меню;\nESCAPE, чтобы завершить программу\n";
}
int main()
{
    int n, n2;
    setlocale(LC_ALL, "RUS");
    cout << "Введите число от 0 до 21474836: ";
    cin >> n;
    menu1();
    while (!_kbhit()) {
        switch (_getch()) {
        case 50: tr = true;
            cout << "\nКол-во цифр числа " << n << " в двоичной с/с: " << convert(n, 2)<<endl;
            menu2();
            while (!_kbhit() && tr) {
                switch (_getch()) {
                case 8: cout << "\nДля проверки необходимо ввести число от 0 до 100: ";
                    cin >> n2;
                    cout << "\nРезультат проверки\nЧисло " << n2 << " в двоичной с/с: " << provercaconvert(n2, 2) << endl;
                    cout << "Кол-во цифр в двоичной с/с: " << convert(n2, 2)<<endl;
                    menu2();
                    break; //backspace
                case 13: menu1();
                    tr=false;
                    break; //enter
                case 27: return 0; //escape
                }
            }
            break;//2
        case 51: tr = true;
            cout << "\nКол-во цифр числа " << n << " в троичной с/с: " << convert(n, 3) << endl;
            menu2();
            while (!_kbhit() && tr) {
                switch (_getch()) {
                case 8: cout << "\nДля проверки необходимо ввести число от 0 до 100: ";
                    cin >> n2;
                    cout << "\nРезультат проверки\nЧисло " << n2 << " в троичной с/с: " << provercaconvert(n2, 3) << endl;
                    cout << "Кол-во цифр в троичной с/с: " << convert(n2, 3) << endl;
                    menu2();
                    break; //backspace
                case 13: menu1();
                    tr = false;
                    break; //enter
                case 27: return 0; //escape
                }
            }
            break;//3
        case 52: tr = true;
            cout << "\nКол-во цифр числа " << n << " в четвертичной с/с: " << convert(n, 4) << endl;
            menu2();
            while (!_kbhit() && tr) {
                switch (_getch()) {
                case 8: cout << "\nДля проверки необходимо ввести число от 0 до 100: ";
                    cin >> n2;
                    cout << "\nРезультат проверки\nЧисло " << n2 << " в четвертичной с/с: " << provercaconvert(n2, 4) << endl;
                    cout << "Кол-во цифр в четвертичной с/с: " << convert(n2, 4) << endl;
                    menu2();
                    break; //backspace
                case 13: menu1();
                    tr = false;
                    break; //enter
                case 27: return 0; //escape
                }
            }
            break;//4
        case 53: tr = true;
            cout << "\nКол-во цифр числа " << n << " в пятеричной с/с: " << convert(n, 5) << endl;
            menu2();
            while (!_kbhit() && tr) {
                switch (_getch()) {
                case 8: cout << "\nДля проверки необходимо ввести число от 0 до 100: ";
                    cin >> n2;
                    cout << "\nРезультат проверки\nЧисло " << n2 << " в пятеричой с/с: " << provercaconvert(n2, 5) << endl;
                    cout << "Кол-во цифр в пятеричной с/с: " << convert(n2, 5) << endl;
                    menu2();
                    break; //backspace
                case 13: menu1();
                    tr = false;
                    break; //enter
                case 27: return 0; //escape
                }
            }
            break;//5
        case 54: tr = true;
            cout << "\nКол-во цифр числа " << n << " в шестеричной с/с: " << convert(n, 6) << endl;
            menu2();
            while (!_kbhit() && tr) {
                switch (_getch()) {
                case 8: cout << "\nДля проверки необходимо ввести число от 0 до 100: ";
                    cin >> n2;
                    cout << "\nРезультат проверки\nЧисло " << n2 << " в шестеричной с/с: " << provercaconvert(n2, 6) << endl;
                    cout << "Кол-во цифр в шестеричной с/с: " << convert(n2, 6) << endl;
                    menu2();
                    break; //backspace
                case 13: menu1();
                    tr = false;
                    break; //enter
                case 27: return 0; //escape
                }
            }
            break;//6
        case 55: tr = true;
            cout << "\nКол-во цифр числа " << n << " в семеричной с/с: " << convert(n, 7) << endl;
            menu2();
            while (!_kbhit() && tr) {
                switch (_getch()) {
                case 8: cout << "\nДля проверки необходимо ввести число от 0 до 100: ";
                    cin >> n2;
                    cout << "\nРезультат проверки\nЧисло " << n2 << " в семеричной с/с: " << provercaconvert(n2, 7) << endl;
                    cout << "Кол-во цифр в семеричной с/с: " << convert(n2, 7) << endl;
                    menu2();
                    break; //backspace
                case 13: menu1();
                    tr = false;
                    break; //enter
                case 27: return 0; //escape
                }
            }
            break;//7
        case 56: tr = true;
            cout << "\nКол-во цифр числа " << n << " в восьмеричной с/с: " << convert(n, 8) << endl;
            menu2();
            while (!_kbhit() && tr) {
                switch (_getch()) {
                case 8: cout << "\nДля проверки необходимо ввести число от 0 до 100: ";
                    cin >> n2;
                    cout << "\nРезультат проверки\nЧисло " << n2 << " в восьмеричной с/с: " << provercaconvert(n2, 8) << endl;
                    cout << "Кол-во цифр в восьмеричной с/с: " << convert(n2, 8) << endl;
                    menu2();
                    break; //backspace
                case 13: menu1();
                    tr = false;
                    break; //enter
                case 27: return 0; //escape
                }
            }
            break;//8
        case 57: tr = true;
            cout << "\nКол-во цифр числа " << n << " в девятиричной с/с: " << convert(n, 9) << endl;
            menu2();
            while (!_kbhit() && tr) {
                switch (_getch()) {
                case 8: cout << "\nДля проверки необходимо ввести число от 0 до 100: ";
                    cin >> n2;
                    cout << "\nРезультат проверки\nЧисло " << n2 << " в девятиричной с/с: " << provercaconvert(n2, 9) << endl;
                    cout << "Кол-во цифр в девятиричной с/с: " << convert(n2, 9) << endl;
                    menu2();
                    break; //backspace
                case 13: menu1();
                    tr = false;
                    break; //enter
                case 27: return 0; //escape
                }
            }
            break;//9
        case 32: cin >> n;
            menu1();
            break;//space
        case 27: return 0; //escape
        }
    }
}