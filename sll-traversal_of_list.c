#include <stdio.h>
#include <stdlib.h>

// Define the structure for a Linked List node
struct Node {
    int data;
    struct Node* next;
};

// --- TRAVERSAL FUNCTION ---
void traverseAndPrint(struct Node* head) {
    // 1. Create a temporary pointer and start it at the head
    struct Node* temp = head;

    // 2. Check if the list is empty
    if (temp == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("Linked List values: ");

    // 3. Loop through the list until temp reaches NULL
    while (temp != NULL) {
        // Print the data inside the current node
        printf("%d -> ", temp->data);
        
        // Move the temp pointer to the next node
        temp = temp->next;
    }
    
    // 4. Print NULL at the end to represent the end of the list
    printf("NULL\n");
}

// Quick main function to test it
int main() {
    // Manually creating three nodes for testing
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));

    // Assigning data and linking the nodes
    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

    // Call the traversal function
    traverseAndPrint(head);

    return 0;
}