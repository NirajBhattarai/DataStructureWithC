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
// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    struct Node *next;
    int data;
} Node;

Node* head = NULL;

void insertAtBegining(int data)
{
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = head;
    head = node;
}

void insertAtLast(int data)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if(head==NULL)
    {
        head =newNode;
    }
    Node *last = head;
    while(last->next!=NULL)
    {
        last = last->next;
    }
    last->next = newNode;
}

void insertAfterNode(int position,int data)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data=data;
    
    Node* temp =head;
    
    while(position--&&temp->next!=NULL)
    {
       temp=temp->next; 
    }
    if(temp==NULL)
    {
        printf("out of bounds");
        return;
    }
    newNode->next= temp->next;
    temp->next = newNode;
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
   insertAfterNode(0,10);
   
   printList();

    return 0;
}


```

```
class Node {
    Node next;
    int data;
}

class LinkedList {
    Node head;

    void insertAtBeginning(int data) {
        Node newNode = new Node();
        newNode.data = data;
        newNode.next = head;
        head = newNode;
    }

    void insertAtLast(int data) {
        Node newNode = new Node();
        newNode.data = data;
        newNode.next = null;
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
        Node newNode = new Node();
        newNode.data = data;
        
        Node temp = head;
        while (position-- > 0 && temp != null) {
            temp = temp.next;
        }
        
        if (temp == null) {
            System.out.println("Position out of bounds");
            return;
        }
        
        newNode.next = temp.next;
        temp.next = newNode;
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
        linkedList.insertAtLast(2);
        linkedList.insertAtLast(3);
        linkedList.insertAtBeginning(0);
        linkedList.insertAfterNode(0, 10);

        linkedList.printList();
    }
}


```