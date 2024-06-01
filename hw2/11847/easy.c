#include <stdio.h>

char expr[31];
int arr[4], idx;

char op();

int main() {
    scanf("%s", expr);
    for (int i = 0; i < 16; i++) {

        idx = 0;

        for (int j = 0; j < 4; j++) {

            arr[j] = (i >> (3-j)) & 1;
            printf("%d ", arr[j]);
        }

        printf("%d\n", op());
    }
}

char op() {
    char c = expr[idx];
    idx += 1;
    if (c == '|') return op() | op();
    if (c == '&') return op() & op();
    return arr[c - 'A'];
}
