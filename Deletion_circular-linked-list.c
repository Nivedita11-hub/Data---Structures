#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Helper function to create a node (used for setup)
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Helper to add nodes to the end (for testing setup)
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

// 1. Delete the Head Node
void deleteHead(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct Node* temp = *head;
    struct Node* last = *head;

    // Case 1: Only one node in the list
    if (temp->next == *head) {
        *head = NULL;
        free(temp);
        return;
    }

    // Case 2: More than one node
    // Find the last node to update its 'next' pointer
    while (last->next != *head) {
        last = last->next;
    }

    // Update pointers and free memory
    last->next = temp->next; // Last node points to the 2nd node
    *head = temp->next;      // Head shifts to the 2nd node
    free(temp);              // Delete the old head
}

// 2. Delete the Tail Node
void deleteTail(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;

    // Case 1: Only one node
    if (temp->next == *head) {
        *head = NULL;
        free(temp);
        return;
    }

    // Case 2: More than one node
    // Traverse to the last node, keeping track of the previous node
    while (temp->next != *head) {
        prev = temp;
        temp = temp->next;
    }

    // Update the second-to-last node to point to the head
    prev->next = *head;
    free(temp); // Delete the tail
}

// 3. Delete a Node with a Specific Value
void deleteByValue(struct Node** head, int value) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* curr = *head;
    struct Node* prev = NULL;

    // Case 1: The value to delete is at the head
    if (curr->data == value) {
        deleteHead(head);
        return;
    }

    // Case 2: Value is somewhere else. Traverse to find it.
    do {
        prev = curr;
        curr = curr->next;
        
        if (curr->data == value) {
            // Bypass the current node
            prev->next = curr->next;
            free(curr);
            return;
        }
    } while (curr->next != *head);

    printf("Value %d not found in the list.\n", value);
}

// Helper function to print the list
void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(HEAD: %d)\n", head->data);
}

// Main function to demonstrate deletion
int main() {
    struct Node* head = NULL;

    // Setup: Create a list -> 10 -> 20 -> 30 -> 40 -> 50 -> (HEAD)
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);
    
    printf("Initial ");
    printList(head);

    printf("\n--- Deleting Head (10) ---\n");
    deleteHead(&head);
    printList(head);

    printf("\n--- Deleting Tail (50) ---\n");
    deleteTail(&head);
    printList(head);

    printf("\n--- Deleting Specific Value (30) ---\n");
    deleteByValue(&head, 30);
    printList(head);

    printf("\n--- Trying to Delete Value Not in List (100) ---\n");
    deleteByValue(&head, 100);

    return 0;
}