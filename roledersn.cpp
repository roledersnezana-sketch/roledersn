#include <iostream>
#include <bitset>
#include <clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    //Задание 1
    cout << "=== Задание 1 ===" << endl;

    cout << "bool        - " << sizeof(bool) << " - логический тип (true/false)" << endl;
    cout << "char        - " << sizeof(char) << " - один символ" << endl;
    cout << "short int   - " << sizeof(short int) << " - короткое целое число" << endl;
    cout << "int         - " << sizeof(int) << " - обычное целое число" << endl;
    cout << "long int    - " << sizeof(long int) << " - длинное целое 4 байта в Windows" << endl;
    cout << "long long   - " << sizeof(long long) << " - очень длинное целое число" << endl;
    cout << "float       - " << sizeof(float) << " - дробное число одинарной точности" << endl;
    cout << "double      - " << sizeof(double) << " - дробное число двойной точности" << endl;
    cout << "long double - " << sizeof(long double) << " - дробное число расширенной точности" << endl;
    cout << endl;

    //Задание 2
    cout << "=== Задание 2 ===" << endl;

    int a;
    cout << "Число: ";
    cin >> a;

    int order_i = sizeof(int) * 8;
    unsigned int mask_i = 1u << (order_i - 1);

    for (int i = 0; i < order_i; i++) {
        cout << ((a & (mask_i >> i)) ? '1' : '0');

        if (i == 0) {
            cout << "  ";
        }
    }
    cout << endl;

    ///Задание 3
    cout << endl << "=== Задание 3 ===" << endl;
    union {
        float f;
        unsigned int u;
    } fu;
    cout << "Введи число типа float: ";
    cin >> fu.f;

    int order_f = sizeof(float) * 8;
    unsigned int mask_f = 1u << (order_f - 1);

    cout << "Число: " << fu.f << endl;
    cout << "Знак | Порядок | Мантисса" << endl;
    for (int i = 0; i < order_f; i++) {
        cout << ((fu.u & (mask_f >> i)) ? '1' : '0');
        if (i == 0 || i == 8) cout << " | ";
    }
    cout << endl;

    ///задание 4
    cout << endl << "=== Задание 4 ===" << endl;

    union {
        double d;
        unsigned long long u;
    } du;
    cout << "Введи число типа double: ";
    cin >> du.d;

    int order_d = sizeof(double) * 8;
    unsigned long long mask_d = 1ULL << (order_d - 1);

    cout << "Число: " << du.d << endl;
    cout << "Знак | Порядок | Мантисса" << endl;
    for (int i = 0; i < order_d; i++) {
        cout << ((du.u & (mask_d >> i)) ? '1' : '0');
        if (i == 0 || i == 11) cout << " | ";
    }
    cout << endl;

    //задание 5
    cout << endl << "=== Задание 5 ===" << endl;
    int type, pos, op;

    cout << "Тип числа (1 - int, 2 - float, 3 - double): ";
    cin >> type;

    if (type == 1) {
        int x;
        cout << "Введите int: ";
        cin >> x;
        cout << "Номер бита (0..31, 0 - младший): ";
        cin >> pos;
        cout << "Операция (1 - сбросить &, 2 - установить |, 3 - инвертировать ^): ";
        cin >> op;

        if (pos < 0 || pos > 31) {
            cout << "Ошибка. Номер бита 0-31." << endl;
        }
        else if (op < 1 || op > 3) {
            cout << "Ошибка. Операция 1-3." << endl;
        }
        else {
            unsigned int u = x;
            unsigned int mask = 1u << pos;

            cout << "До:    ";
            for (int i = 31; i >= 0; i--) cout << ((u & (1u << i)) ? '1' : '0');
            cout << "  = " << x << endl;

            if (op == 1)      u &= ~mask;
            else if (op == 2) u |= mask;
            else              u ^= mask;

            cout << "После: ";
            for (int i = 31; i >= 0; i--) cout << ((u & (1u << i)) ? '1' : '0');
            cout << "  = " << (int)u << endl;
        }
    }
    else if (type == 2) {
        union {
            float f;
            unsigned int u;
        } x;
        cout << "Введите float: ";
        cin >> x.f;
        cout << "Номер бита (0..31, 0 - младший): ";
        cin >> pos;
        cout << "Операция (1 - сбросить &, 2 - установить |, 3 - инвертировать ^): ";
        cin >> op;

        if (pos < 0 || pos > 31) {
            cout << "Ошибка. Номер бита 0-31." << endl;
        }
        else if (op < 1 || op > 3) {
            cout << "Ошибка. Операция 1-3." << endl;
        }
        else {
            unsigned int mask = 1u << pos;

            cout << "До:    ";
            for (int i = 31; i >= 0; i--) {
                cout << ((x.u & (1u << i)) ? '1' : '0');
                if (i == 31 || i == 23) cout << " ";
            }
            cout << "  = " << x.f << endl;

            if (op == 1)      x.u &= ~mask;
            else if (op == 2) x.u |= mask;
            else              x.u ^= mask;

            cout << "После: ";
            for (int i = 31; i >= 0; i--) {
                cout << ((x.u & (1u << i)) ? '1' : '0');
                if (i == 31 || i == 23) cout << " ";
            }
            cout << "  = " << x.f << endl;
        }
    }
    else if (type == 3) {
        union {
            double d;
            unsigned long long u;
        } x;
        cout << "Введите double: ";
        cin >> x.d;
        cout << "Номер бита (0..63, 0 - младший): ";
        cin >> pos;
        cout << "Операция (1 - сбросить &, 2 - установить |, 3 - инвертировать ^): ";
        cin >> op;

        if (pos < 0 || pos > 63) {
            cout << "Ошибка. Номер бита 0-63." << endl;
        }
        else if (op < 1 || op > 3) {
            cout << "Ошибка. Операция 1-3." << endl;
        }
        else {
            unsigned long long mask = 1ULL << pos;

            cout << "До:    ";
            for (int i = 63; i >= 0; i--) {
                cout << ((x.u & (1ULL << i)) ? '1' : '0');
                if (i == 63 || i == 52) cout << " ";
            }
            cout << "  = " << x.d << endl;

            if (op == 1)      x.u &= ~mask;
            else if (op == 2) x.u |= mask;
            else              x.u ^= mask;

            cout << "После: ";
            for (int i = 63; i >= 0; i--) {
                cout << ((x.u & (1ULL << i)) ? '1' : '0');
                if (i == 63 || i == 52) cout << " ";
            }
            cout << "  = " << x.d << endl;
        }
    }
    else {
        cout << "Ошибка. Неверный тип." << endl;
    }

    ///ИДЗ
    cout << endl << "=== ИДЗ ===" << endl;

    int number;
    cout << "Введите целое число: ";
    cin >> number;

    unsigned int u_number = static_cast<unsigned int>(number);
    unsigned int u_result = u_number << 1;

    cout << "Число в двоичном виде: ";
    for (int i = 31; i >= 0; i--) {
        cout << ((u_number & (1u << i)) ? '1' : '0');
    }
    cout << endl;
    cout << "После сдвига влево:    ";
    for (int i = 31; i >= 0; i--) {
        cout << ((u_result & (1u << i)) ? '1' : '0');
    }
    cout << endl;
    cout << "Результат: " << number << " * 2 = " << static_cast<int>(u_result) << endl;
    return 0;
}