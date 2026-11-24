#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Person {
    string name;
    int age;
};

int main() {
    int choice;
    cout << "1. Add Persons\n2. View Saved Persons & Younger/Older\nChoice: ";
    cin >> choice;

    if (choice == 1) {
        int n;
        cout << "How many persons? ";
        cin >> n;

        ofstream out("persons.txt", ios::app);
        for (int i = 0; i < n; i++) {
            string name;
            int age;
            cout << "Enter name and age: ";
            cin >> name >> age;
            out << name << " " << age << "\n";
        }
        out.close();
    } else if (choice == 2) {
        ifstream in("persons.txt");
        vector<Person> people;
        Person p;

        while (in >> p.name >> p.age) {
            people.push_back(p);
        }
        in.close();

        if (!people.empty()) {
            cout << "\nSaved Persons:\n";
            for (int i = 0; i < (int)people.size(); i++) {
                cout << people[i].name << " - " << people[i].age << "\n";
            }

            Person youngest = people[0], oldest = people[0];
            for (int i = 1; i < (int)people.size(); i++) {
                if (people[i].age < youngest.age) youngest = people[i];
                if (people[i].age > oldest.age) oldest = people[i];
            }

            ofstream res("results.txt");
            res << "Younger: " << youngest.name << " (" << youngest.age << ")\n";
            res << "Older: " << oldest.name << " (" << oldest.age << ")\n";
            res.close();

            cout << "\nYounger: " << youngest.name << " (" << youngest.age << ")\n";
            cout << "Older: " << oldest.name << " (" << oldest.age << ")\n";
        } else {
            cout << "No saved persons found.\n";
        }
    }

    return 0;
}
