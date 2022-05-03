#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

string retrieveFile(string sourceFile);
bool isPunctuator(string code, int i);
void dispPunctuators(string code);
void displayOperator(vector<string> values);
vector<string> isOperator(string code);

int main() {

    string fileName = "code.txt";
    string code = retrieveFile(fileName);
    cout << "code.txt:\n" << code << "\n\n";

    dispPunctuators(code);
    displayOperator(isOperator(code));
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

void displayOperator(vector<string> values){
    // display the operator values inside the vector
    for(int i = 0; i< values.size(); i++){
        cout << values[i] << " is an operator" << endl;
    }
}

vector<string> isOperator(string code){
    // creating a vector to store operation elements
    vector<string> operators;
    // check each character in the text file for operations symbols
    for(int i = 0; i< code.length();i++){
        if(code[i] == '+'){
            operators.push_back("+");
        }
        if(code[i] == '-'){
            operators.push_back("-");
        }
        if(code[i] == '&'){
            operators.push_back("&");
        }
        if(code[i] == '*'){
            operators.push_back("*");
        }
        if(code[i] == '!'){
            operators.push_back("!");
        }
        if(code[i] == '~'){
            operators.push_back("~");
        }
        if(code[i] == '<'){
            operators.push_back("<");
        }
        if(code[i] == '>'){
            operators.push_back(">");
        }
        if(code[i] == '|'){
            operators.push_back("|");
        }
        if(code[i] == '^'){
            operators.push_back("^");
        }
        if(code[i] == '%'){
            operators.push_back("%");
        }
        if(code[i] == '.'){
            operators.push_back(".");
        }
        if(code[i] == ','){
            operators.push_back(".");
        }
        if(code[i] == '='){
            operators.push_back("=");
        }
        if(code[i] == '/'){
            operators.push_back("/");
        }
        if(code[i] == ':' && code[i+1] == ':'){
            operators.push_back("::");
        }
        if(code[i] == '-' && code[i+1] == '>'){
            operators.push_back("->");
        }
        if(code[i] == '[' && code[i+1] == ']'){
            operators.push_back("[]");
        }
        if(code[i] == '(' && code[i+1] == ')'){
            operators.push_back("()");
        }
        if(code[i] == '+' && code[i+1] == '+'){
            operators.push_back("++");
        }
        if(code[i] == '-' && code[i+1] == '-'){
            operators.push_back("--");
        }
        if(code[i] == '.' && code[i+1] == '*'){
            operators.push_back(".*");
        }
        if(code[i] == '<' && code[i+1] == '<'){
            operators.push_back("<<");
        }
        if(code[i] == '>' && code[i+1] == '>'){
            operators.push_back(">>");
        }
        if(code[i] == '<' && code[i+1] == '='){
            operators.push_back("<=");
        }
        if(code[i] == '>' && code[i+1] == '='){
            operators.push_back(">=");
        }
        if(code[i] == '=' && code[i+1] == '='){
            operators.push_back("==");
        }
        if(code[i] == '!' && code[i+1] == '='){
            operators.push_back("!=");
        }
        if(code[i] == '&' && code[i+1] == '&'){
            operators.push_back("&&");
        }
        if(code[i] == '|' && code[i+1] == '|'){
            operators.push_back("||");
        }
        if(code[i] == '?' && code[i+1] == ':'){
            operators.push_back("?:");
        }
        if(code[i] == '*' && code[i+1] == '='){
            operators.push_back("*=");
        }
        if(code[i] == '/' && code[i+1] == '='){
            operators.push_back("/=");
        }
        if(code[i] == '%' && code[i+1] == '='){
            operators.push_back("%=");
        }
        if(code[i] == '+' && code[i+1] == '='){
            operators.push_back("+=");
        }
        if(code[i] == '-' && code[i+1] == '='){
            operators.push_back("-=");
        }
        if(code[i] == '&' && code[i+1] == '='){
            operators.push_back("&=");
        }
        if(code[i] == '|' && code[i+1] == '='){
            operators.push_back("|=");
        }
        if(code[i] == '^' && code[i+1] == '='){
            operators.push_back("^=");
        }
        if(code[i] == '-' && code[i+1] == '>' && code[i+1] == '*'){
            operators.push_back("->*");
        }
        if(code[i] == '<' && code[i+1] == '<' && code[i+1] == '='){
            operators.push_back("<<=");
        }
        if(code[i] == '>' && code[i+1] == '>' && code[i+1] == '='){
            operators.push_back(">>=");
        }
        
        
    }
    // check each character in the text file for operations key words
    if(code.find("typeid") < code.length()){
        operators.push_back("typeid");
    }
    if(code.find("const_cast") < code.length()){
        operators.push_back("const_cast");
    }
    if(code.find("dynamic_cast") < code.length()){
        operators.push_back("dynamic_cast");
    }
    if(code.find("reinterpret_cast") < code.length()){
        operators.push_back("reinterpret_cast");
    }
    if(code.find("static_cast") < code.length()){
        operators.push_back("static_cast");
    }
    if(code.find("sizeof") < code.length()){
        operators.push_back("sizeof");
    }
    if(code.find("new") < code.length()){
        operators.push_back("new");
    }
    if(code.find("delete") < code.length()){
        operators.push_back("delete");
    }
    if(code.find("throw") < code.length()){
        operators.push_back("throw");
    }
    return operators;
}
