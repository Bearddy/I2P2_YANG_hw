#include "function.h"
#include <iostream>

using namespace std;



void oj::insert(std::map<int,String>& ma, int key, const std::string& str){

    for(auto it : ma){
        if(it.first == key){
            ma.erase(key);
            ma.insert(pair<int,String>(key, String(str + it.second.str)));
            //it.second.str = str + it.second.str;
            return;
        }
    }

    ma.insert({key, String(str)});
}

void oj::output(const std::map<int,String>& ma, int begin, int end){
    for(auto it : ma){
        if(it.first >= begin && it.first <= end){
            cout << it.second << " ";
            //if(it.first != end) cout << " ";
        }
    }

}
void oj::erase(std::map<int,String>& ma, int begin, int end){
    for(int i = begin; i <= end; i++){
        ma.erase(i);
    }
}

std::ostream& oj::operator<<(std::ostream& os, const std::map<int,String>& ma){
    for(auto it : ma){
        os << it.second << " ";
    }
    return os;
}