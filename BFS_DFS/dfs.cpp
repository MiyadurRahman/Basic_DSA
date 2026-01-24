#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct ListNode
{
    int data;
    struct ListNode* next;
};
typedef struct ListNode ListNode;


ListNode* createListNode(int data)
{
    ListNode* temp = (ListNode *)malloc(sizeof(ListNode));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

/// Stack Start Here

ListNode* top = NULL;


void push(int data)
{
    if(top==NULL)
    {
        top = createListNode(data);
    }
    else
    {
        ListNode* temp = createListNode(data);
        temp->next = top;
        top = temp;
    }

}

int pop()
{
    if(top==NULL)
    {
        return -1;
    }
    else
    {
        ListNode* temp = top;
        top = top->next;
        int data = temp->data;
        free(temp);
        return data;
    }
}

bool isStackEmpty()
{
    if(top==NULL)
        return true;
    else
        return false;
}

/// Queue End Here

ListNode* addAdjacent(ListNode* head, int data)
{
    if(head==NULL)
    {
        head = createListNode(data);
        return head;
    }
    else
    {
        ListNode* temp = createListNode(data);
        temp->next = head;
        head = temp;
        return head;
    }
}

void printNeighbors(ListNode* head)
{
    for(ListNode* i = head; i!=NULL; i=i->next)
    {
        printf("%d ", i->data);
    }
    printf("\n");
}

void printPath(int parent[], int node)
{
    if(parent[node]==node)
    {
        printf("%d ", node);
        return;
    }
    else
    {
        printPath(parent, parent[node]);
        printf("%d ", node);
    }
}

int main()
{
    int V = 5;
    ListNode* graph[V] = {NULL};

    graph[0] = addAdjacent(graph[0], 2);
    graph[0] = addAdjacent(graph[0], 1);


    graph[1] = addAdjacent(graph[1], 3);
    graph[1] = addAdjacent(graph[1], 2);

    graph[2] = addAdjacent(graph[2], 3);

    graph[3] = addAdjacent(graph[3], 0);

    graph[4] = addAdjacent(graph[4], 3);


    for(int i=0; i<V; i++)
    {
        printf("%d -> ", i);
        printNeighbors(graph[i]);
    }

    /// BFS starts here

    int visited[V] = {0};
    int parent[V];
    for(int i=0; i<V; i++)
    {
        parent[i] = -1;
    }

    int source = 1;

    push(source);
    visited[source] = 1;
    parent[source] = source;

    printf("Explore Sequence: ");


    while(isStackEmpty()!=true)
    {
        int current_node = pop();
        printf("%d ", current_node);

        for(ListNode* neighbor = graph[current_node]; neighbor!=NULL; neighbor=neighbor->next)
        {
            int data = neighbor->data;
            if(visited[data]==0)
            {
                push(data);
                visited[data] = 1;
                parent[data] = current_node;
            }
        }
    }

    printf("\nVisited Array: ");
    for(int i=0; i<V; i++)
    {
        printf("%d ", visited[i]);
    }

    printf("\nParent Array: ");
    for(int i=0; i<V; i++)
    {
        printf("%d ", parent[i]);
    }

    printf("\n");

    printPath(parent, 1);

    return 0;
}


 