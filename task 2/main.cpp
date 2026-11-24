#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream out("fruit.txt", ios::app);
    string fruit;
    int n;

    cout << "How many fruits to add? ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        cout << "Enter fruit: ";
        getline(cin, fruit);
        out << fruit << "\n";
    }

    out << "Fresh Fruits\n";
    out.close();

    ifstream in("fruit.txt");
    string line;
    while (getline(in, line)) {
        cout << line << "\n";
    }
    in.close();

    return 0;
}
