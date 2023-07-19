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

typedef struct Node{
    struct Node *next;
    int data;
} Node;

Node* head = NULL;

void insertAtBegining(int data) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = head;
    head = node;
}

void insertAtLast(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if(head == NULL) {
        head = newNode;
    }
    else {
        Node *last = head;
        while(last->next != NULL) {
            last = last->next;
        }
        last->next = newNode;
    }
}

void insertAfterNode(int position,int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    
    Node* temp = head;
    
    while(position-- && temp != NULL) {
       temp = temp->next; 
    }
    if(temp == NULL) {
        printf("Position is out of bounds\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = head;
    head = head->next;
    free(temp);
}

void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    Node* second_last = head;
    while(second_last->next->next != NULL) {
        second_last = second_last->next;
    }
    free(second_last->next);
    second_last->next = NULL;
}

void deleteSpecificNode(int position) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = head;

    if (position == 0) {
        head = temp->next;  
        free(temp);             
        return;
    }

    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Position does not exist\n");
        return;
    }

    Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

void printList() {
    Node* temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main() {
   
   insertAtBegining(1);
   insertAtLast(2);
   insertAtLast(3);
   insertAtBegining(0);
   insertAfterNode(1,10);
   
   printList();

   deleteAtBeginning();
   printList();

   deleteAtEnd();
   printList();

   deleteSpecificNode(1);
   printList();

    return 0;
}



```

```
class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

class LinkedList {
    Node head;

    void insertAtBeginning(int data) {
        Node newNode = new Node(data);
        newNode.next = head;
        head = newNode;
    }

    void insertAtEnd(int data) {
        Node newNode = new Node(data);

        if (head == null) {
            head = newNode;
        } else {
            Node last = head;
            while (last.next != null) {
                last = last.next;
            }
            last.next = newNode;
        }
    }

    void insertAfterNode(int position, int data) {
        Node newNode = new Node(data);
        Node current = head;

        for (int i = 0; current != null && i < position; i++) {
            current = current.next;
        }

        if (current == null) {
            System.out.println("Position is out of bounds");
            return;
        }
        
        newNode.next = current.next;
        current.next = newNode;
    }

    void deleteAtBeginning() {
        if (head == null) {
            System.out.println("List is empty");
            return;
        }
        
        head = head.next;
    }

    void deleteAtEnd() {
        if (head == null) {
            System.out.println("List is empty");
            return;
        }
        
        if (head.next == null) {
            head = null;
        } else {
            Node secondLast = head;
            while (secondLast.next.next != null) {
                secondLast = secondLast.next;
            }
            secondLast.next = null;
        }
    }

    void deleteSpecificNode(int position) {
        if (head == null) {
            System.out.println("List is empty");
            return;
        }

        Node temp = head;
        if (position == 0) {
            head = temp.next;
            return;
        }

        for (int i = 0; temp != null && i < position - 1; i++) {
            temp = temp.next;
        }

        if (temp == null || temp.next == null) {
            System.out.println("Position does not exist");
            return;
        }

        temp.next = temp.next.next;
    }

    void printList() {
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }
}

public class Main {
    public static void main(String[] args) {
        LinkedList linkedList = new LinkedList();

        linkedList.insertAtBeginning(1);
        linkedList.insertAtEnd(2);
        linkedList.insertAtEnd(3);
        linkedList.insertAtBeginning(0);
        linkedList.insertAfterNode(1, 10);

        linkedList.printList();

        linkedList.deleteAtBeginning();
        linkedList.printList();

        linkedList.deleteAtEnd();
        linkedList.printList();

        linkedList.deleteSpecificNode(1);
        linkedList.printList();
    }
}



```