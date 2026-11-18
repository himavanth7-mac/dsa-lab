#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node
struct Node {
   int data;
   struct Node *next;
};

// Insert a node at the beginning
struct Node *insertAtBeginning(struct Node *head, int value) {
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return head;
    }

    newNode->data = value;
    newNode->next = head;
    return newNode;
}

// Insert a node at the end
struct Node *insertAtEnd(struct Node *head, int value) {
    struct Node *newNode;
    struct Node *current;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return head;
    }

    newNode->data = value;
    newNode->next = NULL;

    // If the list is empty
    if (head == NULL) {
        return newNode;
    }

    current = head;

    while (current->next != NULL) {
      current = current->next;
    }

    current->next = newNode;

    return head;
}

// Delete a node by value
struct Node *deleteByValue(struct Node *head, int value) {
   struct Node *current;
   struct Node *temp;

    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }
    // If the value is in the first node
    if (head->data == value) {
        temp = head;
        head = head->next;
        free(temp);

        return head;
    }

    current = head;

    // Search for the value
    while (current->next != NULL &&
         current->next->data != value) {
       current = current->next;
    }

    // Value not found
    if (current->next == NULL) {
        printf("Value %d not found.\n", value);
        return head;
    }

    // Delete the node
    temp = current->next;
    current->next = current->next->next;

    free(temp);

    return head;
}

// Display the linked list
void displayList(struct Node *head) {
   struct Node *current = head;

    while (current != NULL) {
      printf("%d -> ", current->data);
      current = current->next;
    }

    printf("NULL\n");
}
int main() {

    struct Node *head = NULL;

    // Insert 10, 20, 30 and 40
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);

    // Display the list
    printf("Linked List: ");
    displayList(head);

    // Delete 20
    head = deleteByValue(head, 20);

    // Delete 40
    head = deleteByValue(head, 40);

    // Display the list after deletion
    printf("After deleting 20 and 40: ");
    displayList(head);

    // Free remaining nodes
    while (head != NULL) {
       struct Node *temp = head;
       head = head->next;
       free(temp);
    }

    return 0;
}
