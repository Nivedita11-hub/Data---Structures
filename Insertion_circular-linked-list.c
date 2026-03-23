#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Helper function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 1. Insert into an empty list
void insertInEmpty(struct Node** head, int data) {
    if (*head != NULL) {
        printf("List is not empty.\n");
        return;
    }
    struct Node* newNode = createNode(data);
    *head = newNode;
    // The most crucial step for a CLL: point the node to itself
    newNode->next = *head; 
}

// 2. Insert at the beginning (Head)
void insertAtBeginning(struct Node** head, int data) {
    if (*head == NULL) {
        insertInEmpty(head, data);
        return;
    }

    struct Node* newNode = createNode(data);
    struct Node* temp = *head;

    // Traverse to the last node to update its 'next' pointer
    while (temp->next != *head) {
        temp = temp->next;
    }

    // Connect the new node
    newNode->next = *head; // New node points to the current head
    temp->next = newNode;  // Last node points to the new node
    *head = newNode;       // Update the head pointer
}

// 3. Insert at the end (Tail)
void insertAtEnd(struct Node** head, int data) {
    if (*head == NULL) {
        insertInEmpty(head, data);
        return;
    }

    struct Node* newNode = createNode(data);
    struct Node* temp = *head;

    // Traverse to the last node
    while (temp->next != *head) {
        temp = temp->next;
    }

    // Connect the new node
    temp->next = newNode;  // Last node points to the new node
    newNode->next = *head; // New node points back to the head
    // Note: We do NOT update *head here.
}

// 4. Insert after a specific value
void insertAfterValue(struct Node** head, int valueToFind, int data) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = *head;

    // Search for the value
    do {
        if (temp->data == valueToFind) {
            struct Node* newNode = createNode(data);
            
            // Insert the new node after 'temp'
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    } while (temp != *head);

    printf("Value %d not found in the list.\n", valueToFind);
}

// Helper function to print the list
void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    
    printf("(HEAD: %d)\n", head->data); // Show that it loops back
}

// Main function to test the operations
int main() {
    struct Node* head = NULL;

    printf("--- Insertion Operations ---\n");
    
    // 1. Empty List
    insertInEmpty(&head, 10);
    printList(head);

    // 2. At Beginning
    insertAtBeginning(&head, 5);
    printList(head);

    // 3. At End
    insertAtEnd(&head, 20);
    printList(head);

    // 4. After a specific value (insert 15 after 10)
    insertAfterValue(&head, 10, 15);
    printList(head);

    // Try finding a value that doesn't exist
    insertAfterValue(&head, 100, 25);

    return 0;
}