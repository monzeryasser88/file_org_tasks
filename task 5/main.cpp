#include <iostream>
#include <fstream>
#include <limits>
using namespace std;

struct Student {
    char name[20];
    int id;
    float grade;
    char delim = '$';
};

int main() {
    ofstream outFile("students.txt", ios::app);
    if (!outFile.is_open()) {
        cout << "Cannot open file!\n";
        return 1;
    }

    char ch = 'y';
    while (ch == 'y' || ch == 'Y') {
        Student s;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Name: ";
        cin.getline(s.name, 20);

        cout << "ID and Grade: ";
        cin >> s.id >> s.grade;

        outFile << s.name << ", " << s.id << ", " << s.grade << " " << s.delim << "\n";

        cout << "Add more? (y/n): ";
        cin >> ch;
    }

    outFile.close();
    cout << "Done!\n";
    return 0;
}
