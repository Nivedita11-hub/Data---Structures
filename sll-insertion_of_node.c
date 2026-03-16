#include <stdio.h>
#include <stdlib.h>

// Define the structure for a Linked List node
struct Node {
    int data;
    struct Node* next;
};

// Helper function to dynamically allocate memory for a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 1. Insert at the Beginning
void insertAtBeginning(struct Node** head_ref, int new_data) {
    struct Node* newNode = createNode(new_data);
    
    // Point the new node's next to the current head
    newNode->next = *head_ref;
    
    // Move the head pointer to point to the new node
    *head_ref = newNode;
}

// 2. Insert at the End
void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* newNode = createNode(new_data);
    struct Node* last = *head_ref;

    // If the linked list is empty, make the new node the head
    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }

    // Otherwise, traverse to the very last node
    while (last->next != NULL) {
        last = last->next;
    }

    // Change the next pointer of the last node to the new node
    last->next = newNode;
}

// 3. Insert at a Specific Position (k)
// Note: This assumes a 1-based index (k=1 means the very first position)
void insertAtPosition(struct Node** head_ref, int new_data, int k) {
    // Check for invalid positions
    if (k < 1) {
        printf("Invalid position!\n");
        return;
    }

    // If inserting at the first position, it's the same as insertAtBeginning
    if (k == 1) {
        insertAtBeginning(head_ref, new_data);
        return;
    }

    struct Node* newNode = createNode(new_data);
    struct Node* temp = *head_ref;

    // Traverse to the (k-1)th node
    for (int i = 1; temp != NULL && i < k - 1; i++) {
        temp = temp->next;
    }

    // If temp is NULL, the position k is greater than the number of nodes + 1
    if (temp == NULL) {
        printf("Position %d is out of bounds!\n", k);
        free(newNode); // Avoid memory leak
        return;
    }

    // Link the new node to the next node in the sequence
    newNode->next = temp->next;
    
    // Link the (k-1)th node to the new node
    temp->next = newNode;
}

// Helper function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    // Start with an empty list
    struct Node* head = NULL;

    printf("Building initial list...\n");
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    printList(head);

    printf("\nInserting 5 at the beginning...\n");
    insertAtBeginning(&head, 5);
    printList(head);

    printf("\nInserting 40 at the end...\n");
    insertAtEnd(&head, 40);
    printList(head);

    // Insert 25 at position 4 (List is currently: 5 -> 10 -> 20 -> 30 -> 40)
    printf("\nInserting 25 at position 4...\n");
    insertAtPosition(&head, 25, 4); 
    printList(head);

    // Testing an out-of-bounds position
    printf("\nTrying to insert 99 at position 10...\n");
    insertAtPosition(&head, 99, 10); 

    return 0;
}