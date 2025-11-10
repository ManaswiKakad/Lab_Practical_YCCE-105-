/* 
 AIM : Write a program to Implement a menu driven Program in C for the following operations 
 on QUEUE of Characters (Array Implementation of Queue with maximum size MAX)
 a. Insert an Element on to QUEUE
 b. Delete an Elements from QUEUE
 c. Demonstrate Overflow and Underflow situations on QUEUE
 d. Display the status of QUEUE
 e. Exit
 Support the program with appropriate functions for each of the above operations.
*/

#include <stdio.h>
#define MAX 100

char queue[MAX];
int front = -1, rear = -1;

int isFull() {
    return rear == MAX - 1;
}

int isEmpty() {
    return front == -1 || front > rear;
}

void insert(char value) {
    if (isFull()) {
        printf("\nQueue Overflow! Cannot insert '%c'.\n", value);
    } else {
        if (front == -1)
            front = 0;
        queue[++rear] = value;
        printf("'%c' inserted into the queue.\n", value);
    }
}

void delete() {
    if (isEmpty()) {
        printf("\nQueue Underflow! Cannot delete element.\n");
    } else {
        printf("'%c' deleted from the queue.\n", queue[front]);
        front++;
    }
}

void display() {
    if (isEmpty()) {
        printf("\nQueue is empty.\n");
    } else {
        printf("\nCurrent Queue: ");
        for (int i = front; i <= rear; i++) {
            printf("%c ", queue[i]);
        }
        printf("\n");
    }
}

void demonstrateOverflowUnderflow() {
    printf("\n--- Demonstrating Overflow ---\n");
    rear = MAX - 1;
    insert('X'); 

    printf("\n--- Demonstrating Underflow ---\n");
    front = -1;
    rear = -1;
    delete();     
}

int main() {
    int choice;
    char value;

    do {
        printf("\n------ QUEUE OPERATIONS MENU ------\n");
        printf("1. Insert an element into Queue\n");
        printf("2. Delete an element from Queue\n");
        printf("3. Demonstrate Overflow and Underflow situations\n");
        printf("4. Display Queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a character to insert: ");
                scanf(" %c", &value);
                insert(value);
                break;

            case 2:
                delete();
                break;

            case 3:
                demonstrateOverflowUnderflow();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);
    return 0;
}