#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertAtFront(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    newNode->next = head;
    head->prev = newNode;
    return newNode;
}

struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
    return head;
}

struct Node* insertAfterNode(struct Node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("Invalid previous node\n");
        return NULL;
    }
    struct Node* newNode = createNode(data);
    newNode->next = prevNode->next;
    newNode->prev = prevNode;
    if (prevNode->next != NULL) {
        prevNode->next->prev = newNode;
    }
    prevNode->next = newNode;
    return newNode;
}

struct Node* deleteFromFront(struct Node* head) {
    if (head == NULL) {
        printf("List is empty. Cannot delete from the front.\n");
        return NULL;
    }
    struct Node* newHead = head->next;
    free(head);
    if (newHead != NULL) {
        newHead->prev = NULL;
    }
    return newHead;
}

struct Node* deleteFromEnd(struct Node* head) {
    if (head == NULL) {
        printf("List is empty. Cannot delete from the end.\n");
        return NULL;
    }
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    if (current->prev != NULL) {
        current->prev->next = NULL;
    }
    free(current);
    return head;
}

struct Node* deleteNode(struct Node* head, struct Node* deleteNode) {
    if (head == NULL || deleteNode == NULL) {
        printf("Invalid parameters\n");
        return head;
    }
    if (deleteNode->prev != NULL) {
        deleteNode->prev->next = deleteNode->next;
    }
    if (deleteNode->next != NULL) {
        deleteNode->next->prev = deleteNode->prev;
    }
    free(deleteNode);
    return head;
}

void traverseList(struct Node* head) {
    printf("Doubly Linked List: ");
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    head = insertAtFront(head, 10);
    head = insertAtFront(head, 20);
    head = insertAtFront(head, 30);

    traverseList(head);

    head = insertAtEnd(head, 40);
    head = insertAtEnd(head, 50);

    traverseList(head);

    struct Node* secondNode = head->next;
    head = insertAfterNode(secondNode, 25);

    traverseList(head);

    head = deleteFromFront(head);

    traverseList(head);

    head = deleteFromEnd(head);

    traverseList(head);

    head = deleteNode(head, secondNode);

    traverseList(head);

    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

