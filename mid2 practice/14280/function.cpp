#include "function.h"

/* ***** TODO ***** */
// Adds two fractions and returns the result as a new fraction object
Fraction Fraction::operator+(const Fraction& frac){
    long long num = numerator * frac.denominator + frac.numerator * denominator;
    long long den = denominator * frac.denominator;
    return Fraction(num, den);

}

/* ***** TODO ***** */
// Stream extraction operator that inputs the fraction from an input stream 
// in the form "numerator/denominator".
//
// Example.
// --> Fraction f;
//     cin >> f;                      // 6/7 (numerator = 6, denominator = 7)
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
// Compares this Fraction to another Fraction
// to determine if it is (< / > / <= / >=) the other.
bool Fraction::operator<(const Fraction& frac){
    return numerator * frac.denominator < frac.numerator * denominator;
}

bool Fraction::operator>(const Fraction& frac){
    return numerator * frac.denominator > frac.numerator * denominator;

}
bool Fraction::operator<=(const Fraction& frac){
    return numerator * frac.denominator <= frac.numerator * denominator;
}

bool Fraction::operator>=(const Fraction& frac){
    return numerator * frac.denominator >= frac.numerator * denominator;
}

/* ***** TODO ***** */
// Copy constructor: performs a "deep copy" of the entire FractionList.
// This is necessary to ensure that each FractionList instance
// has its own separate copies of Fraction objects and linked FractionList nodes,
// preventing issues related to multiple deletions of the same memory during destruction.
FractionList::FractionList(const FractionList& fraclist){
    if(fraclist.fraction != nullptr){
        fraction = new Fraction(*fraclist.fraction);
    }
    else{
        fraction = nullptr;
    }
    if(fraclist.nextFraction != nullptr){
        nextFraction = new FractionList(*fraclist.nextFraction);
    }
    else{
        nextFraction = nullptr;
    }

}

/* ***** TODO ***** */
// Assigns a new value to the FractionList object, replacing its current contents,
// and properly disposing of the old contents.
// Notice: Adding "return *this" allows the operator to return a reference to the object itself. 
// It supports chaining multiple assignments together in a single statement (e.g. A = B = C), 
// as each assignment operation can then be followed by another, 
// using the result of the previous assignment.
FractionList& FractionList::operator=(const FractionList& fraclist){
    if(this == &fraclist){
        return *this;
    }
    delete fraction;
    delete nextFraction;
    if(fraclist.fraction != nullptr){
        fraction = new Fraction(*fraclist.fraction);
    }
    else{
        fraction = nullptr;
    }
    if(fraclist.nextFraction != nullptr){
        nextFraction = new FractionList(*fraclist.nextFraction);
    }
    else{
        nextFraction = nullptr;
    }
    return *this;

}

/* ***** TODO ***** */
// Adds a new Fraction to the end of the linked list.
// This operator takes a Fraction object as input and appends it
// to the end of the current FractionList.
// Traverse through the entire list to reach the last element, 
// ensuring the new Fraction is added at the end.
FractionList& FractionList::operator+=(const Fraction& frac){
    if(fraction == nullptr){
        fraction = new Fraction(frac);
    }
    else{
        FractionList *current = this;
        while(current->nextFraction != nullptr){
            current = current->nextFraction;
        }
        current->nextFraction = new FractionList(new Fraction(frac));
    }
    return *this;
}

/* ***** TODO ***** */
// Destructor that recursively deletes all fractions in the list to prevent memory leaks.
FractionList::~FractionList(){
    delete fraction;
    delete nextFraction;

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
        result = result + *(current->fraction);
        current = current->nextFraction;
    }
    return result;
}