#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *str;
    int length;

    str = (char *)malloc(100 * sizeof(char));

    if (str == NULL) {
        printf("Memory allocation failed!\n");
        return 1; // Exit if memory allocation fails
    }

    printf("Enter a string: ");
    scanf(" %[^\n]", str); // Read string with spaces

    length = strlen(str);
    printf("The length of the string is: %d\n", length);

    free(str);

    return 0;
}
