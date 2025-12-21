#include <iostream>
using namespace std;

int main() {
    double a, b;
    char op;
    cout << "Enter calculation (e.g., 5 + 3): ";
    cin >> a >> op >> b;
    if (op == '+') cout << "Result: " << a + b << endl;
    else if (op == '-') cout << "Result: " << a - b << endl;
    else if (op == '*') cout << "Result: " << a * b << endl;
    else if (op == '/') cout << "Result: " << (b != 0 ? a / b : 0) << " (Error if b=0)" << endl;
    return 0;
}
