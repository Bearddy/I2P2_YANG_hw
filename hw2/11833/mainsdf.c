#include <stdio.h>

int from[200000];
int arr[200000];
int post_arr[200000];

void parse(int arr_l, int arr_r, int pre_l) {
    if (arr_l > arr_r) return;


    parse(arr_l, from[pre_arr[pre_l]] - 1, pre_l + 1);
    parse(from[pre_arr[pre_l]] + 1, arr_r, pre_l + from[pre_arr[pre_l]] - arr_l + 1);
    printf("%d ", pre_arr[pre_l]);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        from[arr[i]] = i;
    }
    for (int i = 0; i < n; i++) scanf("%d", &post_arr[i]);

    for(int i = n -1; i >=0; i--){
        int temp = post_arr[i];
        post_arr[i] = post_arr[n - i - 1];
        
    }

    parse(0, n - 1, 0);
    printf("\n");
}