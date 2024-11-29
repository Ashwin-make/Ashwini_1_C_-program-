include <stdio.h>
#include <string.h>

struct Book {
    char title[100];
    char author[50];
    int publicationYear;
    float price;
};

int main() {
    int n, i;

    printf("Enter the number of books: ");
    scanf("%d", &n);

    struct Book books[n];

    for (i = 0; i < n; i++) {
        printf("\n--- Enter details for Book %d ---\n", i + 1);
        getchar(); 

        printf("Enter Title: ");
        fgets(books[i].title, sizeof(books[i].title), stdin);
        books[i].title[strcspn(books[i].title, "\n")] = '\0';

        printf("Enter Author: ");
        fgets(books[i].author, sizeof(books[i].author), stdin);
        books[i].author[strcspn(books[i].author, "\n")] = '\0';

        printf("Enter Publication Year: ");
        scanf("%d", &books[i].publicationYear);

        printf("Enter Price: ");
        scanf("%f", &books[i].price);
    }

    printf("\n--- Book Details ---\n");
    for (i = 0; i < n; i++) {
        printf("\nBook %d\n", i + 1);
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("Publication Year: %d\n", books[i].publicationYear);
        printf("Price: $%.2f\n", books[i].price);
    }

    return 0;
}
