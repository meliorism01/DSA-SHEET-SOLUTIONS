// Resverse a string using stack.


//Solution:
#include <iostream>
#include <stack>
using namespace std;

int main() {
    string str;

    cout << "Enter a string: ";
    getline(cin, str);

    stack<char> s;

    // Push each character into the stack
    for (char ch : str) {
        s.push(ch);
    }

    // Pop characters to form the reversed string
    string rev = "";
    while (!s.empty()) {
        rev += s.top();
        s.pop();
    }

    cout << "Reversed string: " << rev << endl;

    return 0;
}
