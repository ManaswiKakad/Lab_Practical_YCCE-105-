/*
 AIM : This C program creates a linked list in store integer elements. 
 It prompts the users to enter elements  and add them to the list until users enter 0.
 It then traverse the list and prints each elements "=>" until reaching the null pointers .
 Finally it displays the number of nodes in the list .
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node *head = NULL, *newNode, *temp;
    int value, count = 0;

    printf("Enter integers to add to the linked list (enter 0 to stop):\n");

    while (1) {
        scanf("%d", &value);
        if (value == 0)
            break;  

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode; 
        } else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
        count++;
    }

    printf("\nLinked List Elements:\n");
    temp = head;
    while (temp != NULL) {
        printf("%d => ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    printf("\nTotal number of nodes in the list: %d\n", count);
    return 0;
}