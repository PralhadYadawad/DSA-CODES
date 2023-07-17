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
QUEUE dequeue2(QUEUE top);
QUEUE copy(QUEUE top,QUEUE another);
void display(QUEUE top);
QUEUE enqueue2(QUEUE top);
int main()
{
    QUEUE top;
    top=NULL;
    int m;
    while(1)
    {
        printf("1:Enqueue from top 2:enqueue from bottom 3:Remove from bottom 4:remove from top 5:display 6:Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&m);
        if(m==1)
        {
            top=enqueue(top);
        }
        else if(m==2)
        {
            top=enqueue2(top);
        }
        else if(m==3)
        {
            top=dequeue(top);
        }
        else if(m==4)
        {
            top=dequeue2(top);
        }
        else if(m==5)
        {
            display(top);
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
QUEUE enqueue2(QUEUE top)
{
    QUEUE cur,newnode;
   newnode=createnode();
    if(top==NULL)
    {
        top=newnode;
        top->link=NULL;
    }
    else
    {
        newnode->link=top;
        top=newnode;
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
QUEUE dequeue2(QUEUE top)
{
    QUEUE cur,prev;
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
        cur=top;
        prev=cur;
        while(cur->link!=NULL)
        {
            prev=cur;
            cur=cur->link;
        }
        prev->link=NULL;
        free(cur);
        cur=prev;
    }
    return top;
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
            printf("%d\n",cur->data);
             printf("^\n");
            cur=cur->link;
        }
        printf("\n");
    }
}
