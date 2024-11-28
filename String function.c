include <stdio.h>
int main() {
    char str1[100], str2[100], str3[200];
    int length, comparison;

    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0'; 

    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0'; 

    length = strlen(str1);
    printf("Length of the first string ('%s') is: %d\n", str1, length);

    strcpy(str3, str1);
    printf("After copying, str3 contains: '%s'\n", str3);

    comparison = strcmp(str1, str2);
    if (comparison == 0) {
        printf("The two strings are equal.\n");
    } else if (comparison > 0) {
        printf("The first string ('%s') is greater than the second string ('%s').\n", str1, str2);
    } else {
        printf("The first string ('%s') is less than the second string ('%s').\n", str1, str2);
    }
  
    strcat(str3, str2);
    printf("After concatenation, str3 contains: '%s'\n", str3);

    return 0;
}
