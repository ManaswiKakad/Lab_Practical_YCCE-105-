/* 
 AIM : Write a program to Implement a menu driven Program in C for the following operations on STACK of Integers [Array Implementation of Stack with maximum size MAX)
 a. Push an Element on to Stack
 b. Pop an Element from Stack
 c. Demonstrate how Stack can be used to check Palindrome
 d. Demonstrate Overflow and Underflow situations on Stack
 e. Display the status of Stack
 f. Exit
 Support the program with appropriate functions for each of the above operations
*/

#include <stdio.h>
#include <string.h>
#define MAX 100

int stack[MAX];
int top = -1;

int isFull() {
    return top == MAX - 1;
}

int isEmpty() {
    return top == -1;
}

void push(int value) {
    if (isFull()) {
        printf("\nStack Overflow! Cannot push %d\n", value);
    } else {
        stack[++top] = value;
        printf("%d pushed onto stack.\n", value);
    }
}

int pop() {
    if (isEmpty()) {
        printf("\nStack Underflow! Cannot pop element.\n");
        return -1;
    } else {
        int value = stack[top--];
        printf("%d popped from stack.\n", value);
        return value;
    }
}

void display() {
    if (isEmpty()) {
        printf("\nStack is empty.\n");
    } else {
        printf("\nCurrent Stack:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

void checkPalindrome() {
    char str[50];
    char rev[50];
    int i;

    printf("Enter a string or number to check palindrome: ");
    scanf("%s", str);

    for (i = 0; str[i] != '\0'; i++) {
        if (isFull()) {
            printf("Stack Overflow while checking palindrome!\n");
            return;
        }
        stack[++top] = str[i];
    }

    int j = 0;
    while (!isEmpty()) {
        rev[j++] = stack[top--];
    }
    rev[j] = '\0';

    if (strcmp(str, rev) == 0)
        printf("'%s' is a Palindrome.\n", str);
    else
        printf("'%s' is NOT a Palindrome.\n", str);
}

int main() {
    int choice, value;

    do {
        printf("\n------ STACK OPERATIONS MENU ------\n");
        printf("1. Push an element onto Stack\n");
        printf("2. Pop an element from Stack\n");
        printf("3. Check Palindrome using Stack\n");
        printf("4. Demonstrate Overflow and Underflow\n");
        printf("5. Display Stack\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                top = -1;  
                checkPalindrome();
                break;

            case 4:
                printf("\n--- Demonstrating Overflow ---\n");
                top = MAX - 1;
                push(100);

                printf("\n--- Demonstrating Underflow ---\n");
                top = -1;
                pop(); 
                break;

            case 5:
                display();
                break;

            case 6:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);
    return 0;
}