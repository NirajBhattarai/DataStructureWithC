# Infix to Postfix Conversion: A Step-by-Step Guide

Converting infix expressions to postfix notation is a fundamental concept in computer science, particularly in the context of expression evaluation and compiler design. This guide will walk you through the conversion process using two example expressions.

## Example 1: Simple Infix Expression

### Infix Expression:

\[ (A + B) \times (C - D) \]

### Conversion Rules:

1. **Operands (e.g., A, B, etc.):** Directly append to the postfix expression.
2. **Parentheses:** Push `(` onto the stack, and pop operators to the postfix expression when encountering `)`.
3. **Operators:** Push onto the stack, ensuring precedence rules are maintained.
4. **End of Expression:** Pop remaining operators from the stack to the postfix expression.

### Step-by-Step Conversion:

| Step | Stack   | Remaining Expression | Postfix   |
|------|---------|----------------------|-----------|
| 1    | (       | (A + B) × (C - D)    |           |
| 2    | (, +    | A + B) × (C - D)     | A         |
| 3    | (       | + B) × (C - D)       | A B       |
| 4    | *       | ) × (C - D)          | A B +     |
| 5    | *, (    | (C - D)              | A B +     |
| 6    | *, (, - | C - D)               | A B + C   |
| 7    | *, (    | - D)                 | A B + C D |
| 8    | *       | )                    | A B + C D - |
| 9    |         |                      | A B + C D - * |

### Final Postfix Expression:

\[ AB + CD - * \]

## Example 2: Complex Infix Expression

### Infix Expression:

\[ A+(((B-C)*(D-E)+F)/G)\$(H-I) \]

### Conversion Rules:

1. **Operands (e.g., A, B, etc.):** Directly append to the postfix expression.
2. **Parentheses:** Push `(` onto the stack, and pop operators to the postfix expression when encountering `)`.
3. **Operators:** Push onto the stack, ensuring precedence rules are maintained.
4. **End of Expression:** Pop remaining operators from the stack to the postfix expression.

### Step-by-Step Conversion:

| Step | Stack          | Remaining Expression        | Postfix       |
|------|----------------|-----------------------------|---------------|
| 1    | +              | A+(((B-C)*(D-E)+F)/G)\$(H-I) | A             |
| 2    | +, (           | (((B-C)*(D-E)+F)/G)\$(H-I)   | A             |
| 3    | +, (, (        | ((B-C)*(D-E)+F)/G)\$(H-I)    | A             |
| 4    | +, (, (, (     | (B-C)*(D-E)+F)/G)\$(H-I)     | A             |
| 5    | +, (, (, (, -  | B-C)*(D-E)+F)/G)\$(H-I)      | A B           |
| 6    | +, (, (, (     | C)*(D-E)+F)/G)\$(H-I)        | A B C -       |
| 7    | +, (, (        | *(D-E)+F)/G)\$(H-I)          | A B C -       |
| 8    | +, (, (, *     | (D-E)+F)/G)\$(H-I)           | A B C -       |
| 9    | +, (, (, *, (  | D-E)+F)/G)\$(H-I)            | A B C -       |
| 10   | +, (, (, *, (, - | E)+F)/G)\$(H-I)           | A B C - D     |
| 11   | +, (, (, *, (  | )+F)/G)\$(H-I)               | A B C - D E - |
| 12   | +, (, (        | +F)/G)\$(H-I)                | A B C - D E - * |
| 13   | +, (, (, +     | F)/G)\$(H-I)                 | A B C - D E - * |
| 14   | +, (, (        | )/G)\$(H-I)                  | A B C - D E - * F + |
| 15   | +, (           | /G)\$(H-I)                   | A B C - D E - * F + |
| 16   | +, /           | G)\$(H-I)                    | A B C - D E - * F + G |
| 17   | +              | )\$(H-I)                     | A B C - D E - * F + G / |
| 18   |                | \$(H-I)                      | A B C - D E - * F + G / + |
| 19   | $              | (H-I)                        | A B C - D E - * F + G / + |
| 20   | $, (           | H-I)                         | A B C - D E - * F + G / + H |
| 21   | $, (, -        | I)                           | A B C - D E - * F + G / + H I |
| 22   | $, (           | )                            | A B C - D E - * F + G / + H I - |
| 23   | $              |                              | A B C - D E - * F + G / + H I - |
| 24   |                |                              | A B C - D E - * F + G / + H I - $ |

### Final Postfix Expression:

\[ ABC-DE-*F+G/+HI-$ \]

## Example 3: Infix Expression with Multiple Operators

### Infix Expression:

\[ A + B - (C \times D / E + F) - G \times H \]

### Conversion Rules:

1. **Operands (e.g., A, B, etc.):** Directly append to the postfix expression.
2. **Parentheses:** Push `(` onto the stack, and pop operators to the postfix expression when encountering `)`.
3. **Operators:** Push onto the stack, ensuring precedence rules are maintained.
4. **End of Expression:** Pop remaining operators from the stack to the postfix expression.

### Step-by-Step Conversion:

| Step | Stack       | Remaining Expression       | Postfix       |
|------|-------------|----------------------------|---------------|
| 1    | +           | A + B - (C * D / E + F) - G * H | A             |
| 2    | +, -        | B - (C * D / E + F) - G * H   | A B +         |
| 3    | +, -        | - (C * D / E + F) - G * H   | A B +         |
| 4    | +, -, (     | (C * D / E + F) - G * H     | A B +         |
| 5    | +, -, (, *  | C * D / E + F) - G * H      | A B + C       |
| 6    | +, -, (, /  | D / E + F) - G * H          | A B + C D *   |
| 7    | +, -, (     | / E + F) - G * H            | A B + C D * E |
| 8    | +, -, (, +  | E + F) - G * H              | A B + C D * E / |
| 9    | +, -, (     | + F) - G * H                | A B + C D * E / F + |
| 10   | +, -        | ) - G * H                   | A B + C D * E / F + |
| 11   | +, -        | - G * H                     | A B + C D * E / F + - |
| 12   | +, -, *     | G * H                       | A B + C D * E / F + - G |
| 13   | +, -        | * H                         | A B + C D * E / F + - G H * |
| 14   |             |                             | A B + C D * E / F + - G H * - |

### Final Postfix Expression:

\[ AB+CD*E/F+GH*- \]

## Example 1: Addition and Subtraction

### Infix Expression:

\[ A + B - C + D \]

### Step-by-Step Conversion:

| Step | Stack | Remaining Expression | Postfix |
|------|-------|----------------------|---------|
| 1    | +     | A + B - C + D        | A       |
| 2    | +, -  | B - C + D            | A B +   |
| 3    | -     | C + D                | A B + C |
| 4    | -, +  | D                    | A B + C - |
| 5    |       |                      | A B + C - D + |

### Final Postfix Expression:

\[ AB+C-D+ \]

---

## Example 2: Multiplication and Division

### Infix Expression:

\[ A \times B / C \times D \]

### Step-by-Step Conversion:

| Step | Stack | Remaining Expression | Postfix |
|------|-------|----------------------|---------|
| 1    | *     | A × B / C × D        | A       |
| 2    | *, /  | B / C × D            | A B *   |
| 3    | /, *  | C × D                | A B * C / |
| 4    | *     | D                    | A B * C / D |
| 5    |       |                      | A B * C / D * |

### Final Postfix Expression:

\[ AB*C/D* \]

---

## Example 3: Mixed Operators with Same Precedence

### Infix Expression:

\[ A + B - C \times D / E \]

### Step-by-Step Conversion:

| Step | Stack | Remaining Expression | Postfix |
|------|-------|----------------------|---------|
| 1    | +     | A + B - C × D / E    | A       |
| 2    | +, -  | B - C × D / E        | A B +   |
| 3    | -     | C × D / E            | A B + C |
| 4    | -, *  | D / E                | A B + C |
| 5    | -, /  | E                    | A B + C D * |
| 6    | -     |                      | A B + C D * E / |
| 7    |       |                      | A B + C D * E / - |

### Final Postfix Expression:

\[ AB+CD*E/- \]

---

# Additional Practice: Infix to Postfix Conversion

## Example 4: Easy Infix Expression

### Infix Expression:

\[ A + B \]

### Step-by-Step Conversion:

| Step | Stack | Remaining Expression | Postfix |
|------|-------|----------------------|---------|
| 1    | +     | A + B                | A       |
| 2    |       | B                    | A B     |
| 3    |       |                      | A B +   |

### Final Postfix Expression:

\[ AB+ \]

---

## Example 5: Infix Expression with Parentheses

### Infix Expression:

\[ (A + B) \times C \]

### Step-by-Step Conversion:

| Step | Stack | Remaining Expression | Postfix |
|------|-------|----------------------|---------|
| 1    | (     | (A + B) × C          |         |
| 2    | (, +  | A + B) × C           | A       |
| 3    | (     | + B) × C             | A B     |
| 4    | *     | ) × C                | A B +   |
| 5    |       | C                    | A B + C |
| 6    |       |                      | A B + C * |

### Final Postfix Expression:

\[ AB+C* \]

---

## Example 6: Infix Expression with Multiple Operators

### Infix Expression:

\[ A + B \times C \]

### Step-by-Step Conversion:

| Step | Stack | Remaining Expression | Postfix |
|------|-------|----------------------|---------|
| 1    | +     | A + B × C            | A       |
| 2    | +, *  | B × C                | A B     |
| 3    | +     | C                    | A B C   |
| 4    |       |                      | A B C * + |

### Final Postfix Expression:

\[ ABC*+ \]

---

## Example 7: Infix Expression with Division

### Infix Expression:

\[ A / B + C \]

### Step-by-Step Conversion:

| Step | Stack | Remaining Expression | Postfix |
|------|-------|----------------------|---------|
| 1    | /     | A / B + C            | A       |
| 2    | +     | B + C                | A B /   |
| 3    |       | C                    | A B / C |
| 4    |       |                      | A B / C + |

### Final Postfix Expression:

\[ AB/C+ \]

---

## Example 8: Infix Expression with Exponentiation

### Infix Expression:

\[ A ^ B + C \]

### Step-by-Step Conversion:

| Step | Stack | Remaining Expression | Postfix |
|------|-------|----------------------|---------|
| 1    | ^     | A ^ B + C            | A       |
| 2    | +     | B + C                | A B ^   |
| 3    |       | C                    | A B ^ C |
| 4    |       |                      | A B ^ C + |

### Final Postfix Expression:

\[ AB^C+ \]

---

## Example 9: Infix Expression with Nested Parentheses

### Infix Expression:

\[ (A + (B \times C)) \]

### Step-by-Step Conversion:

| Step | Stack | Remaining Expression | Postfix |
|------|-------|----------------------|---------|
| 1    | (     | (A + (B × C))        |         |
| 2    | (, +  | A + (B × C))         | A       |
| 3    | (, +, ( | (B × C))          | A       |
| 4    | (, +, (, * | B × C)         | A B     |
| 5    | (, +, ( | C)                | A B C   |
| 6    | (, +  | )                   | A B C * |
| 7    |       |                     | A B C * + |

### Final Postfix Expression:

\[ ABC*+ \]

---

## Example 10: Infix Expression with All Operators

### Infix Expression:

\[ A + B \times C - D / E \]

### Step-by-Step Conversion:

| Step | Stack | Remaining Expression | Postfix |
|------|-------|----------------------|---------|
| 1    | +     | A + B × C - D / E    | A       |
| 2    | +, *  | B × C - D / E        | A B     |
| 3    | +     | C - D / E            | A B C * |
| 4    | -, /  | D / E                | A B C * + D |
| 5    | -     | E                    | A B C * + D E / |
| 6    |       |                      | A B C * + D E / - |

### Final Postfix Expression:

\[ ABC*+DE/- \]

---

## Example 11: Infix Expression with Complex Nesting

### Infix Expression:

\[ ((A + B) \times (C - D)) / E \]

### Step-by-Step Conversion:

| Step | Stack | Remaining Expression | Postfix |
|------|-------|----------------------|---------|
| 1    | (     | ((A + B) × (C - D)) / E |         |
| 2    | (, (  | (A + B) × (C - D)) / E |         |
| 3    | (, (, + | A + B) × (C - D)) / E | A       |
| 4    | (, (  | B) × (C - D)) / E     | A B     |
| 5    | (, *  | ) × (C - D)) / E      | A B +   |
| 6    | (, *, ( | (C - D)) / E        | A B +   |
| 7    | (, *, (, - | C - D)) / E      | A B + C |
| 8    | (, *  | D)) / E               | A B + C D |
| 9    | /     | ) / E                 | A B + C D - * |
| 10   |       | E                     | A B + C D - * E |
| 11   |       |                       | A B + C D - * E / |

### Final Postfix Expression:

\[ AB+CD-*E/ \]

---

## Example 12: Infix Expression with Multiple Exponentiations

### Infix Expression:

\[ A ^ B ^ C \]

### Step-by-Step Conversion:

| Step | Stack | Remaining Expression | Postfix |
|------|-------|----------------------|---------|
| 1    | ^     | A ^ B ^ C            | A       |
| 2    | ^     | B ^ C                | A B     |
| 3    |       | C                    | A B C ^ |
| 4    |       |                      | A B C ^ ^ |

### Final Postfix Expression:

\[ ABC^^ \]

---

## Example 13: Infix Expression with Complex Operators

### Infix Expression:

\[ A + B \times (C - D) / E \]

### Step-by-Step Conversion:

| Step | Stack | Remaining Expression | Postfix |
|------|-------|----------------------|---------|
| 1    | +     | A + B × (C - D) / E  | A       |
| 2    | +, *  | B × (C - D) / E      | A B     |
| 3    | +, *, ( | (C - D) / E        | A B     |
| 4    | +, *, (, - | C - D) / E      | A B C   |
| 5    | +, *, ( | D) / E             | A B C D - |
| 6    | +, *  | ) / E                | A B C D - |
| 7    | +     | / E                  | A B C D - * |
| 8    |       | E                    | A B C D - * E / |
| 9    |       |                      | A B C D - * E / + |

### Final Postfix Expression:

\[ ABCD-*E/+ \]

---

## Example 14: Hard Infix Expression with All Elements

### Infix Expression:

\[ A + (B - C) \times (D / E ^ F) \]

### Step-by-Step Conversion:

| Step | Stack | Remaining Expression | Postfix |
|------|-------|----------------------|---------|
| 1    | +     | A + (B - C) × (D / E ^ F) | A       |
| 2    | +, (  | (B - C) × (D / E ^ F) | A       |
| 3    | +, (, - | B - C) × (D / E ^ F) | A B     |
| 4    | +, (  | C) × (D / E ^ F)     | A B C   |
| 5    | +, *  | ) × (D / E ^ F)      | A B C - |
| 6    | +, *, ( | (D / E ^ F)        | A B C - |
| 7    | +, *, (, / | D / E ^ F       | A B C - D |
| 8    | +, *, (, /, ^ | E ^ F       | A B C - D E |
| 9    | +, *, (, / | F              | A B C - D E F ^ |
| 10   | +, *  | )                   | A B C - D E F ^ / |
| 11   |       |                     | A B C - D E F ^ / * |
| 12   |       |                     | A B C - D E F ^ / * + |

### Final Postfix Expression:

\[ ABC-DEF^/*+ \]

---
# Additional Practice: Infix to Postfix Conversion with Unary Operators

## Example 15: Unary Minus

### Infix Expression:

\[ -A + B \]

### Step-by-Step Conversion:

| Step | Stack | Remaining Expression | Postfix |
|------|-------|----------------------|---------|
| 1    | -     | -A + B               | A       |
| 2    | +     | B                    | A-      |
| 3    |       |                      | A- B +  |

### Final Postfix Expression:

\[ A-B+ \]

---

## Example 16: Unary Plus

### Infix Expression:

\[ +A - B \]

### Step-by-Step Conversion:

| Step | Stack | Remaining Expression | Postfix |
|------|-------|----------------------|---------|
| 1    | +     | +A - B               | A       |
| 2    | -     | B                    | A+      |
| 3    |       |                      | A+ B -  |

### Final Postfix Expression:

\[ A+B- \]

---

## Example 17: Unary Minus with Parentheses

### Infix Expression:

\[ -(A + B) \]

### Step-by-Step Conversion:

| Step | Stack | Remaining Expression | Postfix |
|------|-------|----------------------|---------|
| 1    | -     | -(A + B)             |         |
| 2    | -, (  | (A + B)              |         |
| 3    | -, (, + | A + B)            | A       |
| 4    | -, (  | B)                   | A B     |
| 5    | -     | )                    | A B +   |
| 6    |       |                      | A B + - |

### Final Postfix Expression:

\[ AB+- \]

---

## Example 18: Unary Plus with Multiplication

### Infix Expression:

\[ +A \times B \]

### Step-by-Step Conversion:

| Step | Stack | Remaining Expression | Postfix |
|------|-------|----------------------|---------|
| 1    | +     | +A × B               | A       |
| 2    | *     | B                    | A+      |
| 3    |       |                      | A+ B *  |

### Final Postfix Expression:

\[ A+B* \]

---

## Example 19: Unary Minus with Division

### Infix Expression:

\[ A / -B \]

### Step-by-Step Conversion:

| Step | Stack | Remaining Expression | Postfix |
|------|-------|----------------------|---------|
| 1    | /     | A / -B               | A       |
| 2    |       | -B                   | A B- /  |

### Final Postfix Expression:

\[ AB-/ \]

---

## Example 20: Unary Minus with Exponentiation

### Infix Expression:

\[ -A ^ B \]

### Step-by-Step Conversion:

| Step | Stack | Remaining Expression | Postfix |
|------|-------|----------------------|---------|
| 1    | -     | -A ^ B               | A       |
| 2    | ^     | B                    | A-      |
| 3    |       |                      | A- B ^  |

### Final Postfix Expression:

\[ A-B^ \]

---

## Example 21: Unary Plus with Nested Parentheses

### Infix Expression:

\[ +(A + (B \times C)) \]

### Step-by-Step Conversion:

| Step | Stack | Remaining Expression | Postfix |
|------|-------|----------------------|---------|
| 1    | +     | +(A + (B × C))       |         |
| 2    | +, (  | (A + (B × C))        |         |
| 3    | +, (, + | A + (B × C))      | A       |
| 4    | +, (  | (B × C))             | A B     |
| 5    | +, (, ( | B × C)            | A B     |
| 6    | +, (, (, * | C)            | A B C   |
| 7    | +, (  | )                   | A B C * |
| 8    | +     |                     | A B C * + |
| 9    |       |                     | A B C * + |

### Final Postfix Expression:

\[ ABC*+ \]

---

## Example 22: Unary Minus with Complex Operators

### Infix Expression:

\[ A + -B \times C \]

### Step-by-Step Conversion:

| Step | Stack | Remaining Expression | Postfix |
|------|-------|----------------------|---------|
| 1    | +     | A + -B × C           | A       |
| 2    | +, *  | -B × C               | A B-    |
| 3    | +     | C                    | A B- C *|
| 4    |       |                      | A B- C * + |

### Final Postfix Expression:

\[ AB-C*+ \]

---

## Example 23: Unary Plus with All Operators

### Infix Expression:

\[ +A + B \times C - D / E \]

### Step-by-Step Conversion:

| Step | Stack | Remaining Expression | Postfix |
|------|-------|----------------------|---------|
| 1    | +     | +A + B × C - D / E   | A       |
| 2    | +, +  | B × C - D / E        | A+ B    |
| 3    | +, *  | C - D / E            | A+ B C *|
| 4    | -     | D / E                | A+ B C * + D |
| 5    | /     | E                    | A+ B C * + D E / |
| 6    |       |                      | A+ B C * + D E / - |

### Final Postfix Expression:

\[ A+BC*+DE/- \]

---

## Example 24: Hard Infix Expression with Unary Operators

### Infix Expression:

\[ A + (-B - C) \times (D / E ^ F) \]

### Step-by-Step Conversion:

| Step | Stack | Remaining Expression | Postfix |
|------|-------|----------------------|---------|
| 1    | +     | A + (-B - C) × (D / E ^ F) | A       |
| 2    | +, (  | (-B - C) × (D / E ^ F) | A       |
| 3    | +, (, - | -B - C) × (D / E ^ F) | A B-    |
| 4    | +, (  | C) × (D / E ^ F)     | A B- C  |
| 5    | +, *  | ) × (D / E ^ F)      | A B- C -|
| 6    | +, *, ( | (D / E ^ F)        | A B- C -|
| 7    | +, *, (, / | D / E ^ F       | A B- C - D |
| 8    | +, *, (, /, ^ | E ^ F       | A B- C - D E |
| 9    | +, *, (, / | F              | A B- C - D E F ^ |
| 10   | +, *  | )                   | A B- C - D E F ^ / |
| 11   |       |                     | A B- C - D E F ^ / * |
| 12   |       |                     | A B- C - D E F ^ / * + |

### Final Postfix Expression:

\[ AB-C-DEF^/*+ \]

---

These examples provide a range of practice problems involving unary operators, helping you to master the conversion of infix expressions to postfix notation using a stack.