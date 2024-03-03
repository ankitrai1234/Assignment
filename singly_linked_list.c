#include <stdio.h>
#include <stdlib.h>
struct list {
    int val;
    struct list* next;
};
void insertionFromFront(struct list** head, int x) {
    struct list* add = (struct list*)malloc(sizeof(struct list));
    if (add == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    add->val = x;
    add->next = *head;
    *head = add;
}
void insertionFromBack(struct list* head, int x) {
    while (head->next != NULL) {
        head = head->next;
    }

    struct list* add = (struct list*)malloc(sizeof(struct list));
    if (add == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    add->val = x;
    add->next = NULL;
    head->next = add;
}

void insertionFromMiddle(struct list* ptr, int x) {
    if (ptr == NULL) {
        printf("Invalid pointer\n");
        return;
    }

    struct list* add = (struct list*)malloc(sizeof(struct list));
    if (add == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    add->val = x;
    add->next = ptr->next;
    ptr->next = add;
}

void deleteFromFront(struct list** head) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete from the front.\n");
        return;
    }

    struct list* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteFromBack(struct list* head) {
    if (head == NULL) {
        printf("List is empty. Cannot delete from the back.\n");
        return;
    }

    struct list* temp = NULL;
    while (head->next != NULL) {
        temp = head;
        head = head->next;
    }

    if (temp != NULL) {
        temp->next = NULL;
        free(head);
    }
}

void deleteFromMiddle(struct list* head, int x) {
    if (head == NULL) {
        printf("List is empty. Cannot delete from the middle.\n");
        return;
    }

    struct list* current = head;
    struct list* prev = NULL;

    while (current != NULL && current->val != x) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Node with value %d not found\n", x);
        return;
    }

    if (prev != NULL) {
        prev->next = current->next;
        free(current);
    }
}
void traverseList(struct list* head) {
    printf("Linked List: ");
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct list* head = (struct list*)malloc(sizeof(struct list));
    if (head == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    head->val = 10;
    head->next = NULL;
    insertionFromFront(&head, 5);
    insertionFromBack(head, 15);
    insertionFromMiddle(head, 8);
    struct list* current = head;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
    deleteFromFront(&head);
    current = head;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
    deleteFromBack(head);
    current = head;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
    deleteFromMiddle(head, 8);
    current = head;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
    traverseList(head);
    while (head != NULL) {
        struct list* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

