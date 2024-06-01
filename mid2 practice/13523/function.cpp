#include "function.h"
#include <algorithm>

using namespace std;
Darray::~Darray(){
    delete[] data;
}
int& Darray::operator[](int idx){
    return data[idx];
}

void Darray::pushback(int x){
    if(size == capacity){
        resize();
    }
    data[size++] = x;
}

void Darray::popback(void){
    if(size > 0)
        size--;
}

void Darray::clear(void){
    size = 0;
}

int Darray::length(void){
    return size;
}

void Darray::resize(void){
    int *new_data = new int[capacity * 2];
    for(int i = 0; i < size; i++){
        new_data[i] = data[i];
    }
    delete[] data;
    data = new_data;
    capacity *= 2;
}


void INT::operator+=(INT& b){ 
    int carry = 0;
    int len1 = data.length();
    int len2 = b.data.length();
    int max_len = max(len1, len2);

    data.clear();

    for (int i = 0; i < max_len; i++) {
        int digit1 = (i < len1) ? data[i] : 0;
        int digit2 = (i < len2) ? b.data[i] : 0;
        int sum = digit1 + digit2 + carry;
        data.pushback(sum % 10);
        carry = sum / 10;
    }

    if(carry > 0){
        data.pushback(carry);
    }
    
}

istream &operator>>(istream& is, INT& num){
    string s;
    is >> s;
    reverse(s.begin(), s.end());
    num.data.clear();

    for(char n : s){
        num.data.pushback(n - '0');
    }
    return is;

}

ostream &operator<<(ostream& os, INT& num){
    for (int i = num.data.length() - 1; i >= 0; i--) {
        os << num.data[i];
    }
    return os;
}