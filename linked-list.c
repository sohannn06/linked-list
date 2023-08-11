#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


void insertEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}


void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

t
void sortList(struct Node* head) {
    int swapped;
    struct Node* current;
    struct Node* last = NULL;

    
    if (head == NULL)
        return;

    do {
        swapped = 0;
        current = head;

        while (current->next != last) {
            if (current->data > current->next->data) {
                
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = 1;
            }
            current = current->next;
        }
        last = current;

    } while (swapped);
}


void deleteElement(struct Node** head, int value) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = *head;
    struct Node* prev = NULL;

    while (current != NULL) {
        if (current->data == value) {
            if (prev == NULL) {
                *head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("Deleted %d: ", value);
            printList(*head);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Number not found.\n");
}

int main() {
    struct Node* head = NULL;
    int num;

   
    printf("Enter numbers (enter 0 to stop):\n");
    do {
        scanf("%d", &num);
        if (num != 0) {
            insertEnd(&head, num);
        }
    } while (num != 0);

    
    sortList(head);

    
    printf("Enter numbers to delete (enter 0 to stop):\n");
    do {
        scanf("%d", &num);
        if (num != 0) {
            deleteElement(&head, num);
        }
    } while (num != 0);

   
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
