#include<stdio.h>
#define SIZE 4

int Queue[SIZE];

int Front = -1;
int Rear = -1;

void enqueue(int data)
{
    if(Front==-1)
    {
        Front = Rear = 0;
        Queue[Front] = data;
    }
    else
    {
        int dummy_Rear = (Rear+1)%SIZE;
        if(dummy_Rear == Front)
        {
            printf("Queue Overflow\n");
        }
        else
        {
            Rear = dummy_Rear;
            Queue[Rear] = data;
        }
    }

}

void dequeue()
{
    if(Front==-1)
    {
        printf("Queue Underflow\n");
    }
    else if(Front==Rear)
    {
        printf("%d\n", Queue[Front]);
        Queue[Front] = 0;
        Front = Rear = -1;
    }
    else
    {
        printf("%d\n", Queue[Front]);
        Queue[Front] = 0;
        Front = (Front+1)%SIZE;
    }
}

int main()
{
    enqueue(10);
    enqueue(15);
    enqueue(16);
    enqueue(20);
    enqueue(25);
    dequeue();
    enqueue(25);
    dequeue();
    dequeue();
    dequeue();

    dequeue();
    return 0;
}
