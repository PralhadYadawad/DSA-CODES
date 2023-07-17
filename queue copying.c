#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int data;
    struct queue *link;
};
typedef struct queue *QUEUE;
QUEUE createnode();
QUEUE enqueue(QUEUE top);
QUEUE dequeue(QUEUE top);
QUEUE copy(QUEUE top,QUEUE another);
void display(QUEUE top);
QUEUE enqueue2(QUEUE cur,QUEUE another);
int main()
{
    QUEUE top,another=NULL;
    top=NULL;
    int m;
    while(1)
    {
        printf("1:Enqueue 2:Dequeue 3:display 4:copy 5:Displayed copied 6:Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&m);
        if(m==1)
        {
            top=enqueue(top);
        }
        else if(m==2)
        {
            top=dequeue(top);
        }
        else if(m==3)
        {
            display(top);
        }
        else if(m==4)
        {
            another=copy(top,another);
        }
        else if(m==5)
        {
            display(another);
            another=NULL;
        }
        else if(m==6)
        {
            exit(0);
        }
        else
        {
            printf("invalid choice\n");
        }
    }
}
QUEUE createnode()
{
    QUEUE newnode;
    newnode=malloc(sizeof(struct queue));
    printf("Enter the data that you want to enqueue\n");
    scanf("%d",&newnode->data);
    newnode->link=NULL;
    return newnode;
}
QUEUE enqueue(QUEUE top)
{
    QUEUE newnode,cur;
    newnode=createnode();
    if(top==NULL)
    {
        top=newnode;
        top->link=NULL;
    }
    else
    {
        cur=top;
        while(cur->link!=NULL)
        {
            cur=cur->link;
        }
        cur->link=newnode;
        newnode->link=NULL;
    }
    return top;
}
QUEUE dequeue(QUEUE top)
{
    QUEUE cur;
    if(top==NULL)
    {
        printf("The queue is empty\n");
    }
    else if(top->link==NULL)
    {
        free(top);
        top=NULL;
    }
    else
    {
        cur=top->link;
        free(top);
        top=cur;
    }
    return top;
}
QUEUE enqueue2(QUEUE cur,QUEUE another)
{
    QUEUE newnode,tp;
    newnode=malloc(sizeof(struct queue));
    newnode->data=cur->data;
    if(another==NULL)
    {
        another=newnode;
        another->link=NULL;
    }
    else
    {
        tp=another;
        while(tp->link!=NULL)
        {
            tp=tp->link;
        }
        tp->link=newnode;
        newnode->link=NULL;
    }
    return another;
}
QUEUE copy(QUEUE top,QUEUE another)
{
    QUEUE cur;
    cur=top;
    if(top==NULL)
    {
        printf("The queue is empty\n");
    }
    else
    {
        cur=top;
        while(cur!=NULL)
        {
            another=enqueue2(cur,another);
            cur=cur->link;
        }
    }
    return another;
}
void display(QUEUE top)
{
    QUEUE cur;
    if(top==NULL)
    {
        printf("THe queue is empty");
    }
    else
    {
        cur=top;
        while(cur!=NULL)
        {
            printf("\n");
            printf("%d",cur->data);
            printf(" %xf",cur->link);
            cur=cur->link;
        }
        printf("\n");
    }
}
