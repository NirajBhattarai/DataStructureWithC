# Searching

Searching refers to the process of looking for specific information or data within a larger set of information. In the context of programming or web development, searching usually involves finding specific elements or values within a data structure or a piece of code.

Common data structures include arrays, linked lists, trees, and graphs. There are several search techniques used to find data within these structures, such as:

1. Linear Search:
Linear search is the simplest search technique, in which each element in the data structure is checked sequentially until the desired element is found or the end of the structure is reached. Linear search works on both sorted and unsorted data structures but can be inefficient for large data sets.

2. Binary Search:
Binary search is a more efficient search technique that works on sorted data structures (e.g., arrays or lists). It starts by comparing the desired value with the middle element. If the desired value is found, the search is successful. If the desired value is less than the middle element, the search continues in the lower half of the data structure. If the desired value is greater than the middle element, the search continues in the upper half. This process is repeated until the desired value is found or the search interval becomes empty.

3. Depth-First Search (DFS):
DFS is a search technique used in tree and graph data structures. It starts at a chosen node (or root node in trees) and explores as far as possible along a branch before backtracking. DFS can be implemented using recursion or a stack data structure.

4. Breadth-First Search (BFS):
BFS is another search technique used in tree and graph data structures. It visits all the nodes at the current depth (or level) before moving on to nodes at the next depth level. BFS can be implemented using a queue data structure.

5. Hash-based Search:
In hash-based search, a data structure called a hash table is used to store elements. Each element is assigned a unique key, which is used to calculate its index in the hash table using a hash function. Searching for an element in a hash table involves calculating the element's key and using the hash function to locate its index. This method can provide constant-time search complexity, making it highly efficient for large data sets.


## Sequential Search

Sequential search, also known as linear search, is a simple search algorithm that works by iterating through each element in an array or list until the target element is found or the end of the array is reached. Here is a C program that demonstrates the sequential search algorithm

```
#include <stdio.h>

int sequentialSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i; // Return the index of the target element
        }
    }
    return -1; // Return -1 if the target element is not found
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 50;

    int result = sequentialSearch(arr, n, target);

    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found in the array\n");
    }

    return 0;
}
```

## Binary Search

Binary search is an efficient search algorithm that works on sorted arrays or lists. It repeatedly divides the search interval in half, comparing the middle element with the target value until the target value is found or the search interval becomes empty. Binary search has a time complexity of O(log n), making it much faster than linear search for large data sets.

```
#include <stdio.h>

int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // Return the index of the target element
        }

        if (arr[mid] < target) {
            left = mid + 1; // Narrow the search to the right half
        } else {
            right = mid - 1; // Narrow the search to the left half
        }
    }
    return -1; // Return -1 if the target element is not found
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 50;

    int result = binarySearch(arr, 0, n - 1, target);

    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found in the array\n");
    }

    return 0;
}
```

## Tree Search

Tree search is an algorithm for traversing or searching a tree data structure. There are different types of tree search methods, such as depth-first search (DFS) and breadth-first search (BFS)

Depth-first search (DFS) is an algorithm that explores a tree or graph data structure by visiting a node, then recursively exploring its children from left to right, and continuing this process until all nodes in the tree have been visited.

```

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* newNode(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void dfs(Node* node) {
    if (node == NULL) {
        return;
    }

    printf("%d ", node->data);
    dfs(node->left);
    dfs(node->right);
}

int main() {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    printf("DFS traversal of the binary tree is:\n");
    dfs(root);

    return 0;
}
```

```
      1
     / \
    2   3
   / \ / \
  4  5 6  7

```
```

DFS traversal of the binary tree is:
1 2 4 5 3 6 7

```
## Breadth-first search (BFS)

Breadth-first search (BFS) is an algorithm for traversing or searching a tree or graph data structure. It explores all the nodes at the current depth before moving on to the nodes at the next depth level. BFS can be implemented using a queue data structure.

```

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct QueueNode {
    Node* treeNode;
    struct QueueNode* next;
} QueueNode;

Node* newNode(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

QueueNode* newQueueNode(Node* treeNode) {
    QueueNode* queueNode = (QueueNode*) malloc(sizeof(QueueNode));
    queueNode->treeNode = treeNode;
    queueNode->next = NULL;
    return queueNode;
}

void enqueue(QueueNode** front, QueueNode** rear, Node* treeNode) {
    QueueNode* new_node = newQueueNode(treeNode);
    if (*rear == NULL) {
        *front = *rear = new_node;
        return;
    }
    (*rear)->next = new_node;
    *rear = new_node;
}

Node* dequeue(QueueNode** front, QueueNode** rear) {
    if (*front == NULL) {
        return NULL;
    }
    QueueNode* temp = *front;
    Node* treeNode = temp->treeNode;
    *front = temp->next;
    if (*front == NULL) {
        *rear = NULL;
    }
    free(temp);
    return treeNode;
}

int isQueueEmpty(QueueNode* front) {
    return (front == NULL);
}

void bfs(Node* root) {
    QueueNode* front = NULL;
    QueueNode* rear = NULL;

    if (root == NULL) {
        return;
    }

    enqueue(&front, &rear, root);

    while (!isQueueEmpty(front)) {
        Node* currentNode = dequeue(&front, &rear);
        printf("%d ", currentNode->data);

        if (currentNode->left != NULL) {
            enqueue(&front, &rear, currentNode->left);
        }

        if (currentNode->right != NULL) {
            enqueue(&front, &rear, currentNode->right);
        }
    }
}

int main() {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    printf("BFS traversal of the binary tree is:\n");
    bfs(root);

    return 0;
}
```

Generate Binary Tree

```
      1
     / \
    2   3
   / \ / \
  4  5 6  7
```

Traversal

```
BFS traversal of the binary tree is:
1 2 3 4 5 6 7
```

## Hashing and Hash function

Hashing is a technique that maps data to fixed-size values called hash codes or hash values. These values are generated by a hash function, which takes input data and produces an output hash value, usually an integer or a fixed-size array of bytes. The purpose of hashing is to enable efficient data retrieval and manipulation in data structures like hash tables.

A hash function is designed to efficiently distribute the input data across a range of possible values. A good hash function should have the following properties:

Deterministic: Given the same input data, the function should always produce the same hash value.
Efficient: The hash function should be fast to compute.
Uniform distribution: The hash function should generate hash values that are evenly distributed across the output range, minimizing collisions.
Low collision rate: Different input data should ideally produce different hash values. However, hash functions are not perfect, and collisions (when two different inputs produce the same hash value) can occur. A good hash function minimizes collisions.
For searching, hash functions are used in conjunction with hash tables. A hash table is a data structure that stores key-value pairs, where keys are hashed using a hash function to determine the index at which the corresponding value will be stored. This allows for efficient searching, insertion, and deletion of key-value pairs.


```

#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void insert(int* hashTable, int key, int value) {
    int index = hashFunction(key);
    hashTable[index] = value;
}

int search(int* hashTable, int key) {
    int index = hashFunction(key);
    return hashTable[index];
}

int main() {
    int hashTable[TABLE_SIZE] = {0};

    insert(hashTable, 1, 10);
    insert(hashTable, 11, 20);
    insert(hashTable, 21, 30);

    printf("Value for key 1: %d\n", search(hashTable, 1));
    printf("Value for key 11: %d\n", search(hashTable, 11));
    printf("Value for key 21: %d\n", search(hashTable, 21));

    return 0;
}
```

Output: 

```
Value for key 1: 10
Value for key 11: 20
Value for key 21: 30
```

## Collision Resolution Techniques

When using hash tables, collisions occur when two different keys produce the same hash value, which leads to a conflict in assigning their values to the same index in the hash table. To handle such situations, several collision resolution techniques have been developed. Two common techniques are:

## 1. Chaining (Separate Chaining)
In this technique, each index in the hash table stores a linked list (or another data structure) of all the key-value pairs with the same hash value. When a collision occurs, the new key-value pair is added to the linked list at that index.

### Advantages of Chaining:

Simple to implement.
Can handle a large number of collisions.
### Disadvantages of Chaining:

Requires additional memory to store the linked lists or data structures.
Lookup time can be slower if the linked list becomes too long.
## 2. Open Addressing (Probing)
In open addressing, all key-value pairs are stored directly in the hash table itself. When a collision occurs, the hash table looks for the next available slot in a predefined sequence (linear probing, quadratic probing, or double hashing) until an empty slot is found.

## Linear Probing: Move to the next slot in the table (circularly) until an empty slot is found.
Quadratic Probing: Move to the next slot in the table by a quadratic function of the form c1^2, c2^2, c3^2, ... (circularly) until an empty slot is found.
Double Hashing: Use a secondary hash function to determine the next slot in the table until an empty slot is found.
### Advantages of Open Addressing:

Doesn't require additional memory for storing linked lists or other data structures.
Can be more cache-efficient as all data is stored in the hash table itself.
### Disadvantages of Open Addressing:

Requires a more complex algorithm to find empty slots.
Can lead to performance degradation if the hash table becomes too full (load factor is high).

## Comparison

```

| Search Technique | Time Complexity (Best) | Time Complexity (Average) | Time Complexity (Worst) | Space Complexity | Preprocessing Required | Sorted Data Required |
|------------------|------------------------|---------------------------|-------------------------|------------------|------------------------|----------------------|
| Linear Search    | O(1)                   | O(n)                      | O(n)                    | O(1)             | No                     | No                   |
| Binary Search    | O(1)                   | O(log n)                  | O(log n)                | O(1)             | No                     | Yes                  |
| Hash-based Search| O(1)                   | O(1) (with good hash function) | O(n) (worst case, poor hash function or high load factor) | O(n) | Yes | No               |
| Tree-based Search| O(1) (balanced)        | O(log n) (balanced)       | O(n) (unbalanced)       | O(n)             | Yes                    | No                   |
```
Note: The time complexities mentioned in the table above are for search operations. Insertion, deletion, and other operations might have different time complexities depending on the search technique.
