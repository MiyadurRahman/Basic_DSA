#include<stdio.h>
#include<stdlib.h>

struct ListNode
{
    int data;
    struct ListNode *next;
    struct ListNode *prev;
};

typedef struct ListNode ListNode;

ListNode *createListNode(int user_data)
{
    ListNode* temp = (ListNode *)malloc(sizeof(ListNode));
    temp->data = user_data;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}


/**
    a->next = b
    b->prev = a

**/

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
        head->prev = temp; /// newly added line
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
        temp->prev = last_element; /// newly added line
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
        loc->next->prev = temp;

        loc->next = temp;
        temp->prev = loc;

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
        head->prev = NULL;
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
        i->next = temp->next;
        temp->next->prev = i;


        free(temp);
        return head;
    }
}

int main()
{

    ListNode* head = NULL;



    return 0;
}
