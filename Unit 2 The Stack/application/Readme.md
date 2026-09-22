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

| Step | Token              | Stack | Output                          |
|------|--------------------|-------|----------------------------------|
| 1    | —                  |       |                                   |
| 2    | P                  |       | P                                 |
| 3    | +                  | +     | P                                 |
| 4    | Q                  | +     | P Q                               |
| 5    | -                  | -     | P Q +                             |
| 6    | (                  | - (   | P Q +                             |
| 7    | R                  | - (   | P Q + R                           |
| 8    | *                  | - ( * | P Q + R                           |
| 9    | S                  | - ( * | P Q + R S                         |
| 10   | /                  | - ( / | P Q + R S *                       |
| 11   | T                  | - ( / | P Q + R S * T                     |
| 12   | +                  | - ( + | P Q + R S * T /                   |
| 13   | U                  | - ( + | P Q + R S * T / U                 |
| 14   | )                  | -     | P Q + R S * T / U +               |
| 15   | -                  | -     | P Q + R S * T / U + -             |
| 16   | V                  | -     | P Q + R S * T / U + - V           |
| 17   | *                  | - *   | P Q + R S * T / U + - V           |
| 18   | W                  | - *   | P Q + R S * T / U + - V W         |
| 19   | end (flush stack)  |       | P Q + R S * T / U + - V W * -     |

Final postfix: `P Q + R S * T / U + - V W * -`

> Note: `(` and `)` are never written to the output — `(` is only pushed onto the stack, and `)` only triggers popping until the matching `(`, which is then discarded.

## Trace the algorithm to convert infix to postfix with following infix expression ((A + B) - C * D/E)*(H-I)*F+G and evaluate the obtained postfix expression with following values: A = 4, B = 2, C = 4, D = 3, E = 8, F = 2, G = 3, H =5, I = 1

| Step | Token              | Stack | Output                              |
|------|--------------------|-------|---------------------------------------|
| 1    | —                  |       |                                        |
| 2    | (                  | (     |                                        |
| 3    | (                  | ( (   |                                        |
| 4    | A                  | ( (   | A                                      |
| 5    | +                  | ( ( + | A                                      |
| 6    | B                  | ( ( + | A B                                    |
| 7    | )                  | (     | A B +                                  |
| 8    | -                  | ( -   | A B +                                  |
| 9    | C                  | ( -   | A B + C                                |
| 10   | *                  | ( - * | A B + C                                |
| 11   | D                  | ( - * | A B + C D                              |
| 12   | /                  | ( - / | A B + C D *                            |
| 13   | E                  | ( - / | A B + C D * E                          |
| 14   | )                  |       | A B + C D * E / -                      |
| 15   | *                  | *     | A B + C D * E / -                      |
| 16   | (                  | * (   | A B + C D * E / -                      |
| 17   | H                  | * (   | A B + C D * E / - H                    |
| 18   | -                  | * ( - | A B + C D * E / - H                    |
| 19   | I                  | * ( - | A B + C D * E / - H I                  |
| 20   | )                  | *     | A B + C D * E / - H I -                |
| 21   | *                  | *     | A B + C D * E / - H I - *              |
| 22   | F                  | *     | A B + C D * E / - H I - * F            |
| 23   | +                  | +     | A B + C D * E / - H I - * F *          |
| 24   | G                  | +     | A B + C D * E / - H I - * F * G        |
| 25   | end (flush stack)  |       | A B + C D * E / - H I - * F * G +      |

Final postfix: `A B + C D * E / - H I - * F * G +`

> Note: the earlier version of this table dropped the `+` (from `A + B`) after row 6, giving the wrong final result `ABCD*E/-HI-*F*+G` (only 7 operators for 9 operands — one short). The evaluation table below was already using the correct 8-operator expression, which is why it evaluates to 39.





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
