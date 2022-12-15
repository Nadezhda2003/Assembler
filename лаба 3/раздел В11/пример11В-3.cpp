/*�������� �������, 7 ������
�������: � ������������� �����������  ������  ����� � n-�� ������� ��������� (2<=n<=9) ����� ���������� ���� */
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
    cout << "\n�������� ������� ���������, � ������� ����� ���������, � �������:\n";
    cout << "  2-�������� �/�;      3-��������;     4-������������ �/�;   5-���������� �/�;\n6-����������� �/�;  7-���������� �/�;  8-������������ �/�;  9-������������ �/�.\n";
    cout << "��� �������:\nESCAPE, ����� ��������� ���������;  SPACE, ����� ������ ����� �����.\n";
}
void menu2() {
    cout << "\nH������:\nBACKSPACE, ����� ������� �������� ��������;\nENTER, ����� ��������� � ������� ����;\nESCAPE, ����� ��������� ���������\n";
}
int main()
{
    int n, n2;
    setlocale(LC_ALL, "RUS");
    cout << "������� ����� �� 0 �� 21474836: ";
    cin >> n;
    menu1();
    while (!_kbhit()) {
        switch (_getch()) {
        case 50: tr = true;
            cout << "\n���-�� ���� ����� " << n << " � �������� �/�: " << convert(n, 2)<<endl;
            menu2();
            while (!_kbhit() && tr) {
                switch (_getch()) {
                case 8: cout << "\n��� �������� ���������� ������ ����� �� 0 �� 100: ";
                    cin >> n2;
                    cout << "\n��������� ��������\n����� " << n2 << " � �������� �/�: " << provercaconvert(n2, 2) << endl;
                    cout << "���-�� ���� � �������� �/�: " << convert(n2, 2)<<endl;
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
            cout << "\n���-�� ���� ����� " << n << " � �������� �/�: " << convert(n, 3) << endl;
            menu2();
            while (!_kbhit() && tr) {
                switch (_getch()) {
                case 8: cout << "\n��� �������� ���������� ������ ����� �� 0 �� 100: ";
                    cin >> n2;
                    cout << "\n��������� ��������\n����� " << n2 << " � �������� �/�: " << provercaconvert(n2, 3) << endl;
                    cout << "���-�� ���� � �������� �/�: " << convert(n2, 3) << endl;
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
            cout << "\n���-�� ���� ����� " << n << " � ������������ �/�: " << convert(n, 4) << endl;
            menu2();
            while (!_kbhit() && tr) {
                switch (_getch()) {
                case 8: cout << "\n��� �������� ���������� ������ ����� �� 0 �� 100: ";
                    cin >> n2;
                    cout << "\n��������� ��������\n����� " << n2 << " � ������������ �/�: " << provercaconvert(n2, 4) << endl;
                    cout << "���-�� ���� � ������������ �/�: " << convert(n2, 4) << endl;
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
            cout << "\n���-�� ���� ����� " << n << " � ���������� �/�: " << convert(n, 5) << endl;
            menu2();
            while (!_kbhit() && tr) {
                switch (_getch()) {
                case 8: cout << "\n��� �������� ���������� ������ ����� �� 0 �� 100: ";
                    cin >> n2;
                    cout << "\n��������� ��������\n����� " << n2 << " � ��������� �/�: " << provercaconvert(n2, 5) << endl;
                    cout << "���-�� ���� � ���������� �/�: " << convert(n2, 5) << endl;
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
            cout << "\n���-�� ���� ����� " << n << " � ����������� �/�: " << convert(n, 6) << endl;
            menu2();
            while (!_kbhit() && tr) {
                switch (_getch()) {
                case 8: cout << "\n��� �������� ���������� ������ ����� �� 0 �� 100: ";
                    cin >> n2;
                    cout << "\n��������� ��������\n����� " << n2 << " � ����������� �/�: " << provercaconvert(n2, 6) << endl;
                    cout << "���-�� ���� � ����������� �/�: " << convert(n2, 6) << endl;
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
            cout << "\n���-�� ���� ����� " << n << " � ���������� �/�: " << convert(n, 7) << endl;
            menu2();
            while (!_kbhit() && tr) {
                switch (_getch()) {
                case 8: cout << "\n��� �������� ���������� ������ ����� �� 0 �� 100: ";
                    cin >> n2;
                    cout << "\n��������� ��������\n����� " << n2 << " � ���������� �/�: " << provercaconvert(n2, 7) << endl;
                    cout << "���-�� ���� � ���������� �/�: " << convert(n2, 7) << endl;
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
            cout << "\n���-�� ���� ����� " << n << " � ������������ �/�: " << convert(n, 8) << endl;
            menu2();
            while (!_kbhit() && tr) {
                switch (_getch()) {
                case 8: cout << "\n��� �������� ���������� ������ ����� �� 0 �� 100: ";
                    cin >> n2;
                    cout << "\n��������� ��������\n����� " << n2 << " � ������������ �/�: " << provercaconvert(n2, 8) << endl;
                    cout << "���-�� ���� � ������������ �/�: " << convert(n2, 8) << endl;
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
            cout << "\n���-�� ���� ����� " << n << " � ������������ �/�: " << convert(n, 9) << endl;
            menu2();
            while (!_kbhit() && tr) {
                switch (_getch()) {
                case 8: cout << "\n��� �������� ���������� ������ ����� �� 0 �� 100: ";
                    cin >> n2;
                    cout << "\n��������� ��������\n����� " << n2 << " � ������������ �/�: " << provercaconvert(n2, 9) << endl;
                    cout << "���-�� ���� � ������������ �/�: " << convert(n2, 9) << endl;
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