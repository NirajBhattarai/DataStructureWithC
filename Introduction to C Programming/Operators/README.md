# OPERATORS :

An operator is a symbol or letter which causes the compiler to take an action and yield a value. The operations being carried out are represented by operators. An operator acts on different data items/entities called Operands.

## TYPES OF OPERATORS

### Arithmetic Operators
### Relational Operators
### Logical Operators
### Ternary Operators
### Increment and Decrement Operators


## Arithmetic Operators

Arithmetic operators are those operators which perform arithmetic operations. Arithmetic operators are considered as basic operators and known as binary operators as they require two variables to be evaluated. For e.g. if we want to multiply two numbers, one has to enter or feed the multiplicand and the multiplier. That is why it is considered as a binary operator. There are mainly five types of arithmetic operators used in C language. 

```
Operator   Meaning
+       Addition
-       Subtraction
*       Multiplication
/       Division
%       Modulo(Remainder of an integer division)
```

```
Addition Operator(+)
	int a = 4, b = 2, c;
	c = a + b;		
Output : c = 6

Subtraction Operator(-)
	int a = 4, b = 2, c;
	c = a - b;
	Output : c = 2

Multiplication Operator(*)
	int a = 4, b = 2, c;
	c = a * b;
	Output : c = 8
Division Operator(/)
	int a = 5, b = 2, c;
	c = a / b;
	Output : c = 2

Modulus Operator(%)
	int a = 5, b = 2, c;
	c = a % b;	
	Output : c = 1
```

## Relational Operators

Relational (Comparison) operators compare values to see if they  are equal or if one of them is greater than or less than the other and so on. Comparison operators in C produce only a one or zero result. They are often specified as “true” or “false” respectively. The following operators are used to perform the relational or comparison operations of the two variables or expressions

```
Operator Meaning
< Less than
> Greater than
< = Less than or equal to
> = Greater than or equal to
= = Equal to
! = Not equal to
```

The relational(comparison) operators are represented in the following syntax :
expression_1  realtional_operator  expression_2
For e.g.

```
Expression
Result
3 > 4
False
6 < = 2
False
10 > -32
True
(23 * 7) > = (-67 + 89)
True
8 = = 6 
False
7 ! = 4
True
```

## Difference between Equality (= =) and Assignment(=) Operators

The Equality operator = = is used to test check the equality of the given expression or a statement whereas Assignment operator = is used to assign the value of the variable or expression on the RHS to the LHS. 
For example, the expression
		value = = 3
tests whether value is equal to 3 ? . The expression has the boolean value true if the comparison is true and boolean false if it is false. But the expression
		value = 3
assigns 3 to the value. The whole expression, in this case, has the value 3 because that’s the value of the LHS.

## Logical Operators

Logical operators are those operators which perform logical operations. There are three different types of logical operators used in C language :

### Logical AND
### Logical OR
### Logical NOT

## Logical AND operator ( && )

The Logical AND operator is used in the following manner :
	expression1  &&  expression2
The results of the logical AND operator are :

```
Situation  Results
True && True True
True && False False
False && True False
False && False False
```

```
For e.g. 
if a = 4, b= 5 and c=6, then
(a < b) && (b<c)  results in true because both expressions are true.
```

## Logical OR operator ( || )

The Logical OR operator is used in the following manner :
	expression1  ||  expression2

The results of the logical OR operator are :
```
Situation Results
True || True True
True || False True
False || True True
False || False False
```

For e.g. 

if a = 4, b= 5 and c = 6, then
(a < b) || (b>c)  results in true because first expression is true and second is false.

## Logical NOT operator ( ! )

The Logical NOT operator is used in the following manner:
	! (expression1)
The results of the logical operators are :
Situation Results
!(True) False
! (False) True


For e.g.

```
! (4 > 6)  results in true because (4>6) is false.
! (5 = = 5) results in false because (5 = = 5) is true.
```

## Ternary Operators or Conditional Operators (?:)

C programming offers a Conditional operator (? :) that stores a value depending upon a condition. This operator is called Ternary operator i.e. it requires three expressions. The general form of the Ternary Operator ?: is as follows :

		Expression 1 ? Expression 2 : Expression 3

	IF Expression 1 evaluates to true i.e. 1, then the value of the whole expression is the value of the Expression 2, otherwise, the value of the whole expression is the value of the Expression 3. For Example:

		max = (a >b) ? a :b ;

	The value of ‘a’ variable will be assigned to variable ‘max’ if the test expression a>b evaluates to true otherwise the value of variable ‘b’ will be assigned to variable ‘max’.

## Increment (++) and Decrement (– –) 

C provides ++ and -- operators. These operators are called increment and decrement operators. The increment operator ++ adds 1 to its operand.
```
	++ x means x = x + 1		x ++ means x = x + 1
	- - x means x = x – 1		x - - means  x = x – 1
```
These operators exist in 2 types
Prefix
Postfix
```
Prefix means before its operand. For example
	++ x   
 	- - x
Postfix means after its operand. For example
	x ++
	x - -
```
Prefix increment or decrement operators (For e.g. ++x or --x) follow the FIRST CHANGE THEN USE rule. They first change the value of their operand and then use a new value for the expression. For Example take the following expression :

    		int x,y = 5;
			x = ++y;

In this example, in the first statement the variable y is initialized with value 5. In the second statement, this value of y is first incremented by 1 and then the incremented value of y is assigned to x. After the second statement, the values of x and y are

			x = 6;
			y = 6;
Postfix increment or decrement operators (For e.g. x++ or x--) follow the FIRST USE THEN CHANGE rule. They first use the value of the operand in the expression and then increment or decrement the value of the operand. For Example take the following expression :

			int x,y = 5;
			x = y++;

In this example, in the first statement  the value of y is assigned as 5. In the second statement, this value of y is first assigned to x  and then the value of y is incremented by 1. After the second statement, the values of x and y are

			x = 5;
			y = 6;

## Program - 11:  WAP to accept two integers and display their sum, difference, product, quotient and remainder  

```
#include<stdio.h>
#include<conio.h>
void main()
{
  clrscr( );
    int n1,n2,sm,diff,prod,quot,rem;
    printf("Enter two numbers : ");
    scanf("%d%d",&n1,&n2);
    sm=n1+n2;
    diff=n1-n2;
    prod=n1*n2;
    quot=n1/n2;
    rem=n1%n2;
    printf("\nSum           : %d",sm);
    printf("\nDifference  : %d",diff);
    printf("\nProduct      : %d",prod);
    printf("\nQuotient     : %d",quot);
    printf("\nRemainder : %d",rem);
  getch( );
}

```

### Program - 12:  WAP to accept the name, basic salary, HRA and DA of an employee. Calculate and display the gross salary of employee.
gs = bs+hra+da  

```
#include<stdio.h>
#include<conio.h>
void main( )
{
clrscr( );
  char name[20];
  float bs,hra,da,gs;
  printf("Enter name of employee : ");
  gets(name);
  printf("Enter basic salary, HRA and DA of %s : ",name);
  scanf("%f%f%f",&bs,&hra,&da);
  gs = bs+hra+da;
  printf("\nGross salary of %s is : %.2f",name,gs); 
  getch( );
}

```

## Program - 13:  WAP to accept the name & basic salary of an employee. Calculate and display the gross salary of employee  acc. to conditions given below :
HRA  =  40% of basic salary.
DA  =  30% of basic salary.
gs = bs+hra+da  

```
#include<stdio.h>
#include<conio.h>
void main( )
{
 clrscr( );
  char name[20];
  float bs,hra,da,gs;
  printf("Enter name of employee : ");
  gets(name);
  printf("Enter basic salary of %s : ",name);
  scanf("%f",&bs);
  hra = bs*((float)40/100);
  da = bs*0.3;
  gs = bs+hra+da;
  printf("\nGross salary of %s is : %.2f",name,gs);
 getch( );
}

```
## Program - 14: WAP to display the area and perimeter of a rectangle
```
#include<stdio.h>
#include<conio.h>
void main( )
{
 clrscr( );
  int l,b;
  float area,perimeter;
  printf("Enter length and breadth of rectangle : ");
  scanf("%d%d",&l,&b);
  area = l*b;
  perimeter = 2*(l+b);
  printf("\nArea of rectangle is : %.2f",area);
  printf("\nPerimeter of rectangle is : %.2f",perimeter);
 getch( );
}
```
## Program - 15:  WAP to display the area and circumference of a circle

```
#include<stdio.h>
#include<conio.h>
void main( )
{
  clrscr( );
  float rad,area,cmf,pi;
  pi = (float)22/7;
  printf("Enter radius of circle : ");
  scanf("%f",&rad);
  area = pi*rad*rad;
  cmf = 2*pi*rad;
  printf("\nArea of circle is : %.2f",area);
  printf("\nCircumference of circle is : %.2f",cmf);
  getch( );
}

```

## Program - 16:  WAP to accept the marks of a student in 5 different subjects and display the aggregate and total percentage.

```
#include<stdio.h>
#include<conio.h>

void main( )
{
  clrscr( );
  int eng,hin,math,sc,comp;
  float agg,per;
  printf("Enter marks of 5 subjects : ");
  scanf("%d%d%d%d%d",&eng,&hin,&math,&sc,&comp);
  agg = eng+hin+math+sc+comp;
  per = agg/5;
  printf("\nAggregate marks are : %.2f",agg);
  printf("\nTotal percentage is : %.2f",per); 
  getch( );
}
```
## Program - 17:  Mathematical functions (Square root)
```
#include<stdio.h>
#include<conio.h>
#include<math.h>
void main( )
{
  clrscr( );
  float num;
  printf("Enter number : ");
  scanf("%f",&num);
  printf("\nSquare root of %.2f is : %.2f",num,sqrt(num));
  getch( );
}
```
## Program - 18:  Mathematical function (Power)

```
#include<stdio.h>
#include<conio.h>
#include<math.h>
void main( )
{
 clrscr( );
 int n,p;
 printf("Enter number and its power : ");
 scanf("%d%d",&n,&p);
 printf("\n%d raised to the power %d is : %.2f",n,p,pow(n,p));
 getch( );
}
```

## Program - 19: Mathematical function (Absolute value of integer & floating pt. number)

```
#include<stdio.h>
#include<conio.h>
#include<math.h>

void main( )
{
clrscr( );

// Absolute value of Integer
 int n;
 printf("Enter an integer : ");
 scanf("%d",&n);
 printf("\nAbsolute value of %d is : %d",n,abs(n));

// Absolute value of Floating pt. number
  float num; 
  printf("\n\nEnter a floating pt. number : ");
 scanf("%f",&num);
 printf("\nAbsolute value of %.2f is : %.2f",num,fabs(num));
 getch( );
}
```


### Program - 20:  WAP to determine the area of a triangle by using Hero's formula.
```
#include<stdio.h>
#include<conio.h>
#include<math.h>
void main( )
{
  clrscr( );
   float a,b,c,s,area;
   printf("Enter three sides of a triangle : ");
   scanf("%f%f%f",&a,&b,&c);
   s = (a+b+c)/2;
   area = sqrt(s*(s-a)*(s-b)*(s-c));
    printf("\nArea of triangle is : %.2f",area);
  getch( );
}
```
## Program - 21:  WAP to accept the temperature in Fahrenheit and convert it into Celsius.

```
#include<stdio.h>
#include<conio.h>
void main( )
{
 clrscr( );
   float f,c;
   printf("Enter temperature in Fahrenheit : ");
   scanf("%f",&f);
   c = (f-32)/1.8;
   printf("\nEqu. temperature in Celsius is : %.2f",c);
 getch( );
}

```

## Program - 22:  WAP to swap two numbers by using 3rd variable (M. Imp.)

```
#include<stdio.h>
#include<conio.h>
void main()
{
 clrscr();
  int a,b,temp;
  printf("Enter two numbers : ");
  scanf("%d%d",&a,&b);
  printf("\nBefore swapping\n");
  printf("a : %d\tb : %d",a,b);
  temp=a;
  a=b;
  b=temp;
  printf("\n\nAfter swapping\n");
  printf("a : %d\tb : %d",a,b);
 getch();
}
```

## Program - 23:  WAP to swap two numbers without using 3rd variable (M. Imp.)
```
#include<stdio.h>
#include<conio.h>
void main()
{
  clrscr();
  int a,b;
  printf("Enter two numbers : ");
  scanf("%d%d",&a,&b); 
  printf("\nBefore swapping\n");
  printf("a : %d\tb : %d",a,b);
  a = a + b;
  b = a - b;
  a = a - b;
  printf("\n\nAfter swapping\n");
  printf("a : %d\tb : %d",a,b);
 getch();
}
```