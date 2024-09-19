#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool checkPalindrome(string str) {
    stack<char> s1, s2, s3;

    for(int i = 0; str[i] != '\0'; i++) {
        s1.push(str[i]);
    }

    s2 = s1;

    while(!s1.empty()) {
        char c = s1.top();
        s1.pop();
        s3.push(c);
    }

    while(!s2.empty()) {
        if(s2.top() != s3.top()) {
            return false;
        }
        s2.pop();
        s3.pop();
    } 

    return true;
}


int main() {
    string str = "abac";

    if(checkPalindrome(str)) {
        cout << "Palindrome" << endl;
    }
    else {
        cout << "Not Palindrome" << endl;
    }

    return 0;
}