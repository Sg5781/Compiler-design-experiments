#include <iostream>
#include <string>

using namespace std;

string generateCode(string keyword, string condition, string action) {
    return keyword + " (" + condition + ") {" + action + "}";
}

int main() {
    string condition, action, generatedCode;

    // Generate and print code for the if statement
    generatedCode = generateCode("if", "x > 8", "y = y / 10;");
    cout << "Generated code for if:\n" << generatedCode << endl;

    // Generate and print code for the while loop
    generatedCode = generateCode("while", "x < 7", "y = y / 8;");
    cout << "Generated code for while:\n" << generatedCode << endl;

    return 0;
}
