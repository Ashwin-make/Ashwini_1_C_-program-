#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isPasswordStrong(const char *password) {
    int hasUpper = 0, hasLower = 0, hasDigit = 0, hasSpecial = 0;
    int length = strlen(password);

    if (length < 8) {
        printf("Password must be at least 8 characters long.\n");
        return 0;
    }

    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) hasUpper = 1;
        else if (islower(password[i])) hasLower = 1;
        else if (isdigit(password[i])) hasDigit = 1;
        else if (ispunct(password[i])) hasSpecial = 1;
    }

    if (!hasUpper) {
        printf("Password must contain at least one uppercase letter.\n");
        return 0;
    }
    if (!hasLower) {
        printf("Password must contain at least one lowercase letter.\n");
        return 0;
    }
    if (!hasDigit) {
        printf("Password must contain at least one digit.\n");
        return 0;
    }
    if (!hasSpecial) {
        printf("Password must contain at least one special character.\n");
        return 0;
    }

    return 1; 
}

int main() {
    char password[100];
    printf("Enter a password: ");
    scanf("%s", password);

    if (isPasswordStrong(password)) {
        printf("Password is strong.\n");
    } else {
        printf("Password does not meet the criteria.\n");
    }

    return 0;
}
