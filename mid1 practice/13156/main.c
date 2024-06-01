#include <stdio.h>
#include <stdlib.h>


int parent[200002];
int child[200002][2];
int idx[200002];
int ans = 1;

void solve(int root, int left, int right);


int main(){
    int T;
    while(scanf("%d", &T) != EOF){

        for(int i = 0; i <= T; i++){
            parent[i] = 0;
            child[i][0] = 0;
            child[i][1] = 0;
            idx[i] = 0;            
        }

        for(int i = 1; i <= T; i++){
            scanf("%d %d", &child[i][0], &child[i][1]);
            parent[child[i][0]] = i;
            parent[child[i][1]] = i;
        }

        for(int i = 1; i <= T; i++){
            int num;
            scanf("%d", &num);
            idx[num] = i;
        }
        int root = 0;
        for(int i = 1; i <= T; i++){
            if(parent[i] == 0){
                root = i;
                break;
            }
        }
        ans = 1;
        solve(root, 1, T);
        
        printf("%s\n", ans ? "YES" : "NO");


    }
}

void solve(int root, int left, int right){
    if(ans == 0) return;
    
    if(child[root][0] && child[root][1]){
        if((idx[child[root][0]] > idx[root] && idx[child[root][0]] <= right) && (idx[child[root][1]] < idx[root] && idx[child[root][1]] >= left)){ // 0 : right, 1 : left
            solve(child[root][0], idx[root] + 1, right); //go right
            solve(child[root][1], left, idx[root] - 1); //go left
        }
        else if((idx[child[root][1]] > idx[root] && idx[child[root][1]] <= right) && (idx[child[root][0]] < idx[root] && idx[child[root][0]] >= left)){ // 1 : right, 0 : left
            solve(child[root][1], idx[root] + 1, right); //go right
            solve(child[root][0], left, idx[root] - 1); //go left
        }
        else ans = 0;
    }
    else if(child[root][0] && !child[root][1]){
        if(idx[child[root][0]] > idx[root] && idx[child[root][0]] <= right) solve(child[root][0], idx[root] + 1, right);
        else if(idx[child[root][0]] < idx[root] && idx[child[root][0]] >= left) solve(child[root][0], left, idx[root] - 1);
        else ans = 0;
    }
    else if(!child[root][0] && child[root][1]){
        if(idx[child[root][1]] > idx[root] && idx[child[root][1]] <= right) solve(child[root][1], idx[root] + 1, right);
        else if(idx[child[root][1]] < idx[root] && idx[child[root][1]] >= left) solve(child[root][1], left, idx[root] - 1);
        else ans = 0;
    }
    else return;
}