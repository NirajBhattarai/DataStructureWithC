## Queue Data Structure and Operations 

### Introduction

This documentation is about the Queue data structure and its fundamental operations. A Queue is a type of data structure which follows the FIFO (First In First Out) concept, where the first element that is added to the queue will be the first one to be removed.

Common uses of queues include managing tasks in various computing environments, handling requests on a single shared resource like a printer, CPU task scheduling, and more.

## Basic Operations
The core operations associated with a queue include:

1. Enqueue - Adds an element to the end of the queue
2. Dequeue - Removes an element from the front of the queue
3. IsFull - Checks if the queue is full
4. IsEmpty - Checks if the queue is empty
5. Peek/Top - Gets the value of the front of the queue without removing it

## Implementation

```
#include <stdio.h>

#define SIZE 100

int queue[SIZE];
int front = 0;
int rear = -1;

// Function to add an element to the queue
void enqueue(int item) {
    if (rear == SIZE - 1) {
        printf("Queue is full\n");
    } else {
        queue[++rear] = item;
    }
}

// Function to remove an element from the queue
int dequeue() {
    if (front > rear) {
        printf("Queue is empty\n");
        return -1;
    } else {
        int item = queue[front++];
        return item;
    }
}

// Function to check if the queue is empty
int isEmpty() {
    return front > rear;
}

// Function to get the front of the queue
int peek() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return -1;
    } else {
        return queue[front];
    }
}

int main() {
    // Testing the queue
    enqueue(1);
    enqueue(2);
    enqueue(3);

    printf("Front of the queue: %d\n", peek());

    while (!isEmpty()) {
        printf("Dequeued: %d\n", dequeue());
    }

    return 0;
}
```