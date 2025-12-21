#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Student {
    int id;
    string name;
    int age;
    double gpa;

    Student(int i, string n, int a, double g) : id(i), name(n), age(a), gpa(g) {}

    void display() const {
        cout << left << setw(10) << id 
             << setw(20) << name 
             << setw(10) << age 
             << setw(10) << fixed << setprecision(2) << gpa << endl;
    }
};

class StudentManager {
private:
    vector<Student> students;
    int nextId;

public:
    StudentManager() : nextId(1) {}

    void addStudent(const string& name, int age, double gpa) {
        students.push_back(Student(nextId++, name, age, gpa));
        cout << "Student added successfully! ID: " << (nextId - 1) << endl;
    }

    void displayAllStudents() const {
        if (students.empty()) {
            cout << "No students in the system." << endl;
            return;
        }

        cout << "\n=== Student Records ===" << endl;
        cout << left << setw(10) << "ID" 
             << setw(20) << "Name" 
             << setw(10) << "Age" 
             << setw(10) << "GPA" << endl;
        cout << string(50, '-') << endl;

        for (const auto& student : students) {
            student.display();
        }
    }

    void searchStudent(int id) const {
        auto it = find_if(students.begin(), students.end(), 
                         [id](const Student& s) { return s.id == id; });

        if (it != students.end()) {
            cout << "\nStudent Found:" << endl;
            cout << left << setw(10) << "ID" 
                 << setw(20) << "Name" 
                 << setw(10) << "Age" 
                 << setw(10) << "GPA" << endl;
            cout << string(50, '-') << endl;
            it->display();
        } else {
            cout << "Student with ID " << id << " not found." << endl;
        }
    }

    void calculateAverageGPA() const {
        if (students.empty()) {
            cout << "No students to calculate average." << endl;
            return;
        }

        double sum = 0.0;
        for (const auto& student : students) {
            sum += student.gpa;
        }

        double average = sum / students.size();
        cout << "Average GPA: " << fixed << setprecision(2) << average << endl;
    }

    void deleteStudent(int id) {
        auto it = find_if(students.begin(), students.end(), 
                         [id](const Student& s) { return s.id == id; });

        if (it != students.end()) {
            students.erase(it);
            cout << "Student with ID " << id << " deleted successfully." << endl;
        } else {
            cout << "Student with ID " << id << " not found." << endl;
        }
    }
};

void displayMenu() {
    cout << "\n=== Student Management System ===" << endl;
    cout << "1. Add Student" << endl;
    cout << "2. Display All Students" << endl;
    cout << "3. Search Student by ID" << endl;
    cout << "4. Calculate Average GPA" << endl;
    cout << "5. Delete Student" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    StudentManager manager;
    int choice;

    cout << "Welcome to Student Management System!" << endl;

    while (true) {
        displayMenu();
        cin >> choice;

        if (choice == 6) {
            cout << "Exiting... Thank you!" << endl;
            break;
        }

        switch (choice) {
            case 1: {
                string name;
                int age;
                double gpa;

                cout << "Enter student name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter age: ";
                cin >> age;
                cout << "Enter GPA (0.0 - 4.0): ";
                cin >> gpa;

                if (gpa < 0.0 || gpa > 4.0) {
                    cout << "Invalid GPA! Must be between 0.0 and 4.0" << endl;
                } else if (age < 5 || age > 100) {
                    cout << "Invalid age!" << endl;
                } else {
                    manager.addStudent(name, age, gpa);
                }
                break;
            }
            case 2:
                manager.displayAllStudents();
                break;
            case 3: {
                int id;
                cout << "Enter student ID: ";
                cin >> id;
                manager.searchStudent(id);
                break;
            }
            case 4:
                manager.calculateAverageGPA();
                break;
            case 5: {
                int id;
                cout << "Enter student ID to delete: ";
                cin >> id;
                manager.deleteStudent(id);
                break;
            }
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
