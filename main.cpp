#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string retrieveFile(string sourceFile);
bool isKeyword(string token);
int main() {

    string fileName = "code.txt";
    string code = retrieveFile(fileName);
    cout << code;
    
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