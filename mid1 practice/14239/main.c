#include <stdio.h>
#include <stdlib.h>

int distance[1005];
int student[1005];
int disp[1005] ={0};

int main(){
    int N;
    scanf("%d", &N);
    student[1] = 0;
    for(int i = 2; i <= N; i++){
        scanf("%d", &student[i]);
        distance[i] = student[i] == 1;
    }

    for(int i = 2; i <= N; i++){
        if(distance[i] == 0){
            if(distance[student[i]] != 0){
                distance[i] = distance[student[i]] + 1;
            }
        }
    }

    for(int i = N; i > 0; i--){
        
        disp[student[i]] += disp[i];
        disp[student[i]]++;

    }

    scanf("%d", &N);
    int type, a, b, ans = -1;
    for(int i = 0; i < N; i++){
        ans = -1;
        scanf("%d", &type);
        if(type == 1){
            scanf("%d", &a);
            printf("%d\n", disp[a]);
        }
        else{
            scanf("%d %d", &a, &b);
            int differ = 0;
            if(distance[a] > distance[b]){
                differ = distance[a] - distance[b];
                while(differ--){
                    a = student[a];
                    if(a == b){
                        ans = 0;
                        break;
                    }
                }
                

                //ans = 0
            } 
            else if(distance[a] < distance[b]){
                differ = distance[b] - distance[a];
                while(differ--){
                    b = student[b];
                    if(b == a){
                        ans = 1;
                        break;
                    }
                }
                

                //ans = 0
            }     
            printf("%d\n", ans);          
        }
    }
}