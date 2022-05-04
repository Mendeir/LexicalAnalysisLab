#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

string retrieveFile (string sourceFile);
void tokenize (string givenString);
void evaluateToken (string givenString);
void dispPunctuators(string code);
bool isSymbol(char givenChar);
bool isPunctuator(string code, int i);
bool isKeyword(string token);
bool isOperator(string code);

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

bool isKeyword(string token){
    string keywords[84] = {"alignas", "alignof", "and", "asm", "auto", "bitland", "bitor", "bool",
                            "break", "case", "catch", "char", "char16_t", "char32_t", "class",
                            "compl", "const", "constexpr", "const_cast", "continue", "decltype",
                            "default", "delete", "do", "double", "dynamic_cast", "else", "enum",
                            "explicit", "export", "extern", "false", "false", "float", "for",
                            "friend", "goto", "if", "inline", "int", "long", "mutable", "namespace",
                            "new", "noexcept", "not", "not_eq", "nullptr", "operator", "or" ,"or_eq",
                            "private", "protected", "public", "register", "reinterpret_cast", "return",
                            "short", "signed", "sizeof", "static", "static_assert", "static cast",
                            "struct", "switch", "template", "this", "thread_local", "throw", "true",
                            "try", "typedef", "typeid", "typename", "union", "unsigned", "using",
                            "virtual", "void", "volatile", "wchar_t", "while", "xor", "xor_eq"};
    
    for(int i = 0; i < 84; i++){
        if (token == keywords[i]){
            return true;
        }
    }
    return false;
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
        if (givenString[counter] == ' ' || isSymbol(givenString[counter])) {
        
            if (subString != "") {
                evaluateToken(subString);
                subString = "";

                if (!isSymbol(givenString[counter])) {
                     ++counter;
                    continue;
                }
            }
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
     if (isOperator(givenString)) {
        cout << "'" << givenString << "'" << " is an operator." << '\n';
        return;
    } 

    if (isKeyword(givenString)) {
        cout << "'" << givenString << "'" << " is a keyword." << '\n';
        return;
    } 

    if (false) {
        cout << "'" << givenString << "'" << " is an identifier." << '\n';
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

bool isSymbol(char givenChar) {
    if (givenChar == '+' || givenChar == '-' || givenChar == '!' || givenChar == '%' || 
        givenChar == '^' || givenChar == '&' || givenChar == '*' || givenChar == '~' ||
        givenChar == '/')
        return true;

    return false;
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

bool isOperator(string code){
    
    // check each character in the text file for operations symbols
    for(int i = 0; i< code.length();i++){
        if(code[i] == '+'){
            return true;
        }
        if(code[i] == '-'){
            return true;
        }
        if(code[i] == '&'){
            return true;
        }
        if(code[i] == '*'){
            return true;
        }
        if(code[i] == '!'){
            return true;
        }
        if(code[i] == '~'){
            return true;
        }
        if(code[i] == '<'){
            return true;
        }
        if(code[i] == '>'){
            return true;
        }
        if(code[i] == '|'){
            return true;
        }
        if(code[i] == '^'){
            return true;
        }
        if(code[i] == '%'){
            return true;
        }
        if(code[i] == '.'){
            return true;
        }
        if(code[i] == ','){
            return true;
        }
        if(code[i] == '='){
            return true;
        }
        if(code[i] == '/'){
            return true;
        }
        if(code[i] == ':' && code[i+1] == ':'){
            return true;
        }
        if(code[i] == '-' && code[i+1] == '>'){
            return true;
        }
        if(code[i] == '[' && code[i+1] == ']'){
            return true;
        }
        if(code[i] == '(' && code[i+1] == ')'){
            return true;
        }
        if(code[i] == '+' && code[i+1] == '+'){
            return true;
        }
        if(code[i] == '-' && code[i+1] == '-'){
            return true;
        }
        if(code[i] == '.' && code[i+1] == '*'){
            return true;
        }
        if(code[i] == '<' && code[i+1] == '<'){
            return true;
        }
        if(code[i] == '>' && code[i+1] == '>'){
            return true;
        }
        if(code[i] == '<' && code[i+1] == '='){
            return true;
        }
        if(code[i] == '>' && code[i+1] == '='){
            return true;
        }
        if(code[i] == '=' && code[i+1] == '='){
            return true;
        }
        if(code[i] == '!' && code[i+1] == '='){
            return true;
        }
        if(code[i] == '&' && code[i+1] == '&'){
            return true;
        }
        if(code[i] == '|' && code[i+1] == '|'){
            return true;
        }
        if(code[i] == '?' && code[i+1] == ':'){
            return true;
        }
        if(code[i] == '*' && code[i+1] == '='){
            return true;
        }
        if(code[i] == '/' && code[i+1] == '='){
            return true;
        }
        if(code[i] == '%' && code[i+1] == '='){
            return true;
        }
        if(code[i] == '+' && code[i+1] == '='){
            return true;
        }
        if(code[i] == '-' && code[i+1] == '='){
            return true;
        }
        if(code[i] == '&' && code[i+1] == '='){
            return true;
        }
        if(code[i] == '|' && code[i+1] == '='){
            return true;
        }
        if(code[i] == '^' && code[i+1] == '='){
            return true;
        }
        if(code[i] == '-' && code[i+1] == '>' && code[i+1] == '*'){
            return true;
        }
        if(code[i] == '<' && code[i+1] == '<' && code[i+1] == '='){
            return true;
        }
        if(code[i] == '>' && code[i+1] == '>' && code[i+1] == '='){
            return true;
        }
        
    }
    // check each character in the text file for operations key words
    if(code.find("typeid") < code.length()){
        return true;
    }
    if(code.find("const_cast") < code.length()){
        return true;
    }
    if(code.find("dynamic_cast") < code.length()){
        return true;
    }
    if(code.find("reinterpret_cast") < code.length()){
        return true;
    }
    if(code.find("static_cast") < code.length()){
        return true;
    }
    if(code.find("sizeof") < code.length()){
        return true;
    }
    if(code.find("new") < code.length()){
        return true;
    }
    if(code.find("delete") < code.length()){
        return true;
    }
    if(code.find("throw") < code.length()){
        return true;
    }

    return false;
}

