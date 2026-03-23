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

// --- The Core Search Function ---
// Returns the position (1-based index) if found, or -1 if not found
int searchElement(struct Node* head, int target) {
    // 1. Handle empty list
    if (head == NULL) {
        return -1; 
    }

    struct Node* current = head;
    int position = 1; // Start counting from position 1

    // 2. Traverse the list using do-while
    do {
        // 3. Check if current node holds the target data
        if (current->data == target) {
            return position; // Element found, return its position
        }
        
        // Move to the next node and increment position
        current = current->next;
        position++;
        
    } while (current != head); // 4. Stop when we wrap around to the head

    // 5. If the loop completes, the element is not in the list
    return -1;
}

// Helper function to print the list
void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(HEAD)\n");
}

int main() {
    struct Node* head = NULL;

    // Setup: Build a list -> 10 -> 20 -> 30 -> 40 -> 50
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);

    printf("Current List: ");
    printList(head);
    printf("\n");

    // Test cases for searching
    int targets[] = {30, 10, 50, 100};
    int numTargets = 4;

    for (int i = 0; i < numTargets; i++) {
        int target = targets[i];
        int position = searchElement(head, target);

        if (position != -1) {
            printf("Element %d found at position %d.\n", target, position);
        } else {
            printf("Element %d not found in the list.\n", target);
        }
    }

    return 0;
}