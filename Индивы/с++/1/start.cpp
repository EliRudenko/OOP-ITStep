#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cout << "Введите 3 целых числа: ";
    cin >> a >> b >> c;

    int count = 0, sum = 0;

    if (a > 0) { count++; sum += a; }
    if (b > 0) { count++; sum += b; }
    if (c > 0) { count++; sum += c; }

    cout << "Положительных чисел: " << count << endl;
    if (count > 0) {
        cout << "Сумма положительных: " << sum << endl;
    }

    return 0;
}
