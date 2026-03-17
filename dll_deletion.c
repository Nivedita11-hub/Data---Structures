#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// --- HELPER TO BUILD LIST ---
void basicInsert(struct Node** head) {
    int value;
    printf("Enter value to add to list: ");
    scanf("%d", &value);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("Added %d to the list.\n", value);
}

// --- DELETION FUNCTIONS ---

void deleteFromBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    printf("Deleted %d from the beginning.\n", temp->data);
    free(temp);
}

void deleteFromEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }
    struct Node* temp = *head;
    if (temp->next == NULL) {
        *head = NULL;
        printf("Deleted %d (the only node).\n", temp->data);
        free(temp);
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    printf("Deleted %d from the end.\n", temp->data);
    free(temp);
}

void deleteFromPosition(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    int pos;
    printf("Enter the position to delete (1-based): ");
    scanf("%d", &pos);

    if (pos == 1) {
        deleteFromBeginning(head);
        return;
    }

    struct Node* temp = *head;
    for (int i = 1; temp != NULL && i < pos; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds!\n");
        return;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    printf("Deleted %d from position %d.\n", temp->data, pos);
    free(temp);
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
        printf("\n--- Doubly Linked List: Deletion ---\n");
        printf("1. Add a Node (Setup)\n2. Delete from Beginning\n3. Delete from End\n4. Delete from Position\n5. Display List\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: basicInsert(&head); break;
            case 2: deleteFromBeginning(&head); break;
            case 3: deleteFromEnd(&head); break;
            case 4: deleteFromPosition(&head); break;
            case 5: displayList(head); break;
            case 6: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}