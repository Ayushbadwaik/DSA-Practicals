#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct DataItem {
    int key;
    int value;
};

struct DataItem* hashArray[SIZE];

int hashCode(int key) {
    return key % SIZE;
}

void insert(int key, int value) {
    struct DataItem* item = (struct DataItem*) malloc(sizeof(struct DataItem));
    item->key = key;
    item->value = value;
    int hashIndex = hashCode(key);

    while (hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1) {
        hashIndex++;
        hashIndex %= SIZE;
    }
    hashArray[hashIndex] = item;
}

struct DataItem* search(int key) {
    int hashIndex = hashCode(key);

    while (hashArray[hashIndex] != NULL) {
        if (hashArray[hashIndex]->key == key)
            return hashArray[hashIndex];
        hashIndex++;
        hashIndex %= SIZE;
    }
    return NULL;
}

void delete(int key) {
    int hashIndex = hashCode(key);

    while (hashArray[hashIndex] != NULL) {
        if (hashArray[hashIndex]->key == key) {
            struct DataItem* temp = hashArray[hashIndex];
            hashArray[hashIndex] = NULL;
            free(temp);
            return;
        }
        hashIndex++;
        hashIndex %= SIZE;
    }
}

void display() {
    for (int i = 0; i < SIZE; i++) {
        if (hashArray[i] != NULL)
            printf("(%d, %d) ", hashArray[i]->key, hashArray[i]->value);
        else
            printf("~~ ");
    }
    printf("\n");
}

int main() {
    int choice, key, value;
    
    while (1) {
        printf("\n1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter key and value: ");
                scanf("%d %d", &key, &value);
                insert(key, value);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                struct DataItem* item = search(key);
                if (item != NULL)
                    printf("Element found: (%d, %d)\n", item->key, item->value);
                else
                    printf("Element not found\n");
                break;
            case 3:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                delete(key);
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    
    return 0;
}
