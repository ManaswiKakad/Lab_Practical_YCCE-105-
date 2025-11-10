/*
 AIM: Write a program to implement a Binary Search algorithm. Write a search function which takes a Stacchist as its first parameter and a Comparable as its second. If either parameter is null or if the Searchlast is Last is empty, you should return NULL
 implement the following algorithm Examine the value in the middle of the current array and print it.
 If the midpoint value is the value that we are looking for return true
 If the value that we are looking for is greater than the midpoint value, adjust the current array to start at the midpoint and print the indes.
 if the value that we are looking for is less than the midpoint value, adjust the current array to end at the midpoint and prior the indes
 Continue until you find the value, or until the start reaches the end.
*/

#include <stdio.h>

int binarySearch(int arr[], int n, int key) {
   
    if (arr == NULL || n == 0) {
        return -1; 
    }

    int start = 0, end = n - 1;

    while (start <= end) {
        int mid = (start + end) / 2;

        printf("Examining value at index %d: %d\n", mid, arr[mid]);

        if (arr[mid] == key) {
            printf("Value found at index %d\n", mid);
            return mid;
        } else if (key > arr[mid]) {
            printf("Target is greater than midpoint, adjusting start to %d\n", mid + 1);
            start = mid + 1;
        } else {
            printf("Target is less than midpoint, adjusting end to %d\n", mid - 1);
            end = mid - 1;
        }
    }

    printf("Value not found in the list.\n");
    return -1; 
}

int main() {
    int n, key;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Empty list, returning NULL.\n");
        return 0;
    }

    int arr[n];

    printf("Enter %d sorted numbers (in ascending order):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the number to search: ");
    scanf("%d", &key);

    int result = binarySearch(arr, n, key);

    if (result != -1)
        printf("Search successful: Element found at index %d\n", result);
    else
        printf("Search unsuccessful: Element not found.\n");

    return 0;
}