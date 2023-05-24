## Stack 

A stack is a fundamental data structure used in computer science and programming. It operates based on the principle of Last-In-First-Out (LIFO). This means that the most recently added (or "pushed") element is the first one to be removed (or "popped").

The two primary operations associated with a stack are:

1. Push: This operation adds an element to the collection. In a stack, the element is always added to the top.

2. Pop: This operation removes an element from the collection. In a stack, the topmost element is always the one removed.

Here are a few additional operations that are sometimes associated with a stack:

1. Peek / Top: This operation gets the top data element of the stack, without removing it.
2. IsEmpty: This operation checks whether the stack is empty.
3. IsFull: This operation checks whether the stack is full.
4. Stacks are useful in many situations where you want to reverse a sequence of items or where you want to store items in a specific order. They are used in many areas of programming, such as managing function calls (call stack), parsing (syntax stack), expressi

```

#include <stdio.h>

#define MAX 1000 // maximum size of the stack

int stack[MAX];
int top = -1; // initialize top of stack to -1

void push(int x) {
    if (top >= MAX-1) {
        printf("Stack overflow\n");
    } else {
        stack[++top] = x;
        printf("%d pushed into stack\n", x);
    }
}

int pop() {
    if (top < 0) {
        printf("Stack underflow\n");
        return 0;
    } else {
        int x = stack[top--];
        return x;
    }
}

int peek() {
    if (top < 0) {
        printf("Stack is empty\n");
        return 0;
    } else {
        int x = stack[top];
        return x;
    }
}

int isEmpty() {
    if(top < 0) {
        return 1; // returns 1 if the stack is empty
    } else {
        return 0; // returns 0 if the stack is not empty
    }
}

int isFull() {
    if(top >= MAX-1) {
        return 1; // returns 1 if the stack is full
    } else {
        return 0; // returns 0 if the stack is not full
    }
}

int main() {
    push(10);
    push(20);
    push(30);
    printf("%d popped from stack\n", pop());
    printf("Top item is %d\n", peek());
    printf("Is the stack empty? %d\n", isEmpty()); // prints 0
    printf("Is the stack full? %d\n", isFull()); // prints 0

    // Assuming MAX is 3 for simplicity, push 2 more elements
    push(40);
    printf("Is the stack full? %d\n", isFull()); // prints 1 after all slots are filled

    return 0;
}


```


```

public class Stack {
    private int maxSize;
    private int top;
    private int[] stackArray;

    public Stack(int size) {
        maxSize = size;
        stackArray = new int[maxSize];
        top = -1;
    }

    public void push(int value) {
        if (!isFull()) {
            top++;
            stackArray[top] = value;
            System.out.println(value + " pushed into stack");
        } else {
            System.out.println("Stack is full");
        }
    }

    public int pop() {
        if (!isEmpty()) {
            int topVal = stackArray[top];
            top--;
            System.out.println(topVal + " popped from stack");
            return topVal;
        } else {
            System.out.println("Stack is empty");
            return -1;
        }
    }

    public int peek() {
        if (!isEmpty()) {
            return stackArray[top];
        } else {
            System.out.println("Stack is empty");
            return -1;
        }
    }

    public boolean isEmpty() {
        return (top == -1);
    }

    public boolean isFull() {
        return (top == maxSize - 1);
    }

    public static void main(String[] args) {
        Stack stack = new Stack(3);
        stack.push(10);
        stack.push(20);
        stack.push(30);
        stack.pop();
        System.out.println("Top item is " + stack.peek());
        System.out.println("Is the stack empty? " + stack.isEmpty());
        stack.push(40);
        System.out.println("Is the stack full? " + stack.isFull());
    }
}

```






