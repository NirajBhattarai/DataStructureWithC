## Introduction

Linked lists are a linear data structure where each element points to the next. Unlike arrays, linked lists do not store data contiguously in memory. This allows for efficient insertion and removal of nodes.


## Linked List as an ADT
An Abstract Data Type (ADT) is a high-level description of how data is viewed and the operations that can be performed on the data. It encapsulates the data and hides the implementation details from the user. The user interacts with the data through the interface provided by the ADT.

1. Creation: Initializes a new linked list, usually creating the head node.

2. Insertion: Adds a new node at a specified position.

3. Insert At Beginning: Adds a new node at the start of the list.
4. Insert At End: Adds a new node at the end of the list.
5. Insert After Node: Adds a new node after a specified node.
6. Deletion: Removes a node from a specified position.

7. Delete At Beginning: Removes the node at the start of the list.
8. Delete At End: Removes the node at the end of the list.
9. Delete Specific Node: Removes a specified node.
10. Traversal: Moves through the list, often to print the elements or perform an operation on each node.

11. Searching: Finds the position of a node containing a given value.

12. Update: Modifies the value of a node.

13. Length: Returns the number of nodes in the list.

14. IsEmpty: Checks if the list is empty.

15. Clear: Removes all nodes from the list.

As an ADT, a linked list provides an abstract layer for the operations, while the underlying implementation details may vary. For instance, you could implement a linked list using an array, dynamic memory (nodes and pointers), etc.


## program 

```
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;

// Function to check if the list is empty
int isEmpty() {
    return head == NULL;
}

// Function to return the length of the list
int length() {
    int count = 0;
    Node* current = head;
    while(current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Function to insert at the beginning
void insertAtBeginning(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

// Function to insert at the end
void insertAtEnd(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if(head == NULL) {
        head = newNode;
        return;
    }

    Node* last = head;
    while(last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}

// Function to insert after a node
void insertAfterNode(int position, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    Node* temp = head;

    while(position-- && temp != NULL) {
        temp = temp->next;
    }
    if(temp == NULL) {
        printf("Position out of bounds\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to delete a node at a given position
void deleteNode(int position) {
    if(isEmpty()) {
        printf("List is empty\n");
        return;
    }
    Node* temp = head;
    if(position == 0) {
        head = temp->next;
        free(temp);
        return;
    }
    for(int i=0; temp!=NULL && i<position-1; i++) {
        temp = temp->next;
    }
    if(temp == NULL || temp->next == NULL) {
        printf("Position out of bounds\n");
        return;
    }
    Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

// Function to traverse the list and print elements
void printList() {
    Node* temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to search for a node
int search(int data) {
    Node* temp = head;
    int position = 0;
    while(temp != NULL) {
        if(temp->data == data) {
            return position;
        }
        position++;
        temp = temp->next;
    }
    return -1; // if element is not found
}

// Function to update a node
void update(int position, int data) {
    Node* temp = head;
    while(position-- && temp != NULL) {
        temp = temp->next;
    }
    if(temp == NULL) {
        printf("Position out of bounds\n");
        return;
    }
    temp->data = data;
}

// Function to clear the list
void clear() {
    Node* current = head;
    Node* next;
    while(current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
}

int main() {
    int choice, data, position;

    while(1) {
        printf("\n\n**** MENU ****\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert After Node\n");
        printf("4. Delete Node\n");
        printf("5. Display List\n");
        printf("6. Search Element\n");
        printf("7. Update Node\n");
        printf("8. List Length\n");
        printf("9. Clear List\n");
        printf("10. Check if List is Empty\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 3:
                printf("Enter position and data: ");
                scanf("%d %d", &position, &data);
                insertAfterNode(position, data);
                break;
            case 4:
                printf("Enter position: ");
                scanf("%d", &position);
                deleteNode(position);
                break;
            case 5:
                printList();
                break;
            case 6:
                printf("Enter element to search: ");
                scanf("%d", &data);
                position = search(data);
                if(position == -1) {
                    printf("Element not found in the list\n");
                } else {
                    printf("Element found at position: %d\n", position);
                }
                break;
            case 7:
                printf("Enter position and new data: ");
                scanf("%d %d", &position, &data);
                update(position, data);
                break;
            case 8:
                printf("Length of the list: %d\n", length());
                break;
            case 9:
                clear();
                printf("List cleared\n");
                break;
            case 10:
                if(isEmpty()) {
                    printf("List is empty\n");
                } else {
                    printf("List is not empty\n");
                }
                break;
            case 11:
                return 0;
            default:
                printf("Invalid choice, please enter valid choice\n");
        }
    }
    return 0;
}


```

```
import java.util.*;

public class LinkedListOperations {
    private Node head;
    private int size;

    private class Node {
        int data;
        Node next;
    }

    public LinkedListOperations() {
        head = null;
        size = 0;
    }

    public boolean isEmpty() {
        return (size == 0);
    }

    public int getSize() {
        return size;
    }

    public void insertAtBeginning(int data) {
        Node newNode = new Node();
        newNode.data = data;
        newNode.next = head;
        head = newNode;
        size++;
    }

    public void insertAtEnd(int data) {
        if(head == null) {
            insertAtBeginning(data);
        } else {
            Node newNode = new Node();
            newNode.data = data;
            newNode.next = null;

            Node current = head;
            while(current.next != null) {
                current = current.next;
            }
            current.next = newNode;
            size++;
        }
    }

    public void insertAfterPosition(int data, int position) {
        if(position < 0 || position > size) {
            System.out.println("Invalid position");
            return;
        }

        if(position == 0) {
            insertAtBeginning(data);
            return;
        }

        Node newNode = new Node();
        newNode.data = data;

        Node current = head;
        for(int i = 1; i < position; i++) {
            current = current.next;
        }

        newNode.next = current.next;
        current.next = newNode;
        size++;
    }

    public void deleteAtPosition(int position) {
        if(position < 0 || position >= size) {
            System.out.println("Invalid position");
            return;
        }

        if(position == 0) {
            head = head.next;
            size--;
            return;
        }

        Node current = head;
        for(int i = 1; i < position; i++) {
            current = current.next;
        }

        current.next = current.next.next;
        size--;
    }

    public void display() {
        Node current = head;
        while(current != null) {
            System.out.print(current.data + " ");
            current = current.next;
        }
        System.out.println();
    }

    public boolean search(int data) {
        Node current = head;
        while(current != null) {
            if(current.data == data) {
                return true;
            }
            current = current.next;
        }
        return false;
    }

    public void updateAtPosition(int data, int position) {
        if(position < 0 || position >= size) {
            System.out.println("Invalid position");
            return;
        }

        Node current = head;
        for(int i = 0; i < position; i++) {
            current = current.next;
        }

        current.data = data;
    }

    public static void main(String[] args) {
        LinkedListOperations list = new LinkedListOperations();
        Scanner scanner = new Scanner(System.in);

        while(true) {
            System.out.println("\n1. Insert at beginning");
            System.out.println("2. Insert at end");
            System.out.println("3. Insert after position");
            System.out.println("4. Delete at position");
            System.out.println("5. Display list");
            System.out.println("6. Search for element");
            System.out.println("7. Update element at position");
            System.out.println("8. Check if list is empty");
            System.out.println("9. Get list size");
            System.out.println("10. Exit");
            System.out.println("Enter your choice: ");

            int choice = scanner.nextInt();
            int position, data;

            switch(choice) {
                case 1:
                    System.out.println("Enter data: ");
                    data = scanner.nextInt();
                    list.insertAtBeginning(data);
                    break;
                case 2:
                    System.out.println("Enter data: ");
                    data = scanner.nextInt();
                    list.insertAtEnd(data);
                    break;
                case 3:
                    System.out.println("Enter position and data: ");
                    position = scanner.nextInt();
                    data = scanner.nextInt();
                    list.insertAfterPosition(data, position);
                    break;
                case 4:
                    System.out.println("Enter position: ");
                    position = scanner.nextInt();
                    list.deleteAtPosition(position);
                    break;
                case 5:
                    list.display();
                    break;
                case 6:
                    System.out.println("Enter element to search: ");
                    data = scanner.nextInt();
                    if(list.search(data)) {
                        System.out.println("Element found in the list");
                    } else {
                        System.out.println("Element not found in the list");
                    }
                    break;
                case 7:
                    System.out.println("Enter position and new data: ");
                    position = scanner.nextInt();
                    data = scanner.nextInt();
                    list.updateAtPosition(data, position);
                    break;
                case 8:
                    if(list.isEmpty()) {
                        System.out.println("List is empty");
                    } else {
                        System.out.println("List is not empty");
                    }
                    break;
                case 9:
                    System.out.println("Size of the list: " + list.getSize());
                    break;
                case 10:
                    scanner.close();
                    System.exit(0);
                    break;
                default:
                    System.out.println("Invalid choice, please enter a valid choice");
            }
        }
    }
}

```