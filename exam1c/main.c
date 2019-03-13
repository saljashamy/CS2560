#include <stdio.h>

void printMultiplicationTable(){
    int n = 0;
    printf("size: ");
    fflush(stdout);
    scanf("%d", &n);
    printf("     ");
    for(int i = 0; i < n; i++){
        printf("%-4d   ", (i+1));
    }
    printf("\n");
    printf("  +");
    for(int i = 0; i < n; i++){
        printf("%s", "-------");
    }
    printf("\n");
    for(int i = 0; i < n; i++){
        printf("%-2d|  ", (i+1));
        for(int j = 0; j < n; j++){
            printf("%-4d   ", (i+1)*(j+1));
        }
        printf("\n");
    }
    
}

int main(){
    printMultiplicationTable();
    return 0;
}