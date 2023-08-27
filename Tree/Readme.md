```
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value);
Node* insert(Node* root, int value);
Node* find(Node* root, int value);
Node* deleteNode(Node* root, int value);
Node* findMinimum(Node* root);

int insertedValues[100];  // Assuming max of 100 insertions for simplicity
int counter = 0;

int main() {
    Node* root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    printf("Values in the order of insertion:\n");
    for (int i = 0; i < counter; i++) {
        printf("%d ", insertedValues[i]);
    }
    printf("\n");

    int searchValue = 60;
    Node* result = find(root, searchValue);
    if (result != NULL) {
        printf("Node %d found in the BST.\n", searchValue);
    } else {
        printf("Node %d not found in the BST.\n", searchValue);
    }

    int deleteValue = 30;
    root = deleteNode(root, deleteValue);
    printf("After deleting node %d:\nValues in the order of insertion:\n", deleteValue);
    for (int i = 0; i < counter; i++) {
        printf("%d ", insertedValues[i]);
    }
    printf("\n");

    return 0;
}

Node* createNode(int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int value) {
    insertedValues[counter++] = value;

    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

Node* find(Node* root, int value) {
    if (root == NULL) {
        return NULL;
    }
    
    if (value == root->data) {
        return root;
    } else if (value < root->data) {
        return find(root->left, value);
    } else {
        return find(root->right, value);
    }
}

Node* deleteNode(Node* root, int value) {
    if (root == NULL) return root;

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = findMinimum(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

Node* findMinimum(Node* root) {
    Node* current = root;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

```