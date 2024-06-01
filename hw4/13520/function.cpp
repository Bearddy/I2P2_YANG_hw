#include "function.h"

Darray::~Darray(){
    delete[] data;
}

int& Darray::operator[](int idx){
    return data[idx];
}

void Darray::pushback(int x){
    if (size == capacity) {
        resize();
    }
    data[size++] = x;
}

void Darray::clear(void){
    size = 0;
}

int Darray::length(void){
    return size;
}

void Darray::resize(void){
    int *new_data = new int[capacity * 2];
    for (int i = 0; i < size; i++) {
        new_data[i] = data[i];
    }
    delete[] data;
    data = new_data;
    capacity *= 2;
}