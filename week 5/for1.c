#include <stdio.h>
int main() {
    int mark [5];
    for (int i = 0; i < 5; i++) {
        printf("Enter mark %d\n", i+1);
        scanf("%d", mark[i]);
    }
    return 0;
} 