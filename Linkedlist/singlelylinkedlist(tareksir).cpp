#include<stdio.h>
#include<stdlib.h>

struct ListNode
{
    int data;
    struct ListNode *next;
};

typedef struct ListNode ListNode;


ListNode *createListNode(int user_data)
{
    ListNode* temp = (ListNode *)malloc(sizeof(ListNode));
    temp->data = user_data;
    temp->next = NULL;
    return temp;
}

void printList(ListNode* head)
{
    for(ListNode* i=head; i!=NULL; i=i->next)
    {
        printf("%d ", i->data);
    }
    printf("\n");
}

ListNode* linear_search(ListNode* head, int key)
{
    for(ListNode* i=head; i!=NULL; i=i->next)
    {
        if(i->data==key)
        {
            return i;
        }
    }
    return NULL;
}

int count_nodes(ListNode* head)
{
    int counter = 0;
    for(ListNode* i=head; i!=NULL; i=i->next)
    {
        counter++;
    }
    return counter;
}

ListNode *insertFirst(ListNode* head, int new_data)
{
    if(head==NULL)
    {
        head = createListNode(new_data);
        return head;
    }
    else
    {
        ListNode* temp = createListNode(new_data);
        temp->next = head;
        head = temp;
        return head;
    }
}

ListNode* insertLast(ListNode* head, int new_data)
{
    if(head==NULL)
    {
        head = createListNode(new_data);
        return head;
    }
    else
    {
        ListNode* last_element = head;
        while(last_element->next!=NULL)
        {
            last_element = last_element->next;
        }

        ListNode* temp = createListNode(new_data);
        last_element->next = temp;
        return head;
    }
}

ListNode* insert_after(ListNode* head, int key, int new_data)
{
    ListNode* loc = linear_search(head, key);
    if(loc==NULL)
    {
        return head;
    }
    else
    {
        ListNode* temp = createListNode(new_data);

        temp->next = loc->next;
        loc->next = temp;
        return head;
    }
}

ListNode* delete_first(ListNode* head)
{
    if(head==NULL)
    {
        return head;
    }
    else
    {
        ListNode* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
}

ListNode* delete_last(ListNode* head)
{
    if(head==NULL)
    {
        return head;
    }
    else if(head->next==NULL)
    {
        free(head);
        head = NULL;
        return head;
    }
    else
    {
        ListNode* second_last_element = head;
        while(second_last_element->next->next!=NULL)
        {
            second_last_element = second_last_element->next;
        }

        free(second_last_element->next);
        second_last_element->next = NULL;
        return head;
    }
}

ListNode* delete_any(ListNode* head, int key)
{
    if(head==NULL)
    {
        return head;
    }
    else if(head->data == key)
    {
        return delete_first(head);
    }
    else
    {
        ListNode* i = head;
        while(i->next!=NULL && i->next->data!=key)
        {
            i = i->next;
        }

        if(i->next==NULL) /// key is absent in the list
        {
            return head;
        }


        /// key is present in the list

        ListNode* temp = i->next;
        i->next = i->next->next; /// i->next = temp->next;
        free(temp);
        return head;
    }
}

ListNode* reverse_list(ListNode* head)
{
    if(head==NULL)
        return head;

    ListNode* back = NULL;
    ListNode* current = head;
    ListNode* front = head->next;

    while(current!=NULL)
    {
        current->next = back;

        back = current;
        current = front;
        if(front!=NULL) front = front->next;
    }
    return back;
}

void printList_reverse(ListNode* head)
{
    if(head==NULL)
        return;
    else
    {
        printList_reverse(head->next);
        printf("%d ", head->data);
    }
}

ListNode* insert_at(ListNode* head, int position, int new_data)
{
    if(position==1)
    {
        return insertFirst(head, new_data);
    }
    else
    {
        int current_position= 1;
        ListNode *loc = head;

        while(loc!=NULL && current_position<position-1)
        {
            current_position++;
            loc = loc->next;
        }

        if(loc==NULL)
            return head;

        ListNode* temp = createListNode(new_data);
        temp->next = loc->next;
        loc->next = temp;
        return head;

    }
}

ListNode* find_middle_node(ListNode *head)
{
    ListNode* hare = head;
    ListNode* tortoise = head;

    while(hare!=NULL && hare->next!= NULL)
    {
        hare = hare->next->next;
        tortoise = tortoise->next;
    }
    return tortoise;
}

int main()
{
    ListNode* head = NULL;
    head = createListNode(5);
    head->next = createListNode(6);
    head->next->next = createListNode(7);
    head->next->next->next = createListNode(8);
    head->next->next->next->next = createListNode(9);


    printList(head);



    head = insertLast(head, 15);
    printList(head);

    head = insertLast(head, 16);
    printList(head);


    head = insertFirst(head, 2);
    printList(head);

    head = insert_after(head, 7, 10);
    printList(head);


    head = delete_first(head);
    printList(head);

    head = delete_first(head);
    printList(head);

    head = delete_last(head);
    printList(head);

    head = delete_any(head, 8);
    printList(head);


    head = insert_at(head, 4, 100);
    printList(head);

    head = delete_last(head);
    printList(head);


    ListNode* middle_node = find_middle_node(head);
    printf("%d\n", middle_node->data);

    return 0;
}

