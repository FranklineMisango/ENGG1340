#include <stdlib.h>
#include <stdio.h>

//Malloc was failing after not being declared 
//as an int functions explicitly
void update(int *a, int *b) {
    int *p = (int*) malloc(sizeof(int));
    int *z = (int*) malloc(sizeof(int));
    *p = *a + *b;
    *z = abs(*a - *b);
    *a = *p;
    *b = *z;
    free(p);
    free(z);
}


int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
