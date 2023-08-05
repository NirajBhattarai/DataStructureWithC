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

## Trace the algorithm to convert infix to postfix with following infix expression ((A + B) - C * D/E)*(H-I)*F+G

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
