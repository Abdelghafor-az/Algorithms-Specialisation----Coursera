#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
} node;

// node *list = NULL;

node *addNode(node *list, int data);
node *deleteMin(node *list, int *pn);
void printList(node *list);

int main(void)
{
    node *list = NULL;
    list = addNode(list, 2);
    list = addNode(list, 1);
    // And why the adress of list change ??!

    // I DON'T EVEN KNOW WHY I SHOULD RETURN THE ADRESS OF LIST
    // WHYYYYYY - IT SUPPOSED TO BE THE SAME
    // SUCH AS PASSING AN ARRAY => I DO MY WORK WITHOUT RETURNING IT
    // WHYY HERE I HAVE TO RETUUURN IT.

    printList(list);
    int n;
    list = deleteMin(list, &n);
    printList(list);
    printf("n is %d", n);
    return 0;
}

node *addNode(node *list, int data)
{
    node *n = malloc(sizeof(node));
    if (!n)
        return NULL;
    n->number = data;
    n->next = list;
    list = n;
    return list;
}

node *Delete(node *list, int n)
{
    node *temp1 = list;
    if (n == 1)
    {
        list = list->next;
        free(temp1);
        return list;
    }
    for (int i = 0; i < n-2; i++)
        temp1 = temp1->next;
    node *temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2);
    return list;
}

node *deleteMin(node *list, int *pn)
{
    // Find Min
    int min = __INT_MAX__;
    int counter = 1, position;
    node *tmp1 = list;
    if (!list)
    {
        printf("list is already NULL\n");
    }
    while (tmp1)
    {
        if (tmp1->number < min)
        {
            min = tmp1->number;
            position = counter;
        }
        tmp1 = tmp1->next;
        counter++;
    }
    // Delete It
    list = Delete(list, position);
    *pn = min;
    return list;
}

void printList(node *list)
{
    printf("Start printing >>> ");
    for (node *tmp = list; tmp != NULL; tmp = tmp->next)
    {
        printf(" %i ", tmp->number);
    }
    printf("\nEnd printing.\n");
}