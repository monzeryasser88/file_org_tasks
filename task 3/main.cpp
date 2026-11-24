#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream out("welcome.txt");
    out << "Hello Everybody";
    out.close();

    ifstream in("welcome.txt");
    string text;
    getline(in, text);
    in.close();

    size_t pos = text.find("body");
    if (pos != string::npos) {
        text.replace(pos, 4, "one");
    }

    ofstream out2("welcome.txt");
    out2 << text;
    out2.close();

    cout << text << "\n";
    return 0;
}

