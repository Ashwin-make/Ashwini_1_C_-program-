#include <stdio.h>

int main() {
    int num = 10;     
    int *ptr = &num; 

    printf("Value of num: %d\n", num);
    printf("Address of num: %p\n", &num);
    printf("Value using pointer: %d\n", *ptr);

    *ptr = 20;
    printf("Value of num after modification: %d\n", num);

    return 0;
}
