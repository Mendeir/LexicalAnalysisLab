#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string retrieveFile(string sourceFile);

int main() {

    cout << retrieveFile("code.txt");

    return 0;
}

string retrieveFile(string sourceFile) {
    fstream codeFile;

    codeFile.open(sourceFile, ios::in);

    if (!codeFile) {
        cerr << "File not found!";
        return "";
    }

    string fileLine = "";
    string code = "";

    while (getline(codeFile, fileLine)) {
        code += fileLine;
        code += " ";
    }

    return code;
}