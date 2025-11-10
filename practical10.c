/* AIM : Assume that you have a seven slots closed hash table ( the slots are numbered 0 through 6) . 
 Write c program to find hash table that would result if you used the hash function h(k) - k mod 7 .
*/

#include <stdio.h>
#define SIZE 7  

int hashFunction(int key) {
    return key % SIZE;
}

void insert(int hashTable[], int key) {
    int index = hashFunction(key);
    int startIndex = index; 

    while (hashTable[index] != -1) {
        index = (index + 1) % SIZE;
        if (index == startIndex) {
            printf("Hash table is full! Cannot insert %d\n", key);
            return;
        }
    }
    hashTable[index] = key;
}

void display(int hashTable[]) {
    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] != -1)
            printf("Slot %d --> %d\n", i, hashTable[i]);
        else
            printf("Slot %d --> NULL\n", i);
    }
}

int main() {
    int hashTable[SIZE];
    int n, key;

    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;

    printf("Enter number of keys to insert: ");
    scanf("%d", &n);

    printf("Enter %d keys:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        insert(hashTable, key);
    }

    display(hashTable);
    return 0;
}