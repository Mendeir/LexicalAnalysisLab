#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string retrieveFile(string sourceFile);
bool isPunctuator(string code, int i);
void dispPunctuators(string code);

int main() {

    string fileName = "code.txt";
    string code = retrieveFile(fileName);
    cout << "code.txt:\n" << code << "\n\n";

    dispPunctuators(code);

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