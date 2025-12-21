#include <iostream>
using namespace std;

int main() {
    int n = 10, a = 0, b = 1;
    cout << "First 10 Fibonacci numbers:" << endl;
    for (int i = 0; i < n; i++) {
        cout << a << " ";
        int next = a + b;
        a = b;
        b = next;
    }
    cout << endl;
    return 0;
}
