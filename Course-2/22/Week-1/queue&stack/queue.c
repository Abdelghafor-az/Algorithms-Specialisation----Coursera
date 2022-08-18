#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

node *front = NULL;
node *rear = NULL;

void enqueue(int a);
int dequeue(void);
void print_queue(void);

int main(void)
{
    enqueue(1);
    enqueue(-23);
    enqueue(17);
    enqueue(39);
    int x = dequeue();
    // int y = dequeue();
    // printf("%d-%d\n", x, y);
    print_queue();

    return 0;
}

void enqueue(int a)
{
    node *temp = malloc(sizeof(node));
    if (temp == NULL)
        return;
    else {
        temp->number = a;
        temp->next = NULL;
    }

    // if It's the first node added, front also should point to it
    if (front == NULL && rear == NULL)
    {
        front = rear = temp;
        // printf("%d is added\n", a);
        return;
    }
    rear->next = temp;
    rear = temp;
    // printf("%d is added\n", a);
}

int dequeue(void)
{
    if (front == NULL)
        printf("the queue is empty\n");
    node *temp = front;
    int a = front->number;
    if (front == NULL)
        return -1;
    if (front == rear)
        front = rear = NULL;
    else
        front = front->next;
    free(temp);
    // printf("%d removed\n", a);
    return a;
}

void print_queue(void)
{
    printf("[ ");
    for (node *temp = front; temp != NULL; temp = temp->next)
        printf("%d ", temp->number);
    printf("]");
}