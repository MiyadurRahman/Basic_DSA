#include <stdio.h>
struct customer
{
    char name[100];
    int number;
    int points;
};
int main()
{
    int N;
    scanf("%d", &N);
    struct customer customers[100];

    for (int i = 0; i < N; i++)
    {
        printf("Enter name: ");
        getchar(); // to consume newline character
        gets(customers[i].name);
        printf("Enter number: ");
        scanf("%d", &customers[i].number);
        printf("Enter points: ");
        scanf("%d", &customers[i].points);
    }
    while (1)
    {
        printf("0.add new student information\n1.show the information\n.2.kth most valuable customer\n3.exit\n4.THEIR TOP STANDING POSITION\n");

        int choice;
        scanf("%d ", &choice);
        if (choice == 1)
        {
            for (int i = 0; i < N; i++)
            {
                printf("Name: %s\n", customers[i].name);
                printf("Number: %d\n", customers[i].number);
                printf("Points: %d\n", customers[i].points);
            }
        }
        if (choice == 0)
        {
            printf("Enter name: ");
            getchar(); // to consume newline character
            gets(customers[N].name);
            printf("Enter number: ");
            scanf("%d", &customers[N].number);
            printf("Enter points: ");
            scanf("%d", &customers[N].points);
            N++;
        }
        else if (choice == 2)
        {
            int k;
            scanf("%d", &k);
            // sort by points
            for (int i = 0; i < N - 1; i++)
            {
                for (int j = i + 1; j < N; j++)
                {
                    if (customers[j].points > customers[i].points)
                    {
                        struct customer temp = customers[i];
                        customers[i] = customers[j];
                        customers[j] = temp;
                    }
                }
            }
            printf("Kth most valuable customer:\n");
            printf("Name: %s\n", customers[k - 1].name);
            printf("Number: %d\n", customers[k - 1].number);
            printf("Points: %d\n", customers[k - 1].points);
        }
         else if (choice == 4)
        {
            // sort by points (highest first)
            for (int i = 0; i < N - 1; i++)
            {
                for (int j = i + 1; j < N; j++)
                {
                    if (customers[j].points > customers[i].points)
                    {
                        struct customer temp = customers[i];
                        customers[i] = customers[j];
                        customers[j] = temp;
                    }
                }
            }

            printf("\n--- Customer Standings ---\n");
            for (int i = 0; i < N; i++)
            {
                printf("Position %d: %s (Number: %d)\n", i + 1, customers[i].name, customers[i].number);
            }
        }
        else if (choice == 3)
        {
            break;
        }
       
    }
}