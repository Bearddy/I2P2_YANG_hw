#include <iostream>
#include <string>
#include "function.h"


using namespace std;

String_Calculator::String_Calculator(const string str) : s(str) {}

String_Calculator& String_Calculator::Add(const string str) {
    this->s += str;
    return *this;
}

String_Calculator& String_Calculator::Subtract(const string str) {
    size_t pos = this->s.find(str);
    if (pos == string::npos) this->s = "error";
    else this->s.erase(pos, str.size());
    return *this;
}

String_Calculator& String_Calculator::DividedBy(const string str) {
    size_t pos = -1;
    int cnt = 0;
    while ((pos = this->s.find(str, pos+1)) != string::npos) {
        cnt++;
    }
    this->s = to_string(cnt);
    return *this;
}

void String_Calculator::output() const {
    cout << s << '\n';
}
