/*      Stack (FIFO)
    First in, firt out
    add at the front and pop from the front
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

node *stack = NULL;

// Stack prototypes functions
void push(int a);
int pop(void);

int main(void)
{
    push(123);
    push(907);
    push(-45);
    push(3);
    int a = pop();
    int b = pop();
    int c = pop();
    int d = pop();
    // int e = pop(); just retuned INT_MIN and not printed, since printf comes after

    return 0;
}

void push(int a)
{
    node *temp = malloc(sizeof(node));
    if (temp == NULL)
        return;
    temp->number = a;
    temp->next = stack;
    stack = temp;
    printf("%d is added!\n", a);
}

int pop(void)
{
    if (stack == NULL)
        return INT_MIN;
    int a = stack->number;
    node *temp = stack;
    stack = stack->next;
    free(temp);

    printf("%d is popped!\n", a);
    return a;
}