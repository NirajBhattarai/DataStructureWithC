## Show the status of stack converting following infix expression to prost fix P + Q – (R*S/T+U)-V*W

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
