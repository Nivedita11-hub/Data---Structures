#include <stdio.h>
#include <stdlib.h>

// Define the structure for a Doubly Linked List node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// --- 1. Helper function to add nodes (so we have data to traverse/search) ---
void insertNode(struct Node** head) {
    int value;
    printf("Enter the value to insert: ");
    scanf("%d", &value);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    // If the list is empty, make the new node the head
    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
    } else {
        // Otherwise, traverse to the end and attach it
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("Node with value %d added successfully!\n", value);
}

// --- 2. Forward Traversal ---
void traverseForward(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    printf("Forward Traversal: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// --- 3. Reverse Traversal ---
void traverseReverse(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    
    // Move to the very last node
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    // Traverse backwards using 'prev' pointers
    printf("Reverse Traversal: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

// --- 4. Search for a specific value ---
void searchList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    
    int key, pos = 1, found = 0;
    printf("Enter the value to search for: ");
    scanf("%d", &key);

    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Value %d found at position %d!\n", key, pos);
            found = 1;
            break;
        }
        temp = temp->next;
        pos++;
    }
    
    if (!found) {
        printf("Value %d is not present in the list.\n", key);
    }
}

// --- 5. Count Total Nodes ---
void countNodes(struct Node* head) {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("Total number of nodes in the list: %d\n", count);
}

// --- 6. Find Middle Element (Slow & Fast Pointer) ---
void findMiddle(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    
    struct Node* slow = head;
    struct Node* fast = head;

    // Fast moves 2 steps, slow moves 1 step
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    printf("The middle element is: %d\n", slow->data);
}

// --- MAIN FUNCTION (Program Entry Point) ---
int main() {
    struct Node* head = NULL;
    int choice;

    while (1) {
        printf("\n=========================================\n");
        printf("  Doubly Linked List: Traversals & Ops   \n");
        printf("=========================================\n");
        printf("1. Add a Node (Setup data)\n");
        printf("2. Forward Traversal\n");
        printf("3. Reverse Traversal\n");
        printf("4. Search for a Value\n");
        printf("5. Count Total Nodes\n");
        printf("6. Find Middle Element\n");
        printf("7. Exit\n");
        printf("-----------------------------------------\n");
        printf("Enter your choice (1-7): ");
        
        // Read user choice
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                insertNode(&head); 
                break;
            case 2: 
                traverseForward(head); 
                break;
            case 3: 
                traverseReverse(head); 
                break;
            case 4: 
                searchList(head); 
                break;
            case 5: 
                countNodes(head); 
                break;
            case 6: 
                findMiddle(head); 
                break;
            case 7: 
                printf("Exiting program...\n");
                exit(0);
            default: 
                printf("Invalid choice! Please select between 1 and 7.\n");
        }
    }
    
    return 0; // This guarantees the compiler knows the main function ends here
}