#include <stdio.h>
#include <string.h>

struct Book {
    int id;
    char title[100];
    char author[100];
    int year;
};

void addBook() {
    struct Book book;
    FILE *file = fopen("books.dat", "ab"); 
    if (!file) {
        printf("Error opening file.\n");
        return;
    }

    printf("Enter Book ID: ");
    scanf("%d", &book.id);
    printf("Enter Book Title: ");
    scanf(" %[^\n]", book.title);
    printf("Enter Book Author: ");
    scanf(" %[^\n]", book.author);
    printf("Enter Publication Year: ");
    scanf("%d", &book.year);

    fwrite(&book, sizeof(struct Book), 1, file);
    fclose(file);

    printf("Book added successfully.\n");
}

void searchBook() {
    struct Book book;
    char title[100];
    int found = 0;

    FILE *file = fopen("books.dat", "rb");
    if (!file) {
        printf("Error opening file.\n");
        return;
    }

    printf("Enter Book Title to search: ");
    scanf(" %[^\n]", title);

    while (fread(&book, sizeof(struct Book), 1, file)) {
        if (strcasecmp(book.title, title) == 0) {
            printf("\nBook Found:\n");
            printf("ID: %d\nTitle: %s\nAuthor: %s\nYear: %d\n",
                   book.id, book.title, book.author, book.year);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }

    fclose(file);
}

void deleteBook() {
    struct Book book;
    int id, found = 0;

    FILE *file = fopen("books.dat", "rb"); 
    FILE *tempFile = fopen("temp.dat", "wb"); 
    if (!file || !tempFile) {
        printf("Error opening file.\n");
        return;
    }

    printf("Enter Book ID to delete: ");
    scanf("%d", &id);

    while (fread(&book, sizeof(struct Book), 1, file)) {
        if (book.id == id) {
            found = 1; 
            continue;
        }
        fwrite(&book, sizeof(struct Book), 1, tempFile);
    }

    fclose(file);
    fclose(tempFile);

    remove("books.dat");
    rename("temp.dat", "books.dat");

    if (found) {
        printf("Book deleted successfully.\n");
    } else {
        printf("Book with ID %d not found.\n", id);
    }
}

void displayBooks() {
    struct Book book;

    FILE *file = fopen("books.dat", "rb");
    if (!file) {
        printf("Error opening file.\n");
        return;
    }

    printf("\n--- Book Records ---\n");
    printf("%-10s %-30s %-30s %-10s\n", "ID", "Title", "Author", "Year");
    printf("-------------------------------------------------------------\n");

    while (fread(&book, sizeof(struct Book), 1, file)) {
        printf("%-10d %-30s %-30s %-10d\n",
               book.id, book.title, book.author, book.year);
    }

    fclose(file);
}

int main() {
    int choice;

    do {
        printf("\n--- Book Management System ---\n");
        printf("1. Add Book\n");
        printf("2. Search Book\n");
        printf("3. Delete Book\n");
        printf("4. Display All Books\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                searchBook();
                break;
            case 3:
                deleteBook();
                break;
            case 4:
                displayBooks();
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
