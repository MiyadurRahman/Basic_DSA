#include <stdio.h>

struct Book {
    char booktitle[100];
    int isbn;
    char author_name[100];
    int publication_year;
    double Price;
};

int main() {
    int M;
    printf("Enter number of books: ");
    scanf("%d", &M);

    struct Book books[100];
    getchar(); // clear newline

    for (int i = 0; i < M; i++) {
        printf("Enter title: ");
        gets(books[i].booktitle);

        printf("Enter ISBN: ");
        scanf("%d", &books[i].isbn);
        getchar();

        printf("Enter author name: ");
        gets(books[i].author_name);

        printf("Enter publication year: ");
        scanf("%d", &books[i].publication_year);

        printf("Enter price: ");
        scanf("%lf", &books[i].Price);
        getchar();
    }

    while (1) {
        int choice;

        printf("\nSelect an option:\n");
        printf("1. Add a new book\n");
        printf("2. Search a book by ISBN\n");
        printf("3. Kth cheapest book\n");
        printf("4. Show all sorted by publication year\n");
        printf("5. Exit\n");

        scanf("%d", &choice);
        getchar();

        if (choice == 1) {
            printf("Enter new book details:\n");

            printf("Enter title: ");
            gets(books[M].booktitle);

            printf("Enter ISBN: ");
            scanf("%d", &books[M].isbn);
            getchar();

            printf("Enter author name: ");
            gets(books[M].author_name);

            printf("Enter publication year: ");
            scanf("%d", &books[M].publication_year);

            printf("Enter price: ");
            scanf("%lf", &books[M].Price);
            getchar();

            M++;
        }

        else if (choice == 2) {
            int search_isbn;
            printf("Enter ISBN to search: ");
            scanf("%d", &search_isbn);

            int found = 0;
            for (int i = 0; i < M; i++) {
                if (books[i].isbn == search_isbn) {
                    printf("\nBook Found:\n");
                    printf("Title: %s\nAuthor: %s\nPublication: %d\nPrice: %.2lf\n",
                           books[i].booktitle, books[i].author_name,
                           books[i].publication_year, books[i].Price);
                    found = 1;
                }
            }
            if (!found) printf("Not found!\n");
        }

        else if (choice == 3) {
            int k;
            printf("Enter k: ");
            scanf("%d", &k);

            if (k < 1 || k > M) {
                printf("Invalid k!\n");
                continue;
            }

            // sort by price
            for (int i = 0; i < M - 1; i++) {
                for (int j = i + 1; j < M; j++) {
                    if (books[j].Price < books[i].Price) {
                        struct Book temp = books[i];
                        books[i] = books[j];
                        books[j] = temp;
                    }
                }
            }

            printf("\n%d-th cheapest book:\n", k);
            printf("Title: %s\nAuthor: %s\nPublication: %d\nPrice: %.2lf\n",
                   books[k - 1].booktitle, books[k - 1].author_name,
                   books[k - 1].publication_year, books[k - 1].Price);
        }

        else if (choice == 4) {
            // sort by year
            for (int i = 0; i < M - 1; i++) {
                for (int j = i + 1; j < M; j++) {
                    if (books[j].publication_year < books[i].publication_year) {
                        struct Book temp = books[i];
                        books[i] = books[j];
                        books[j] = temp;
                    }
                }
            }

            printf("\nBooks sorted by publication year:\n");
            for (int i = 0; i < M; i++) {
                printf("Title: %s\nAuthor: %s\nPublication: %d\nPrice: %.2lf\n\n",
                       books[i].booktitle, books[i].author_name,
                       books[i].publication_year, books[i].Price);
            }
        }

        else if (choice == 5) {
            break;
        }

        else {
            printf("Invalid option!\n");
        }
    }

    return 0;
}
