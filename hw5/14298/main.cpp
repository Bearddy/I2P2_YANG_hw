#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <map>

using namespace std;

void print_min_max(int);
void change_vote(int);


struct cmp{
    bool operator()(const int& a, const int& b) const{
        return a < b;
    }
};

multiset<int, cmp> vote;

int main(){
    int N;
    string cmd;
    cin >> N;
    while(N--){
        cin >> cmd;
        if(cmd == "Max" || cmd == "Min") print_min_max(cmd == "Max"); 
        else if(cmd == "Add" || cmd == "Remove") change_vote(cmd == "Add");

        // cout << "votes : ";
        // for(auto it : vote){
        //     cout << it << " ";
        // }
        // cout << endl;
    }
}

void print_min_max(int index){
    if(vote.empty()){
        cout << "No votes recorded" << endl;
        return;
    }
    

    if(index){
        cout << *prev(vote.end()) << endl;
    }
    else{
        cout << *vote.begin() << endl;
    }
}


void change_vote(int index){
    int num;
    cin >> num;
    if(index){
        vote.insert(num);
    }
    else{
        if(vote.empty() || vote.find(num) == vote.end()) return;
        vote.erase(vote.find(num));
    }
}