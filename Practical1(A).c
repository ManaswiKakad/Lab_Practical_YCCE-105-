// Write a program to accept a 'n' numbers into an array and then calculate the sum of 
// numbers present in odd positions and even positions respectively. 

#include<stdio.h>

int main() {
    int n, i;
    int sumOddPos = 0, sumEvenPos = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++) {ṇ
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++) {
        if ((i + 1) % 2 == 0) {
            sumEvenPos += arr[i]; 
        } else {
            sumOddPos += arr[i];   
        }
    }

    printf("Sum of numbers at odd positions: %d\n", sumOddPos);
    printf("Sum of numbers at even positions: %d\n", sumEvenPos);

    return 0;
}