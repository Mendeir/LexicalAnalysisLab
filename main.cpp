#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string retrieveFile (string sourceFile);
void tokenize (string givenString);
void evaluateToken (string givenString);
bool isPunctuator(string code, int i);
void dispPunctuators(string code);

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

    if (givenString == "") {
        cout << "File is empty!" << '\n';
        return;
    }

    while (counter <= stringLength) {
        if (givenString[counter] == ' ') {
            if (subString != "") {
                evaluateToken(subString);
                subString = "";
            }

            ++counter;
            continue;
        }

        if (isPunctuator(givenString, counter)) {
            cout << "'" << givenString[counter] << "'" << " is a punctuator." << '\n';
        } else {
            subString += givenString[counter];
        }

        ++counter;
    }


}

void evaluateToken (string givenString) {
    if (false) {
        cout << "'" << givenString << "'" << " is a keyword." << '\n';
        return;
    } 

    if (false) {
        cout << "'" << givenString << "'" << " is an identifier." << '\n';
        return;
    } 

    if (false) {
        cout << "'" << givenString << "'" << " is an operator." << '\n';
        return;
    } 

    cout << "'" << givenString << "'" << " is a literal." << '\n';
}

void dispPunctuators(string code){
    //Scanner for punctuators
    //Mainly for testing before merge
    for(int i=0; i<code.length(); i++){
            if(isPunctuator(code, i)){
                cout << code[i] << " is a Punctuator\n";
            }
        }
}

bool isPunctuator(string code, int i){
    /*
        Returns true if char is a punctuator
        EXCLUDES operators that use punctuator characters
        except exact matches (i.e. punctuator '^' vs bitwise or '^')
    */
    switch (code[i]){
        case '!':
            if(code[i]=='!' && code[i+1]=='='){
                return false;
            }
            return true;
        case '%':
            if(code[i]=='%' && code[i+1]=='='){
                return false;
            }
            return true;
        case '^':
            if(code[i]=='^' && code[i+1]=='='){
                return false;
            }
            return true;
        case '&':
            if((code[i]=='&' && code[i+1]=='=')
            || (code[i]=='&' && code[i+1]=='&')
            || (code[i-1]=='&' && code[i]=='&')
            || (code[i]=='&' && isalpha(code[i+1]))){
                return false;
            }
            return true;
        case '*':
            if(code[i]=='*' && code[i+1]=='='){
                return false;
            }
            return true;
        case '(':
            return true;
        case ')':
            return true;
        case '-':
            if((code[i]=='-' && code[i+1]=='=')
            || (code[i]=='-' && code[i+1]=='-')
            || (code[i-1]=='-' && code[i]=='-')){
                return false;
            }
            return true;
        case '+':
            if((code[i]=='+' && code[i+1]=='=')
            || (code[i]=='+' && code[i+1]=='+')
            || (code[i-1]=='+' && code[i]=='+')){
                return false;
            }
            return true;
        case '<':
            if((code[i]=='<' && code[i+1]=='=')
            || (code[i]=='<' && code[i+1]=='<')
            || (code[i-1]=='<' && code[i]=='<')){
                return false;
            }
            return true;
        case '>':
            if((code[i]=='>' && code[i+1]=='=')
            || (code[i]=='>' && code[i+1]=='>')
            || (code[i-1]=='>' && code[i]=='>')){
                return false;
            }
            return true;
        case '=':
            if((code[i]=='=' && code[i+1]=='=')
            || (code[i-1]=='=' && code[i]=='=')){
                return false;
            }
            return true;
        case '{':
            return true;
        case '}':
            return true;
        case '|':
            if((code[i]=='|' && code[i+1]=='=')
            || (code[i]=='|' && code[i+1]=='|')
            || (code[i-1]=='|' && code[i]=='|')){
                return false;
            }
            return true;
        case '~':
            return true;
        case '[':
            return true;
        case ']':
            return true;
        case '\\':
            return true;
        case ';':
            return true;
        case '\'':
            return true;
        case '?':
            if(code[i]=='?' && code[i+1]==':'){
                return false;
            }
            return true;
        case ':':
            if((code[i]==':' && code[i+1]==':')
            || (code[i-1]==':' && code[i]==':')){
                return false;
            }
            return true;
        case '\"':
            return true;
        case ',':
            return true;
        case '.':
            if(code[i]=='.' && code[i+1]=='*'){
                return false;
            }
            return true;
        case '/':
            if(code[i]=='/' && code[i+1]=='='){
                return false;
            }
            return true;
        case '#':
            return true;
        default:
            return false;
    }
}