#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>
#include <string>



#define endl '\n'
using namespace std;

void insert();
void range_out();
void output();

int key_val(vector<int> v);

struct cmp{
    bool operator()(const vector<int> &a, const vector<int> &b) const{
        return key_val(a) < key_val(b);
    }
};

set<vector<int>, cmp> s;

int main(){
    string cmd;
    while(cin >> cmd){
        if(cmd == "insert") insert();
        else if(cmd == "range_out") range_out();
        else if(cmd == "output") output();
    }

}

void insert(){
    int num;
    vector<int> v;
    while(cin >> num){
        if(num == 0) break;
        v.push_back(num);
    }

    int key = key_val(v);

    for(auto it : s){
        if(key_val(it) == key){
            cout << "exist" << endl;
            s.erase(it);
            reverse(v.begin(), v.end());
            break;
        }
    }

    s.insert(v);
}

void range_out(){
    int outkey[2], num;
    vector<int> v;

    for(int i = 0; i < 2; i++){
        while(cin >> num){
            if(num == 0) break;
            v.push_back(num);
        }
        outkey[i] = key_val(v);
        v.clear();
    }

    for(auto it : s){
        if(key_val(it) >= outkey[0] && key_val(it) <= outkey[1]){
            for(int n : it) cout << n << " ";
            cout << endl;
        }
    }
}

void output(){
    for(auto it : s){
        for(int n : it) cout << n << " ";
        cout << endl;
    }
}

int key_val(vector<int> v){
    int val = 0;
    for(int i = 0; i < v.size(); i++){
        val += v[i]*(v.size()-i);
    }
    return val;
}