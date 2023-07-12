## Introduction

A list in computer science is a type of data structure that can hold zero or more items. These items are often related and are arranged in a linear sequence, which allows for easy access to elements based on their position. The list can be either ordered (where the items are in a specific sequence, also known as a sequence), or unordered (where the items are not in any specific sequence).

There are two main types of lists:

1. Static Lists: These lists have a fixed size that's determined at the time of creation. The size cannot be changed once the list is created. The advantage of static lists is that they are straightforward and efficient, but the downside is that they lack flexibility. An example of this type in Java is an array.

2. Dynamic Lists: These lists can grow or shrink in size dynamically as elements are added or removed. The size does not need to be determined at the time of creation, which provides greater flexibility. However, they may be slightly less efficient than static lists due to the overhead of managing dynamic memory. An example of this type in Java is the ArrayList class.

Lists are a foundational data structure in computer science and are used in many algorithms and applications. They are often used as building blocks for more complex data structures like stacks, queues, and graphs.

Programs:

Array as List

```
public class ListArray {
    private int arr[];
    private int index;
    private int size;

    // Constructor to initialize array with size
    public ListArray(int size) {
        arr = new int[size];
        index = 0;
        this.size = size;
    }

    // Function to add an element to the list
    public void add(int data) {
        if (index < size) {
            arr[index] = data;
            index++;
        } else {
            System.out.println("List is full");
        }
    }

    // Function to get an element at a specific index
    public int get(int index) {
        if (index < size) {
            return arr[index];
        } else {
            System.out.println("Index out of bounds");
            return -1;
        }
    }

    // Function to print the list
    public void printList() {
        for (int i = 0; i < index; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        ListArray list = new ListArray(5);

        list.add(1);
        list.add(2);
        list.add(3);
        list.add(4);
        list.add(5);

        list.printList();  // Prints: 1 2 3 4 5

        System.out.println("Element at index 2: " + list.get(2));  // Prints: Element at index 2: 3

        list.add(6);  // Prints: List is full
    }
}
```

```
#include <stdio.h>
#define SIZE 5

// List
int list[SIZE];
int index = 0;

// Add element to list
void add(int element) {
    if (index < SIZE) {
        list[index] = element;
        index++;
    } else {
        printf("List is full\n");
    }
}

// Get element from list
int get(int i) {
    if (i < SIZE) {
        return list[i];
    } else {
        printf("Index out of bounds\n");
        return -1;
    }
}

// Print list
void printList() {
    for(int i = 0; i < index; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}

int main() {
    add(1);
    add(2);
    add(3);
    add(4);
    add(5);

    printList();  // Prints: 1 2 3 4 5

    printf("Element at index 2: %d\n", get(2));  // Prints: Element at index 2: 3

    add(6);  // Prints: List is full

    return 0;
}
```


Queue as List

```

import java.util.ArrayList;

public class Queue {
    private ArrayList<Integer> list;

    public Queue() {
        this.list = new ArrayList<>();
    }

    // Add an element to the queue (enqueue)
    public void enqueue(int element) {
        list.add(element);
    }

    // Remove an element from the queue (dequeue)
    public int dequeue() {
        if(list.isEmpty()) {
            System.out.println("Queue is empty");
            return -1; // or optionally, throw an exception
        }
        return list.remove(0);
    }

    // Check if the queue is empty
    public boolean isEmpty() {
        return list.isEmpty();
    }

    public static void main(String[] args) {
        Queue queue = new Queue();

        queue.enqueue(1);
        queue.enqueue(2);
        queue.enqueue(3);

        System.out.println(queue.dequeue()); // prints: 1
        System.out.println(queue.dequeue()); // prints: 2
        System.out.println(queue.dequeue()); // prints: 3
        System.out.println(queue.dequeue()); // prints: Queue is empty, then: -1
    }
}
```

```
#include <stdio.h>
#include <stdlib.h>

// Queue structure
typedef struct {
    int front, rear, size;
    unsigned capacity;
    int* array;
} Queue;

// Function to create a queue
Queue* createQueue(unsigned capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0; 
    queue->rear = capacity - 1; 
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

// Function to check if the queue is full
int isFull(Queue* queue) {
    return (queue->size == queue->capacity);
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    return (queue->size == 0);
}

// Function to add an element to the queue
void enqueue(Queue* queue, int item) {
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1)%queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
    printf("%d enqueued to queue\n", item);
}

// Function to remove an element from the queue
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1)%queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

int main() {
    Queue* queue = createQueue(1000);

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);

    printf("%d dequeued from queue\n", dequeue(queue));
    printf("%d dequeued from queue\n", dequeue(queue));
    printf("%d dequeued from queue\n", dequeue(queue));

    return 0;
}
```