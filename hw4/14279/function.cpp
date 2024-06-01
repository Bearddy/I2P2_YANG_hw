#include "function.h"

using namespace std;

Fraction Fraction::operator+(const Fraction& frac){
    long long num = numerator * frac.denominator + frac.numerator * denominator;
    long long den = denominator * frac.denominator;
    return Fraction(num, den);
}

Fraction& Fraction::operator*=(const Fraction& frac){
    long long num = numerator * frac.numerator;
    long long den = denominator * frac.denominator;
    long long gcd = __gcd(num, den);
    numerator = num / gcd;
    denominator = den / gcd;
    return *this;
}

long long Fraction::getIntegerPart(){
    return numerator / denominator;
}

int Fraction::operator()(const int& digit){
    // long long num = numerator * 10;
    // long long den = denominator;
    // for(int i = 0; i < digit; i++){
    //     num = num % den * 10;
    // }
    // return num / den;

    long long remainder = this->numerator % this->denominator;
    for (int i = 1; i < digit; i++) {
        remainder = (remainder * 10) % this->denominator;
    }
    return (remainder * 10) / this->denominator;
}

ostream& operator<<(ostream& os, const Fraction& frac){
    os << frac.numerator << "/" << frac.denominator;
    return os;
}

istream& operator>>(istream& is, Fraction& frac){
    string fraction_str;
    if (is >> fraction_str) {
        frac = Fraction(fraction_str);
    }
    else{
        frac = Fraction(0, 1);
    } 
    return is;
}


/* ***** TODO ***** */
        // Copy constructor: performs a "deep copy" of the entire FractionList.
        // This is necessary to ensure that each FractionList instance
        // has its own separate copies of Fraction objects and linked FractionList nodes,
        // preventing issues related to multiple deletions of the same memory during destruction.
FractionList::FractionList(const FractionList& frac){

    if (frac.fraction) {
        this->fraction = new Fraction(*frac.fraction);
    } else {
        this->fraction = nullptr;
    }

    if (frac.nextFraction) {
        this->nextFraction = new FractionList(*frac.nextFraction);
    } else {
        this->nextFraction = nullptr;
    }
}

 /* ***** TODO ***** */
        // Assigns a new value to the FractionList object, replacing its current contents,
        // and properly disposing of the old contents.
        // Notice: Adding "return *this" allows the operator to return a reference to the object itself. 
        // It supports chaining multiple assignments together in a single statement (e.g. A = B = C), 
        // as each assignment operation can then be followed by another, 
        // using the result of the previous assignment.
FractionList& FractionList::operator=(const FractionList& frac){
    if (this == &frac) {
        return *this;
    }

    delete this->fraction;
    delete this->nextFraction;

    if (frac.fraction) {
        this->fraction = new Fraction(*frac.fraction);
    } else {
        this->fraction = nullptr;
    }

    if (frac.nextFraction) {
        this->nextFraction = new FractionList(*frac.nextFraction);
    } else {
        this->nextFraction = nullptr;
    }

    return *this;
}

FractionList::~FractionList() {
    delete this->fraction;
    delete this->nextFraction;
}

 /* ***** TODO ***** */
        // Depending on the operation specified, 
        // either adds the given fraction to the list or multiplies the current fraction by it.
        // When the operator (ope) is "*", multiply the fractions directly; 
        // when "+", create a new fraction for each addition, linking them together using nextFraction.
        //
        // Hint.
        // --> Use the "*=" operator, which has been overloaded to multiply a fraction and assign the result, 
        //     to perform the multiplication on the last fraction in the list.
FractionList* FractionList::operation(string ope, Fraction* frac) {
    if (ope == "*") {
        *(this->fraction) *= *frac;
        return this;
    } else if (ope == "+") {
        FractionList* current = this;
        current->nextFraction = new FractionList(frac);
        return current->nextFraction;
    }
    return this;
}

 /* ***** TODO ***** */
        // At the end of all * operations, 
        // traverse through the FractionList and summing them up to compute the final result.
        //
        // Hint.
        // --> Use the "+" operator, which has been overloaded to add fractions, 
        //     to perform the addition of the fractions in the list.
Fraction FractionList::getResult(){
    Fraction result(0, 1);
    FractionList* current = this;
    while (current) {
        if (current->fraction) {
            result = result + *(current->fraction);
        }
        current = current->nextFraction;
    }
    return result;
}

