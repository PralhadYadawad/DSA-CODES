#include<stdio.h>
#include<stdlib.h>

struct Node
{
    char name[20];
    int rno;
    struct Node *next;
};

typedef struct Node* node;
node head, newnode, temp, cur;

node getnode();
node read_details(node newnode);
node insertend(node head);
node insertbeg(node head);
node insertpos(node head);
node deleteend(node head);
node deletebeg(node head);
node deletepos(node head);
void display(node head);

int main()
{
    int choice;
    while(1)
    {
        printf("\n1->Insert at the end\n2->Insert at the beginning\n3->Insert at a specified position\n4->Display\n5->Delete from the end\n6->Delete from the beginning\n7->Delete from a specified position\n8->Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                head = insertend(head);
                break;
            case 2:
                head = insertbeg(head);
                break;
            case 3:
                head = insertpos(head);
                break;
            case 4:
                display(head);
                break;
            case 5:
                head = deleteend(head);
                break;
            case 6:
                head = deletebeg(head);
                break;
            case 7:
                head = deletepos(head);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid input\n");
                break;
        }
    }
}

node getnode()
{
    newnode = (node)malloc(sizeof(struct Node));
    if (newnode == NULL)
    {
        printf("Memory not allocated\n");
        exit(0);
    }
    return newnode;
}

node read_details(node newnode)
{
    printf("Enter the name and roll no: ");
    scanf("%s%d", newnode->name, &newnode->rno);
    newnode->next = NULL;
    return newnode;
}

node insertend(node head)
{
    newnode = getnode();
    newnode = read_details(newnode);
    if (head == NULL)
    {
        head = newnode;
        return head;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        return head;
    }
}

node insertbeg(node head)
{
    newnode = getnode();
    newnode = read_details(newnode);
    if (head == NULL)
    {
        head = newnode;
        return head;
    }
    else
    {
        newnode->next = head;
        head = newnode;
        return head;
    }
}

node insertpos(node head)
{
    int pos, i;
    printf("Enter the position to insert the node: ");
    scanf("%d", &pos);
    if (pos < 1)
    {
        printf("Invalid position\n");
        return head;
    }

    if (pos == 1)
    {
        head = insertbeg(head);
        return head;
    }
    else
    {
        temp = head;
        for (i = 1; i < pos - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            printf("Position exceeds the length of the list\n");
            return head;
        }
        else
        {
            newnode = getnode();
            newnode = read_details(newnode);
            newnode->next = temp->next;
            temp->next = newnode;
            return head;
        }
    }
}

void display(node head)
{
    if (head == NULL)
    {
        printf("Linked list is empty\n");
    }
    else
    {
        temp = head;
        while (temp != NULL)
        {
            printf("%s%d->", temp->name, temp->rno);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

node deleteend(node head)
{
    if (head == NULL)
    {
        printf("Linked list is empty\n");
        return head;
    }
    else
    {
        if (head->next == NULL)
        {
            printf("Deleted: %s%d\n", head->name, head->rno);
            free(head);
            head = NULL;
            return head;
        }
        else
        {
            temp = head;
            cur = head->next;
            while (cur->next != NULL)
            {
                temp = temp->next;
                cur = cur->next;
            }
            printf("Deleted: %s%d\n", cur->name, cur->rno);
            free(cur);
            temp->next = NULL;
            return head;
        }
    }
}

node deletebeg(node head)
{
    if (head == NULL)
    {
        printf("Linked list is empty\n");
        return head;
    }
    else
    {
        temp = head;
        head = head->next;
        printf("Deleted: %s%d\n", temp->name, temp->rno);
        free(temp);
        return head;
    }
}

node deletepos(node head)
{
    int pos, i;
    printf("Enter the position to delete the node: ");
    scanf("%d", &pos);
    if (pos < 1)
    {
        printf("Invalid position\n");
        return head;
    }

    if (pos == 1)
    {
        head = deletebeg(head);
        return head;
    }
    else
    {
        temp = head;
        for (i = 1; i < pos - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }
        if (temp == NULL || temp->next == NULL)
        {
            printf("Position exceeds the length of the list\n");
            return head;
        }
        else
        {
            cur = temp->next;
            temp->next = cur->next;
            printf("Deleted: %s%d\n", cur->name, cur->rno);
            free(cur);
            return head;
        }
    }
}
