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

## Linked Stacks and Queues in C

## Node
The Node struct represents a single node in the linked list. Each node has an int data field to hold the value and a Node* next field to refer to the next node in the list.

```
typedef struct Node {
    int data;
    struct Node* next;
} Node;

```

## Stack
The stack operations represent a stack data structure, which is a linear data structure that follows the LIFO (Last In First Out) principle. It is built upon the linked list operations and provides the basic operations of a stack:

1. push(int data): Adds an element to the top of the stack.
2. pop(): Removes an element from the top of the stack.
3. peek(): Returns the top element of the stack without removing it.
4. isEmptyStack(): Checks if the stack is empty.

```
#include <stdio.h>
#include <stdlib.h>

// Define Node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        printf("Heap Overflow");
        exit(0);
    }
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to check if the stack is empty
int isEmpty(Node* root) {
    return !root;
}

// Function to add an element to the stack
void push(Node** root, int data) {
    Node* node = newNode(data);
    node->next = *root;
    *root = node;
    printf("%d pushed to stack\n", data);
}

// Function to remove an element from the stack
int pop(Node** root) {
    if (isEmpty(*root))
        return -1;
    Node* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);

    return popped;
}

// Function to return the top element of the stack
int peek(Node* root) {
    if (isEmpty(root))
        return -1;
    return root->data;
}

int main() {
    Node* root = NULL;

    push(&root, 10);
    push(&root, 20);
    push(&root, 30);

    printf("Top element is %d\n", peek(root));

    printf("%d popped from stack\n", pop(&root));

    printf("Top element is %d\n", peek(root));

    return 0;
}

```

## Queue
The queue operations represent a queue data structure, which is a linear data structure that follows the FIFO (First In First Out) principle. It is also built upon the linked list operations and provides the basic operations of a queue:

1. enqueue(int data): Adds an element to the end of the queue.
2. dequeue(): Removes an element from the front of the queue.
3. peekQueue(): Returns the front element of the queue without removing it.
4. isEmptyQueue(): Checks if the queue is empty.

```
#include <stdio.h>
#include <stdlib.h>

// Define Node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// A utility function to create a new linked list node.
Node* newNode(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// The queue, front stores the front node and rear stores the last node
typedef struct Queue {
    Node *front, *rear;
} Queue;

// A utility function to create an empty queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// The function to add a data k to q
void enqueue(Queue* q, int data) {
    // Create a new node
    Node* temp = newNode(data);

    // If queue is empty, then new node is front and rear both
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }

    // Add the new node at the end of queue and change rear
    q->rear->next = temp;
    q->rear = temp;
}

// Function to remove a key from given queue q
Node* dequeue(Queue* q) {
    // If queue is empty, return NULL
    if (q->front == NULL)
        return NULL;

    // Store previous front and move front one node ahead
    Node* temp = q->front;

    q->front = q->front->next;

    // If front becomes NULL, then change rear also as NULL
    if (q->front == NULL)
        q->rear = NULL;
    
    return temp;
}

int main() {
    Queue* q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    dequeue(q);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    Node* n = dequeue(q);
    if (n != NULL)
        printf("Dequeued item is %d", n->data);

    return 0;
}

```

## Doubly Linked List in C
This project provides an implementation of a doubly linked list in C. The doubly linked list is a linear data structure that consists of nodes, where each node contains a data element and two pointers, one pointing to the previous node and the other pointing to the next node. This implementation includes operations to insert at the beginning and end, insert after a specific node, delete from the beginning, end, and a specific node, and print the elements of the list.


```
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    struct Node *next;
    struct Node *prev;
    int data;
} Node;

Node* head = NULL;

void insertAtBegining(int data) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = head;
    node->prev = NULL;
    if (head != NULL) {
        head->prev = node;
    }
    head = node;
}

void insertAtLast(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    if(head == NULL) {
        head = newNode;
    }
    else {
        Node *last = head;
        while(last->next != NULL) {
            last = last->next;
        }
        last->next = newNode;
        newNode->prev = last;
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
    newNode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = head;
    if (head->next != NULL) {
        head->next->prev = NULL;
    }
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
    Node* last = head;
    while(last->next != NULL) {
        last = last->next;
    }
    last->prev->next = NULL;
    free(last);
}

void deleteSpecificNode(int position) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = head;

    if (position == 0) {
        head = temp->next; 
        if (temp->next != NULL) {
            temp->next->prev = NULL;
        }
        free(temp);
        return;
    }

    for (int i = 0; temp != NULL && i < position; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position does not exist\n");
        return;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    free(temp);
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