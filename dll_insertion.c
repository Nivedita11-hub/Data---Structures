#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// --- INSERTION FUNCTIONS ---

void insertAtBeginning(struct Node** head) {
    int value;
    printf("Enter the value to insert at the beginning: ");
    scanf("%d", &value);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = *head;

    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
    printf("Node inserted!\n");
}

void insertAtEnd(struct Node** head) {
    int value;
    printf("Enter the value to insert at the end: ");
    scanf("%d", &value);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        printf("Node inserted as the first element!\n");
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    printf("Node inserted at the end!\n");
}

void insertAtPosition(struct Node** head) {
    int value, pos;
    printf("Enter the position (1-based): ");
    scanf("%d", &pos);
    
    if (pos < 1) {
        printf("Invalid position!\n");
        return;
    }
    if (pos == 1) {
        // Redirect to insert at beginning logic without asking for value again
        printf("Enter the value: ");
        scanf("%d", &value);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->prev = NULL;
        newNode->next = *head;
        if (*head != NULL) (*head)->prev = newNode;
        *head = newNode;
        printf("Node inserted!\n");
        return;
    }

    printf("Enter the value to insert: ");
    scanf("%d", &value);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    struct Node* temp = *head;

    for (int i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    printf("Node inserted at position %d!\n", pos);
}

void displayList(struct Node* node) {
    if (node == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Current List: ");
    while (node != NULL) {
        printf("%d <-> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice;

    while (1) {
        printf("\n--- Doubly Linked List: Insertion ---\n");
        printf("1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n4. Display List\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertAtBeginning(&head); break;
            case 2: insertAtEnd(&head); break;
            case 3: insertAtPosition(&head); break;
            case 4: displayList(head); break;
            case 5: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}