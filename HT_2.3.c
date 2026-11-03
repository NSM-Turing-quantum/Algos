#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void print(struct Node* head)
{
    struct Node* temp = head;

    while (temp->next != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("%d \n", temp->data);
}

void freeList(struct Node* head)
{
    struct Node* temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}


struct Node* deleteNode(struct Node* head, int val)
{
    while (head != NULL && head->data == val)
    {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    if (head == NULL) {
        return NULL;
    }

    struct Node* curr = head;

    while (curr->next != NULL)
    {
        if (curr->next->data == val)
        {
            struct Node* temp = curr->next;
            curr->next = curr->next->next;
            free(temp);
        }
        else
        {
            curr = curr->next;
        }
    }

    return head;
}

int main()
{
    struct Node* head = createNode(1);
    head->next = createNode(1);
    head->next->next = createNode(2);
    head->next->next->next = createNode(3);
    head->next->next->next->next = createNode(4);
    head->next->next->next->next->next = createNode(5);

    printf("My List:  ");
    print(head);
    printf("\n");

    head = deleteNode(head, 1);
    printf("Result, 1 del:    ");
    print(head);
    printf("\n");

    head = deleteNode(head, 3);
    printf("Result, 3 del:    ");
    print(head);
    printf("\n");

    head = deleteNode(head, 33);
    printf("Result, 33 del:    ");
    print(head);

    freeList(head);

    return 0;
}
