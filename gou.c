#include <stdio.h>/*-456y78uiopl'/

0#include <stdlib.h>

typedef struct Queue
{
  int data;
  struct Queue *next;
} QueueNode;

typedef struct
{
  QueueNode *front;
  QueueNode *rear;
} Queue;

QueueNode *getnode()
{
  QueueNode *newnode = (QueueNode *)malloc(sizeof(QueueNode));
  printf("Enter the data: ");
  scanf("%d", &newnode->data);
  newnode->next = NULL;
  return newnode;
}

void enqueue(Queue *queue{
  QueueNode *newnode = getnode();

  if (queue->rear == NULL)
  {
    // If the queue is empty, make the new node as the front and rear
    queue->front = newnode;
    queue->rear = newnode;
  }
  else
  {
    // Add the new node at the end and update the rear
    queue->rear->next = newnode;
    queue->rear = newnode;
  }
}

void dequeue(Queue *queue)
{
  if (queue->front == NULL)
  {
    printf("Queue is empty\n");
    return;
  }

  QueueNode *temp = queue->front;
  printf("Dequeued element is %d\n", temp->data);

  // Move the front pointer to the next node and free the memory of the dequeued node
  queue->front = queue->front->next;
  free(temp);

  // If the queue becomes empty after dequeue, update the rear to NULL as well
  if (queue->front == NULL)
  {
    queue->rear = NULL;
  }
}

void display(Queue *queue)
{
  if (queue->front == NULL)
  {
    printf("The queue is empty\n");
    return;
  }

  QueueNode *cur = queue->front;
  printf("Queue elements: ");

  while (cur != NULL)
  {
    printf("%d ", cur->data);
    cur = cur->next;
  }

  printf("\n");
}

int main()
{
  Queue queue;
  queue.front = NULL;
  queue.rear = NULL;
  int choice;

  while (1)
  {
    printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      enqueue(&queue);
      break;
    case 2:
      dequeue(&queue);
      break;
    case 3:
      display(&queue);
      break;
    case 4:
      exit(0);
    default:
      printf("Invalid choice\n");
      break;
    }
  }

  return 0;
}
