#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string retrieveFile (string sourceFile);
void tokenize (string givenString);
void evaluateToken (string givenString);


int main() {
    string fileName = "code.txt";
    string code = retrieveFile(fileName);
    tokenize(code);

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

void tokenize (string givenString) {
    int stringLength = givenString.length();
    int counter = 0;
    string subString = "";

    while (counter <= stringLength) {
        if (givenString[counter] == ' ') {
            if (subString != " ") {
                evaluateToken(subString);
                subString = " ";
            }

            ++counter;
            continue;
        }

        if (false) {
            cout << givenString[counter] << " is a punctuator." << '\n';
        } else {
            subString += givenString[counter];
        }

        ++counter;
    }


}

void evaluateToken (string givenString) {
    if (false) {
        cout << "'" << givenString << "'" << " is a keyword." << '\n';
    } 

    if (false) {
        cout << "'" << givenString << "'" << " is an identifier." << '\n';
    } 

    if (false) {
        cout << "'" << givenString << "'" << " is an operator." << '\n';
    } 

    cout << "'" << givenString << "'" << " is a literal." << '\n';
}