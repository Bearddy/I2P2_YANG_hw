#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <map>

using namespace std;

struct cmp{
    bool operator()(const int& a, const int& b) const{
        return a < b;
        
    }
};


set<int, cmp> nums;

int main(){
    int N, M;
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        int num;
        cin >> num;
        nums.insert(num);
    }

    for(int i = 0; i < M; i++){
        int num, ans;
        cin >> num;
        
        if(nums.find(num) != nums.end()){
            ans = num;
        }
        else if(num < *nums.begin()){
            ans = *nums.begin();
        }
        else if(num > *prev(nums.end())){
            ans = *prev(nums.end());
        }
        else {
            nums.insert(num);
            auto it = nums.find(num);
            auto prev_it = prev(it);
            auto next_it = next(it);

            if(abs(*prev_it - num) <= *next_it - num) ans = *prev_it;
            else ans = *next_it;
            nums.erase(num);
        }    
        cout << ans << endl;
    }

    return 0;

}