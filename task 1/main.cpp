#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    int choice;
    cout << "1. Add Student\n2. View Saved Students\nChoice: ";
    cin >> choice;
    cin.ignore();

    if (choice == 1) {
        string name, id, grade;
        cout << "Enter Full Name: ";
        getline(cin, name);
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Grade: ";
        cin >> grade;

        ofstream out("Student.txt", ios::app);
        out << "Full Name: " << name << " | ID: " << id << " | Grade: " << grade << "\n";
        out.close();
    } else if (choice == 2) {
        ifstream in("Student.txt");
        string line;
        while (getline(in, line)) cout << line << "\n";
        in.close();
    }
    return 0;
}
