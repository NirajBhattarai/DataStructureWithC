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

## Circular Queue

A circular queue is a type of linear data structure that follows the First In First Out (FIFO) principle. What makes the circular queue different is its ability to connect the front and the rear ends, making the queue resemble a circle. This makes the queue a continuous or cyclic entity, which allows efficient utilization of memory.

```
#include <stdio.h>

#define SIZE 5 // Size of Circular Queue

int items[SIZE];
int front = -1, rear =-1;

// Check if the queue is full
int isFull() {
    if((front == rear + 1) || (front == 0 && rear == SIZE-1)) return 1;
    return 0;
}

// Check if the queue is empty
int isEmpty() {
    if(front == -1) return 1;
    return 0;
}

// Add elements into queue
void enQueue(int element) {
    if(isFull()) printf("\n Queue is full!! \n");
    else {
        if(front == -1) front = 0;
        rear = (rear + 1) % SIZE;
        items[rear] = element;
        printf("\n Inserted -> %d", element);
    }
}

// Remove element from queue
int deQueue() {
    int element;
    if(isEmpty()) {
        printf("\n Queue is empty !! \n");
        return(-1);
    } else {
        element = items[front];
        if (front == rear){
            front = -1;
            rear = -1;
        } /* Q has only one element, so we reset the queue after deleting it. */
        else {
            front = (front + 1) % SIZE;
            
        }
        printf("\n Deleted element -> %d \n", element);
        return(element);
    }
}

// Display the queue
void display() {
    int i;
    if(isEmpty()) printf(" \n Empty Queue\n");
    else {
        printf("\n Front -> %d ",front);
        printf("\n Items -> ");
        for( i = front; i!=rear; i=(i+1)%SIZE) {
            printf("%d ",items[i]);
        }
        printf("%d ",items[i]);
        printf("\n Rear -> %d \n",rear);
    }
}

int main() {
    // Fails because front = -1
    deQueue();

    enQueue(1);
    enQueue(2);
    enQueue(3);
    enQueue(4);
    enQueue(5);

    // Fails to enqueue because front == 0 && rear == SIZE - 1
    enQueue(6);

    display();
    deQueue();

    display();

    enQueue(7);

    display();

    // Fails to enqueue because front == rear + 1
    enQueue(8);

    return 0;
}
```

In Java Language Also 

```

public class CircularQueue {
	static int size = 5;
	static int front = -1;
	static int rear = -1;
	static int[] queues = new int[size];

	static boolean isFull() {
		if (front == 0 && rear == size - 1) {
			return true;
		}
		if (front == rear + 1)
			return true;
		return false;
	}

	static boolean isEmpty() {
		if (front == -1)
			return true;
		return false;
	}

	static void enqueue(int data) {
		if (isFull()) {
			System.out.print("queue full");
			return;
		} else {
			if (front == -1)
				front = 0;
			rear = (rear + 1) % size;
			queues[rear] = data;
			System.out.println("Inserted " + data);

		}

	}

	static int deQueue() {
		int element;
		if (isEmpty()) {
			System.out.println("Queue is Empty");
			return -1;
		} else {
			element = queues[front];
			if (front == rear) {
				front = -1;
				rear = -1;
			} else {
				front = (front + 1) % size;
			}
		}
		return element;

	}

	public static void main(String[] args) {
		enqueue(1);
		enqueue(2);
		enqueue(3);
		System.out.println(deQueue());
		enqueue(4);
		enqueue(5);
		enqueue(1);
	}

}
```

## Priority Queue

This PriorityQueue class is a simple data structure that holds elements each with a certain priority. The priority of the elements in a PriorityQueue determines the order in which elements are served (i.e., deleted). The element with the highest priority is served before the element with the lowest priority. If elements with equal priorities occur, they are served according to their order in the queue.

```

#include <stdio.h>

#define MAX_SIZE 100

int heap[MAX_SIZE];
int heapSize = 0;

// Function to swap elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to insert element into the heap
void insert(int val) {
    if (heapSize >= MAX_SIZE) {
        printf("\nOverflow: Could not insertKey\n");
        return;
    }

    // First insert the new key at the end
    heapSize++;
    int i = heapSize - 1;
    heap[i] = val;

    // Fix the max heap property if it is violated
    while (i != 0 && heap[(i - 1) / 2] < heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to display the heap
void displayHeap() {
    for(int i = 0; i < heapSize; ++i)
        printf("%d ", heap[i]);
    printf("\n");
}

// Main function
int main() {
    insert(3);
    insert(2);
    insert(15);
    insert(5);
    insert(4);
    insert(45);

    printf("Heap array is ");
    displayHeap();

    return 0;
}
```