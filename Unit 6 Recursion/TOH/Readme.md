## Tower of Hanoi in C
The Tower of Hanoi (also called the Tower of Brahma or Lucas' Tower) is a mathematical game or puzzle. It consists of three rods and a number of disks of different sizes, which can slide onto any rod. The puzzle starts with the disks in a neat stack in ascending order of size on one rod, the smallest at the top, thus making a conical shape.

## Rules:
Only one disk can be moved at a time.
Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack or on an empty rod.
No larger disk may be placed on top of a smaller disk.

Program 

```
#include <stdio.h>

void TowerOfHanoi(int n, int A, int B, int C) {
 
 if(n>0)
 {
    TowerOfHanoi(n-1,A,C,B);
    printf("(%d,%d)\n",A,C);
    TowerOfHanoi(n-1,B,A,C);
 }

}

int main() {
    int n = 3; // Number of disks
    TowerOfHanoi(n, 1, 2, 3);
    return 0;
}
```
