#include <bits/stdc++.h>
#include "function.h"

using namespace std;

void check_parentA(Person* p){
    if(p->parentA == nullptr){
        Person* pA = new Person();
        pA->child = p;

        if(p->parentB){
            pA->mate = p->parentB;
            p->parentB->mate = pA;
        }
        p->parentA = pA;
    }
}

void check_parentB(Person* p){
    if(p->parentB == nullptr){
        Person* pB = new Person();
        pB->child = p;

        if(p->parentA){
            pB->mate = p->parentA;
            p->parentA->mate = pB;
        }
        p->parentB = pB;
    }
}

void check_mate(Person* p){
    if(p->mate == nullptr){
        Person* m = new Person();
        m->mate = p;

        if(p->child){
            if(p->child->parentA == p){
                p->child->parentB = m;
            }
            else {
                p->child->parentA = m;
            }
            m->child = p->child;
        }

        p->mate = m;
    }
}

void check_child(Person* p){
    if(p->child == nullptr){
        Person* ch = new Person();
        ch->parentA = p;

        if(p->mate){
            p->mate->child = ch;
            ch->parentB = p->mate;
        }
        p->child = ch;
    }
}

void Person::describe(string* arr, int now, int len){
    if (now == len) return;

    if (arr[now] == "ParentA"){
        check_parentA(this);
        this->parentA->describe(arr, now + 1, len);
    }
    else if (arr[now] == "ParentB"){
        check_parentB(this);
        this->parentB->describe(arr, now + 1, len);
    }
    else if (arr[now] == "Mate"){
        check_mate(this);
        this->mate->describe(arr, now + 1, len);
    }
    else if (arr[now] == "Child"){
        check_child(this);
        this->child->describe(arr, now + 1, len);
    }
    else if(arr[now] == "Age"){
        this->age = stoi(arr[now + 1]);
        this->describe(arr, now + 2, len);
    }
    else if(arr[now] == "Gender"){
        if(arr[now+1] == "MALE") this->gender = MALE;
        else this->gender = FEMALE;
        this->describe(arr, now + 2, len);
    }
    else if(arr[now] == "Personality"){
        if(this->personality == "") this->personality = arr[now + 1];
        else this->personality += " " + arr[now + 1];
        this->describe(arr, now + 2, len);
    }
    else if(arr[now] == "Name"){
        this->name = arr[now + 1];

        this->describe(arr, now + 2, len);
    }




}

Person* Person::getRelative (string* arr, int now, int len){
    if (now == len) return this;

    if (arr[now] == "ParentA"){
        check_parentA(this);
        return this->parentA->getRelative(arr, now + 1, len);
    }
    else if (arr[now] == "ParentB"){
        check_parentB(this);
        return this->parentB->getRelative(arr, now + 1, len);
    }
    else if (arr[now] == "Mate"){
        check_mate(this);
        return this->mate->getRelative(arr, now + 1, len);
    }
    else if (arr[now] == "Child"){
        check_child(this);
        return this->child->getRelative(arr, now + 1, len);
    }
    else return this;
}