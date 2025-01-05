# Infix to Postfix Conversion

This document explains the algorithm to convert an infix expression to a postfix expression, also known as Reverse Polish Notation (RPN).

## Algorithm Steps

1. **Initialize Structures**:
   - Use a stack to hold operators and parentheses.
   - Use a list (or queue) to build the output postfix expression.

2. **Read the Infix Expression**:
   - Process the expression from left to right, one token at a time.

3. **Token Processing**:
   - **Operand**: Directly add operands (e.g., variables, numbers) to the output list.
   - **Left Parenthesis `(`**: Push onto the stack to denote a subexpression.
   - **Right Parenthesis `)`**: Pop from the stack to the output list until a left parenthesis is encountered. Discard the left parenthesis.
   - **Operator**: 
     - Determine the precedence of the current operator.
     - While there is an operator at the top of the stack with greater precedence, or the operator at the top of the stack has the same precedence and is left associative, pop operators from the stack to the output list.
     - Push the current operator onto the stack.

4. **End of Expression**:
   - After reading the entire expression, pop all remaining operators from the stack to the output list.

## Operator Precedence and Associativity

- **Precedence Levels** (from highest to lowest):
  1. Parentheses `()`
  2. Exponentiation `^`
  3. Multiplication `*` and Division `/`
  4. Addition `+` and Subtraction `-`

- **Associativity**:
  - **Left Associative**: `+`, `-`, `*`, `/` (evaluated from left to right)
  - **Right Associative**: `^` (evaluated from right to left)

---

This guide provides a comprehensive overview of the process for converting infix expressions to postfix, ensuring the correct order of operations is maintained.

## Show the status of stack converting following infix expression to post fix P + Q – (R*S/T+U)-V*W

| Step | Stack | Input                               | Output                      |
|------|-------|-------------------------------------|------------------------------|
| 1    |       | P + Q - (R * S / T + U) - V * W     |                              |
| 2    | +     | Q - (R * S / T + U) - V * W         | P                            |
| 3    | +     | - (R * S / T + U) - V * W           | P Q                          |
| 4    | -     | (R * S / T + U) - V * W             | P Q +                        |
| 5    | -     | R * S / T + U) - V * W              | P Q + (                      |
| 6    | - *   | S / T + U) - V * W                  | P Q + R                      |
| 7    | - *   | / T + U) - V * W                    | P Q + R S                    |
| 8    | - /   | T + U) - V * W                      | P Q + R S *                  |
| 9    | - /   | + U) - V * W                        | P Q + R S * T                |
| 10   | - +   | U) - V * W                          | P Q + R S * T /              |
| 11   | - +   | ) - V * W                           | P Q + R S * T / U            |
| 12   | -     | - V * W                             | P Q + R S * T / U +          |
| 13   | -     | V * W                               | P Q + R S * T / U + -        |
| 14   | - *   | W                                   | P Q + R S * T / U + - V      |
| 15   | - *   |                                     | P Q + R S * T / U + - V W    |
| 16   | -     |                                     | P Q + R S * T / U + - V W *  |
| 17   |       |                                     | P Q + R S * T / U + - V W * -|

## Trace the algorithm to convert infix to postfix with following infix expression ((A + B) - C * D/E)*(H-I)*F+G and evaluate the obtained postfix expression with following values: A = 4, B = 2, C = 4, D = 3, E = 8, F = 2, G = 3, H =5, I = 1

| Step | Stack   | Input                                       | Output                   |
|------|---------|---------------------------------------------|--------------------------|
| 1    |         | ((A + B) - C * D / E) * (H - I) * F + G      |                          |
| 2    | (       | (A + B) - C * D / E) * (H - I) * F + G       |                          |
| 3    | ((      | A + B) - C * D / E) * (H - I) * F + G         |                          |
| 4    | ((+     | B) - C * D / E) * (H - I) * F + G             | A                        |
| 5    | ((+     | ) - C * D / E) * (H - I) * F + G              | AB+                      |
| 6    | (-      | C * D / E) * (H - I) * F + G                  |                          |
| 7    | (-*     | D / E) * (H - I) * F + G                      | C                        |
| 8    | (-*     | / E) * (H - I) * F + G                        | CD*                      |
| 9    | (-/     | E) * (H - I) * F + G                          | CD*                      |
| 10   | (-/     | ) * (H - I) * F + G                           | E                        |
| 11   | (*      | (H - I) * F + G                               | ABCD*E/-                 |
| 12   | ((*     | H - I) * F + G                                |                          |
| 13   | ((-     | I) * F + G                                    | H                        |
| 14   | ((-     | ) * F + G                                     | HI-                      |
| 15   | (*      | * F + G                                       |                          |
| 16   | (*      | F + G                                         | HI-*                     |
| 17   | (*      | + G                                           | F                        |
| 18   | +       | G                                             | ABCD*E/-HI-*F*           |
| 19   |         |                                               | ABCD*E/-HI-*F*+G         |





| Step | Operation    | Stack       | Result  |
|------|--------------|-------------|---------|
| 1    | Push 4       | 4           |         |
| 2    | Push 2       | 4, 2        |         |
| 3    | Add          | 6           |         |
| 4    | Push 4       | 6, 4        |         |
| 5    | Push 3       | 6, 4, 3     |         |
| 6    | Multiply     | 6, 12       |         |
| 7    | Push 8       | 6, 12, 8    |         |
| 8    | Divide       | 6, 1.5      |         |
| 9    | Subtract     | 4.5         |         |
| 10   | Push 5       | 4.5, 5      |         |
| 11   | Push 1       | 4.5, 5, 1   |         |
| 12   | Subtract     | 4.5, 4      |         |
| 13   | Multiply     | 18          |         |
| 14   | Push 2       | 18, 2       |         |
| 15   | Multiply     | 36          |         |
| 16   | Push 3       | 36, 3       |         |
| 17   | Add          | 39          |         |
| 18   | Done         |             | 39      |
