#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

int main() {
    ofstream out("grades.txt");
    int g;
    cout << "Enter 5 grades: ";
    for (int i = 0; i < 5; i++) {
        cin >> g;
        out << g << "\n";
    }
    out.close();

    ifstream in("grades.txt");
    cout << "Grades:\n";
    while (in >> g) cout << g << "\n";
    in.close();

    int del;
    cout << "Grade to delete: ";
    cin >> del;

    in.open("grades.txt");
    ofstream tmp("temp.txt");
    bool found = false;
    while (in >> g) {
        if (g == del && !found) { found = true; continue; }
        tmp << g << "\n";
    }
    in.close();
    tmp.close();

    if (remove("grades.txt") == 0 && rename("temp.txt", "grades.txt") == 0)
        cout << (found ? "Deleted & updated successfully.\n" : "Updated (grade not found).\n");
    else
        cout << "Error updating file!\n";

    return 0;
}
