#include <stdio.h>

// Function to demonstrate pass-by-value
void pass_by_value(int num) {
    num = num * 2; // This will only modify the local copy of the variable
    // No effect on the original value outside the function
}

// Function to demonstrate pass-by-reference using pointers
void pass_by_reference(int *num_ptr) {
    *num_ptr = *num_ptr * 2; // This will modify the original value through the pointer
    // The original value outside the function is affected
}

int main() {
    int a = 5;
    int b = 5;

    printf("Before function calls: a = %d, b = %d\n", a, b);

    pass_by_value(a); // Pass by value - no effect on the original value
    pass_by_reference(&b); // Pass by reference - original value will be modified

    printf("After function calls: a = %d, b = %d\n", a, b);

    return 0;
}
