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

// Helper function to insert a node at the end (for setup)
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = *head;
}

// --- The Core Traversal Function ---
void traverseList(struct Node* head) {
    // 1. Handle the edge case of an empty list
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    // 2. Initialize a pointer to start at the head
    struct Node* current = head;

    printf("Circular Linked List Elements: ");

    // 3. Use a do-while loop for traversal
    do {
        // Print the current node's data
        printf("%d -> ", current->data);
        
        // Move to the next node
        current = current->next;
        
    } while (current != head); // 4. Stop when we loop back to the head

    printf("(Back to HEAD)\n");
}

int main() {
    struct Node* head = NULL;

    // Test Case 1: Traversing an empty list
    printf("--- Test 1: Empty List ---\n");
    traverseList(head);
    printf("\n");

    // Setup: Let's build a list: 10 -> 20 -> 30 -> 40
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);

    // Test Case 2: Traversing a populated list
    printf("--- Test 2: Populated List ---\n");
    traverseList(head);

    return 0;
}