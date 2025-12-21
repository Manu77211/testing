#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Calculator {
private:
    double result;

public:
    Calculator() : result(0.0) {}

    double add(double a, double b) {
        result = a + b;
        return result;
    }

    double subtract(double a, double b) {
        result = a - b;
        return result;
    }

    double multiply(double a, double b) {
        result = a * b;
        return result;
    }

    double divide(double a, double b) {
        if (b == 0) {
            throw invalid_argument("Error: Division by zero is not allowed!");
        }
        result = a / b;
        return result;
    }

    double getResult() const {
        return result;
    }
};

void displayMenu() {
    cout << "\n=== Calculator Menu ===" << endl;
    cout << "1. Addition (+)" << endl;
    cout << "2. Subtraction (-)" << endl;
    cout << "3. Multiplication (*)" << endl;
    cout << "4. Division (/)" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    Calculator calc;
    int choice;
    double num1, num2;

    cout << "Welcome to C++ Calculator!" << endl;

    while (true) {
        displayMenu();
        cin >> choice;

        if (choice == 5) {
            cout << "Thank you for using Calculator. Goodbye!" << endl;
            break;
        }

        if (choice < 1 || choice > 5) {
            cout << "Invalid choice! Please try again." << endl;
            continue;
        }

        cout << "Enter first number: ";
        cin >> num1;
        cout << "Enter second number: ";
        cin >> num2;

        try {
            double result;
            switch (choice) {
                case 1:
                    result = calc.add(num1, num2);
                    cout << "Result: " << num1 << " + " << num2 << " = " << result << endl;
                    break;
                case 2:
                    result = calc.subtract(num1, num2);
                    cout << "Result: " << num1 << " - " << num2 << " = " << result << endl;
                    break;
                case 3:
                    result = calc.multiply(num1, num2);
                    cout << "Result: " << num1 << " * " << num2 << " = " << result << endl;
                    break;
                case 4:
                    result = calc.divide(num1, num2);
                    cout << "Result: " << num1 << " / " << num2 << " = " << result << endl;
                    break;
            }
        } catch (const invalid_argument& e) {
            cout << e.what() << endl;
        }
    }

    return 0;
}
