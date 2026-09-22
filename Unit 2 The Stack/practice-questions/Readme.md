# Infix to Postfix: Practice Problems (Easy → Hard)

Each problem is traced one token at a time — see [../application/Readme.md](../application/Readme.md) for the algorithm and precedence/associativity rules these traces follow. Every row shows exactly one token being consumed, what's still left to read (`Remaining Expression`), the stack, and the output built so far.

## 1. Easy — Single Operator

**Infix:** `A + B`

| Step | Token | Stack | Remaining Expression | Output    |
|------|-------|-------|-----------------------|-----------|
| 1    | —     |       | A + B                 |           |
| 2    | A     |       | + B                    | A         |
| 3    | +     | +     | B                      | A         |
| 4    | B     | +     |                        | A B       |
| 5    | end   |       |                        | A B +     |

**Final postfix:** `A B +`

---

## 2. Easy — Precedence, No Pop

**Infix:** `A + B * C`

`*` outranks `+`, so when `*` arrives it just stacks on top instead of forcing `+` off.

| Step | Token | Stack | Remaining Expression | Output      |
|------|-------|-------|-----------------------|-------------|
| 1    | —     |       | A + B * C              |             |
| 2    | A     |       | + B * C                | A           |
| 3    | +     | +     | B * C                  | A           |
| 4    | B     | +     | * C                    | A B         |
| 5    | *     | + *   | C                      | A B         |
| 6    | C     | + *   |                        | A B C       |
| 7    | end   |       |                        | A B C * +   |

**Final postfix:** `A B C * +`

---

## 3. Easy — Precedence, Forces a Pop

**Infix:** `A * B + C`

`+` is lower precedence than the `*` already on the stack, so `*` gets popped before `+` is pushed.

| Step | Token | Stack | Remaining Expression | Output      |
|------|-------|-------|-----------------------|-------------|
| 1    | —     |       | A * B + C              |             |
| 2    | A     |       | * B + C                | A           |
| 3    | *     | *     | B + C                  | A           |
| 4    | B     | *     | + C                    | A B         |
| 5    | +     | +     | C                      | A B *       |
| 6    | C     | +     |                        | A B * C     |
| 7    | end   |       |                        | A B * C +   |

**Final postfix:** `A B * C +`

---

## 4. Medium — Parentheses Override Precedence

**Infix:** `(A + B) * C`

| Step | Token | Stack | Remaining Expression | Output      |
|------|-------|-------|-----------------------|-------------|
| 1    | —     |       | ( A + B ) * C          |             |
| 2    | (     | (     | A + B ) * C            |             |
| 3    | A     | (     | + B ) * C              | A           |
| 4    | +     | ( +   | B ) * C                | A           |
| 5    | B     | ( +   | ) * C                  | A B         |
| 6    | )     |       | * C                    | A B +       |
| 7    | *     | *     | C                      | A B +       |
| 8    | C     | *     |                        | A B + C     |
| 9    | end   |       |                        | A B + C *   |

**Final postfix:** `A B + C *`

---

## 5. Medium — Parentheses on the Other Operand

**Infix:** `A * (B + C)`

| Step | Token | Stack | Remaining Expression | Output      |
|------|-------|-------|-----------------------|-------------|
| 1    | —     |       | A * ( B + C )          |             |
| 2    | A     |       | * ( B + C )            | A           |
| 3    | *     | *     | ( B + C )              | A           |
| 4    | (     | * (   | B + C )                | A           |
| 5    | B     | * (   | + C )                  | A B         |
| 6    | +     | * ( + | C )                    | A B         |
| 7    | C     | * ( + | )                      | A B C       |
| 8    | )     | *     |                        | A B C +     |
| 9    | end   |       |                        | A B C + *   |

**Final postfix:** `A B C + *`

---

## 6. Medium — Left-Associative Chain

**Infix:** `A + B - C * D / E`

| Step | Token | Stack | Remaining Expression | Output              |
|------|-------|-------|-----------------------|----------------------|
| 1    | —     |       | A + B - C * D / E      |                      |
| 2    | A     |       | + B - C * D / E        | A                    |
| 3    | +     | +     | B - C * D / E          | A                    |
| 4    | B     | +     | - C * D / E            | A B                  |
| 5    | -     | -     | C * D / E              | A B +                |
| 6    | C     | -     | * D / E                | A B + C              |
| 7    | *     | - *   | D / E                  | A B + C              |
| 8    | D     | - *   | / E                    | A B + C D            |
| 9    | /     | - /   | E                      | A B + C D *          |
| 10   | E     | - /   |                        | A B + C D * E        |
| 11   | end   |       |                        | A B + C D * E / -    |

**Final postfix:** `A B + C D * E / -`

---

## 7. Medium-Hard — Nested Parentheses

**Infix:** `(A + (B * C)) - D`

| Step | Token | Stack   | Remaining Expression | Output          |
|------|-------|---------|-----------------------|------------------|
| 1    | —     |         | ( A + ( B * C ) ) - D  |                  |
| 2    | (     | (       | A + ( B * C ) ) - D    |                  |
| 3    | A     | (       | + ( B * C ) ) - D      | A                |
| 4    | +     | ( +     | ( B * C ) ) - D        | A                |
| 5    | (     | ( + (   | B * C ) ) - D          | A                |
| 6    | B     | ( + (   | * C ) ) - D            | A B              |
| 7    | *     | ( + ( * | C ) ) - D              | A B              |
| 8    | C     | ( + ( * | ) ) - D                | A B C            |
| 9    | )     | ( +     | ) - D                  | A B C *          |
| 10   | )     |         | - D                    | A B C * +        |
| 11   | -     | -       | D                      | A B C * +        |
| 12   | D     | -       |                        | A B C * + D      |
| 13   | end   |         |                        | A B C * + D -    |

**Final postfix:** `A B C * + D -`

---

## 8. Hard — Right-Associative Exponent Chain

**Infix:** `A ^ B ^ C`

`^` is right-associative, so a second `^` does **not** pop the first one off the stack — it stacks on top, and the flush at the end reverses the order.

| Step | Token | Stack | Remaining Expression | Output      |
|------|-------|-------|-----------------------|-------------|
| 1    | —     |       | A ^ B ^ C              |             |
| 2    | A     |       | ^ B ^ C                | A           |
| 3    | ^     | ^     | B ^ C                  | A           |
| 4    | B     | ^     | ^ C                    | A B         |
| 5    | ^     | ^ ^   | C                      | A B         |
| 6    | C     | ^ ^   |                        | A B C       |
| 7    | end   |       |                        | A B C ^ ^   |

**Final postfix:** `A B C ^ ^`

---

## 9. Hard — Nested Parentheses on Both Sides

**Infix:** `((A + B) * (C - D)) / E`

| Step | Token | Stack   | Remaining Expression       | Output              |
|------|-------|---------|------------------------------|----------------------|
| 1    | —     |         | ( ( A + B ) * ( C - D ) ) / E |                      |
| 2    | (     | (       | ( A + B ) * ( C - D ) ) / E   |                      |
| 3    | (     | ( (     | A + B ) * ( C - D ) ) / E     |                      |
| 4    | A     | ( (     | + B ) * ( C - D ) ) / E       | A                    |
| 5    | +     | ( ( +   | B ) * ( C - D ) ) / E         | A                    |
| 6    | B     | ( ( +   | ) * ( C - D ) ) / E           | A B                  |
| 7    | )     | (       | * ( C - D ) ) / E             | A B +                |
| 8    | *     | ( *     | ( C - D ) ) / E               | A B +                |
| 9    | (     | ( * (   | C - D ) ) / E                 | A B +                |
| 10   | C     | ( * (   | - D ) ) / E                   | A B + C              |
| 11   | -     | ( * ( - | D ) ) / E                     | A B + C              |
| 12   | D     | ( * ( - | ) ) / E                       | A B + C D            |
| 13   | )     | ( *     | ) / E                         | A B + C D -          |
| 14   | )     |         | / E                           | A B + C D - *        |
| 15   | /     | /       | E                             | A B + C D - *        |
| 16   | E     | /       |                                | A B + C D - * E      |
| 17   | end   |         |                                | A B + C D - * E /    |

**Final postfix:** `A B + C D - * E /`

---

## 10. Hardest — All Operators, Nesting, and Exponentiation

**Infix:** `A + (B - C) * (D / E ^ F)`

| Step | Token | Stack     | Remaining Expression         | Output                    |
|------|-------|-----------|--------------------------------|-----------------------------|
| 1    | —     |           | A + ( B - C ) * ( D / E ^ F )  |                              |
| 2    | A     |           | + ( B - C ) * ( D / E ^ F )    | A                            |
| 3    | +     | +         | ( B - C ) * ( D / E ^ F )      | A                            |
| 4    | (     | + (       | B - C ) * ( D / E ^ F )        | A                            |
| 5    | B     | + (       | - C ) * ( D / E ^ F )          | A B                          |
| 6    | -     | + ( -     | C ) * ( D / E ^ F )            | A B                          |
| 7    | C     | + ( -     | ) * ( D / E ^ F )              | A B C                        |
| 8    | )     | +         | * ( D / E ^ F )                | A B C -                      |
| 9    | *     | + *       | ( D / E ^ F )                  | A B C -                      |
| 10   | (     | + * (     | D / E ^ F )                    | A B C -                      |
| 11   | D     | + * (     | / E ^ F )                      | A B C - D                    |
| 12   | /     | + * ( /   | E ^ F )                        | A B C - D                    |
| 13   | E     | + * ( /   | ^ F )                          | A B C - D E                  |
| 14   | ^     | + * ( / ^ | F )                            | A B C - D E                  |
| 15   | F     | + * ( / ^ | )                              | A B C - D E F                |
| 16   | )     | + *       |                                | A B C - D E F ^ /            |
| 17   | end   |           |                                | A B C - D E F ^ / * +        |

**Final postfix:** `A B C - D E F ^ / * +`

---

## 11. Hardest — Several Operands Inside a Single Parenthesis

**Infix:** `A * (B + C * D - E) / F`

Only one pair of parentheses this time, but it holds four operands (`B`, `C`, `D`, `E`) and mixed-precedence operators, so the stack still has to sort out `+`, `*`, and `-` *within* that one group before the `)` lets anything escape it.

| Step | Token | Stack     | Remaining Expression           | Output                |
|------|-------|-----------|----------------------------------|-------------------------|
| 1    | —     |           | A * ( B + C * D - E ) / F        |                          |
| 2    | A     |           | * ( B + C * D - E ) / F          | A                        |
| 3    | *     | *         | ( B + C * D - E ) / F            | A                        |
| 4    | (     | * (       | B + C * D - E ) / F              | A                        |
| 5    | B     | * (       | + C * D - E ) / F                | A B                      |
| 6    | +     | * ( +     | C * D - E ) / F                  | A B                      |
| 7    | C     | * ( +     | * D - E ) / F                    | A B C                    |
| 8    | *     | * ( + *   | D - E ) / F                      | A B C                    |
| 9    | D     | * ( + *   | - E ) / F                        | A B C D                  |
| 10   | -     | * ( -     | E ) / F                          | A B C D * +              |
| 11   | E     | * ( -     | ) / F                            | A B C D * + E            |
| 12   | )     | *         | / F                               | A B C D * + E -          |
| 13   | /     | /         | F                                 | A B C D * + E - *        |
| 14   | F     | /         |                                   | A B C D * + E - * F      |
| 15   | end   |           |                                   | A B C D * + E - * F /    |

At step 10, `-` arrives while the stack (above the `(`) holds `+ *` — both outrank `-`, so *both* get popped (first `*`, then `+`) before `-` is pushed; the algorithm never looks past the `(` while doing this.

**Final postfix:** `A B C D * + E - * F /`
