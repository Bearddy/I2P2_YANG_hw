#include <stdio.h>

int student[1001];
int distance[1001];


int main() {
    int n, i, flag = 1;
    scanf("%d", &n);
    distance[1] = 0;
    for (i = 2; i <= n; i++) {
        scanf("%d", &student[i]);
        distance[i] = student[i] == 1;
    }
    while(flag)
        for(i = 2; i <= n; i++){
            if(distance[i] != 1){
                if(distance[student[i]] != 0){
                    distance[i] = distance[student[i]] + 1;
                    flag++;
                }
            }
        }

    for(i = 2; i < n; i++) printf("%d ", distance[i]);
    printf("%d\n", distance[n]);

    int Q, a, b;
    scanf("%d", &Q);
    while(Q--){
        scanf("%d %d", &a, &b);
        while (b > 0 && a != -1) { 
            a = student[a]; 
            b--;
        }
        printf("%d\n", a ? a : -1); 
    }
    
}