# DECISION MAKING STATEMENTS :

A C program is a set of statements which are normally executed sequentially in the order in which they appear. This happens when no options or no repetitions of certain calculations are necessary. However, in practice, we have a number of situations where we may have to change the order of execution of statements based on certain conditions, or repeat a group of statements until certain specified conditions are met. This involves a kind of decision making to see whether a particular condition has occurred or not and then direct the computer to execute certain statements accordingly. C language must be able to perform different sets of actions depending upon the circumstances. C has two major decision making (conditional) statements:

### The If-else statement
### The Switch statement 


## IF ELSE STATEMENT

There are mainly 3 types of If Else Statements used in C :

### Simple If Statement
### If Else Statement
## Nested If Else Ladder (if else if statement)

(1) Simple If Statement 

The general form of simple If statement is:
```
if (condition)
{
   Statement-block;
}
Statement-x;
```
The statement block may be a single statement or a group of statements. If the condition is true, the statement-block will be executed and then the execution will jump to the statement-x. If the condition is false, the statement-block will be skipped and the execution will directly jump to the statement-x. For example,
```
int a=5;
if(a= =5)
{
  printf(“%d”,a);
}
```
In above simple if statement, the printf statement inside if block is executed because the value of a is initialized as 5 and the condition a==5 inside if is true. Take another example,

```
int a=8;
if(a= =5)
{
  printf(“%d”,a);
}
```
In above simple if statement, the printf statement inside if block is skipped because the value of a is initialized as 8 and the condition a==5 inside if is false.

## Program 1 :   WAP to display the greatest out of three numbers.

```
#include<stdio.h>
#include<conio.h>
void main()
{
  int a,b,c,max; 
  clrscr();
  printf("Enter three numbers : ");
  scanf("%d%d%d",&a,&b,&c);
  max=a;
  if(b>max)
    max=b;
  if(c>max)
    max=c;
   printf("\nLargest number is : %d",max);
  getch();
}
```
## If Else Statement

The if else statement is an extension of the simple if statement. The general form of if else statement is :
```
if (condition)
{
  true-block statement(s);
}
else
{
  false-block statement(s);
}
statement-x;
```
In the above syntax, if the condition is true, then the true-block statement(s), immediately following the if statements are executed, otherwise the false-block statement(s) are executed. In either case, either true-block or false-block will be executed. In both the cases, the control is transferred subsequently to statement-x. For example,

```
if(a>b)
{
   printf(“%d is greater”,a);
}
else
{
   printf(“%d is greater”,b);
}
```

In above example, if the condition a>b inside if is true, then the printf statement inside if block is executed and the else block statement is skipped. If the condition a>b is false, then the printf statement inside if block is skipped and the else block printf statement is executed. 

## Program 2 :  WAP to display the greatest out of two numbers.

```
#include<stdio.h>
#include<conio.h>
void main()
{
clrscr();
int a,b;
printf("Enter two numbers : ");
scanf("%d%d",&a,&b);

if(a>b)
  printf("\n%d is greater than %d",a,b);
else
  printf("\n%d is greater than %d",b,a);
getch();
}
```

## Program 3 : WAP to accept the age of a person and display whether the person is  eligible to vote or not ?

```
#include<stdio.h>
#include<conio.h>
void main()
{
clrscr();
int age;
printf("Enter age : ");
scanf("%d",&age);
if(age>=18)
  printf("\nPerson is eligible to vote ");
else
  printf("\nPerson is not eligible to vote ");
getch();
}

```

## Program 4 :  WAP to accept an integer from keyboard and display whether the given  number is even or odd ?    

```
#include<stdio.h>
#include<conio.h>
void main()
{
clrscr();
int n;
printf("Enter the value of n : ");
scanf("%d",&n);
if(n%2==0)
  printf("\n%d is even",n);
else
  printf("\n%d is odd",n);
getch();
}

```

## Program 5 :  WAP to accept an year from the keyboard and display whether the given year is a leap year or not ? 

```
#include<stdio.h>
#include<conio.h>
void main()
{
clrscr();
int yr;
printf("Enter the year : ");
scanf("%d",&yr);
if(yr%4==0)
 printf("\n%d is leap year",yr);
else
 printf("\n%d is not leap year ",yr);
getch();
}

```

## Nested Else-If Ladder :

There is another way of putting ifs together when multipath decisions are involved. A multipath decision is a chain of ifs in which the statement associated with each else is an if. The general form of a Nested if else Ladder is :
```

if(condition 1)
   Statement-1;
else
    if(condition 2)
       Statement-2;
    else
       if(condition 3)
          Statement-3;
       else
            …………..
             …………….
             else
               if(condition – (n-1)
	       Statement-(n-1);
               else
                  Statement-n;
Statement-x;
```

The construct is known as the else if ladder. The conditions are evaluated from the top (of the ladder), downwards. As soon as a true condition is found, the statement associated with it is executed and the control is transferred to the statement-x (skipping the rest of the ladder). When all the (n-1) conditions become false, then the final else containing the Statement-n will be executed. There is no limit of nested else statements in nested If-Else Ladder. Let us consider an example of grading the students in an academic institution. The grading is done according to the following rules:
```
	Average marks		Grade
	80 to 100			Honours
	60 to 79			First division
	50 to 59			Second division
	40 to 49			Third division
	0 to 39			Fail.
The grading is done using the else if ladder as follows:
	 if (marks >=80 )
	    printf(“Honours”);
	else  
	   if (marks >= 60)
	        printf(“First division”);
     	   else  
	        if (marks >= 50)
	           printf(“Second division”);
      	       else  
	           if (marks >= 40)
	 	    printf(“Third division”);
		 else
		     printf(“Fail”);	

```

## Program 6 :  WAP to accept a day number [1-7] and display its equivalent day. For example, 1 for Sunday, 2 for Monday,……, 7 for Saturday. 

```
#include<stdio.h>
#include<conio.h>
void main()
{
clrscr();
int dayno;
printf("Enter day number [1/2/3/4/5/6/7] : ");
scanf("%d",&dayno);
printf("\n");
if(dayno==1)
 printf("Sunday");
else
 if(dayno==2)
  printf("Monday");
 else
  if(dayno==3)
   printf("Tuesday");
  else
   if(dayno==4)
    printf("Wednesday");
   else
    if(dayno==5)
     printf("Thursday");
    else
     if(dayno==6)
      printf("Friday");
     else
      if(dayno==7)
       printf("Saturday");
      else
       printf("Invalid day number entered");
getch();
}
```

## Program 7 :  WAP to display the result of a student acc. to grades given below :

 ``` 
  Grade				Result
    A					First class with distinction
    B					First class
    C					Second class
    D 					Conditionally passed
   For all other grades   		Failed     

#include<stdio.h>
#include<conio.h>

void main()
{
clrscr();
char grade;
printf("Enter the grade [A/B/C/D] :");
scanf("%c",&grade);
printf("\n");
if(grade=='A')
 printf("First class with distinction");
 else
  if(grade=='B')
   printf("First class");
    else
     if(grade=='C')
      printf("Second class");
       else
	if(grade=='D')
	 printf("Conditionally passed");
	  else
	   printf("Failed");
getch();
}
```

## Program 8 :  WAP to display the roots of a quadratic equation and also display whether  the roots are real and equal, real and unequal or complex and imaginery.       

```
#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
clrscr();
float a,b,c,d,r1,r2;
printf("Enter the cofficent's a,b,c of a quadratic equation : ");
scanf("%f%f%f",&a,&b,&c);
d=((b*b)-(4*a*c));
if(d==0)
{
 r1=r2=-b/(2*a);
 printf("\nRoot-1 : %.2f\nRoot-2 : %.2f",r1,r2);
 printf("\nRoots are real and equal");
}
 else
  if(d>0)
  {
   r1=(-b+sqrt(d))/(2*a);
   r2=(-b-sqrt(d))/(2*a);
   printf("\nRoot-1 : %.2f\nRoot-2 : %.2f",r1,r2);
   printf("\nRoots are real and unequal");
  }
  else
   printf("\nRoots are complex and imaginery");
getch();
}
```


## SWITCH STATEMENT


C has a built-in multiway decision statement known as a switch. The switch statement tests the value of a given variable (or expression) against a list of case values and when a match is found, a block of statements associated with that case is executed. The general form of the switch statement is as shown below:



	switch(variable or expression)
	{
	case constant 1 :   statement 1;
			             break;
	case constant 2 :   statement 2;
			             break;

	case constant 3 :   statement 3;
			             break;
	………….
	………….
	case constant n-1 :   statement n-1;
			                break;
	default		:     statement n;
	}
	statement-x;

The variable or expression is integer or character variable or expression. Constant 1, Constant 2 …….. are integer or character constants and are known as case labels. Each of these constant should be unique within a switch statement. Statement 1, statement 2…….are statement lists and may contain zero or more statements. There is no need to put braces around these blocks. Note that case labels end with a colon ( : ).
When the switch is executed, the value of the variable or expression is successfully compared against the values constant 1, constant 2,….. . If a match is found whose value matches with the value of the variable or expression, then the block of statement(s) that follows the case are executed.
The break statement at the end of each block signals the end of a particular case and causes an exit from the switch statement, transferring the control the statement-x following the switch.
The default is an optional case. When present, it will be executed if the value of the variable or expression does not match with any of the case constants. If not present, no action takes place if all matches fail and the control goes to statement-x.
 
## Program 1 :  WAP to accept a day number [1-7] and display its equivalent day

```
#include<stdio.h>
#include<conio.h>
void main()
{
clrscr();
int dayno;

printf("Enter day number [1/2/3/4/5/6/7] : ");
scanf("%d",&dayno);
printf("\n");
switch(dayno)
{
case 1 : printf("Sunday");
	   break;
case 2 : printf("Monday");
	   break;
case 3 : printf("Tuesday");
	   break;
case 4 : printf("Wednesday");
	   break;
case 5 : printf("Thursday");
	   break;
case 6 : printf("Friday");
	   break;
case 7 : printf("Saturday");
	   break;
default : printf("Invalid day no. entered");
}
getch();
}
```

## Program 2 :  WAP to accept the grade of a student and display the result of student  acc. to conditions given below :

    GRADE				RESULT
     A					First class with distinction
     B					First class
     C                  			Second class
     D                  			Conditionally passed
     For all other grades  	Failed  

```
#include<stdio.h>
#include<conio.h>
void main()
{
clrscr();
char grade;
printf("Enter grade [A/B/C/D] : ");
scanf("%c",&grade);
printf("\n");
switch(grade)
{
case 'A' : printf("First class with distinction");
	     break;
case 'B' : printf("First class");
	     break;
case 'C' : printf("Second class");
	     break;
case 'D' : printf("conditionally passed");
	     break;
default  : printf("Failed");
}
getch();
}
```

## Program 3 :  WAP to accept an alphabet from the keyboard and display whether it is  a vowel or a consonant 
```
#include<stdio.h>
#include<conio.h>
void main()
{
clrscr();
char alpha;
printf("Enter an alphabet : ");
scanf("%c",&alpha);
printf("\n");
switch(alpha)
{
case 'A' :
case 'E' :
case 'I'   :
case 'O' :
case 'U' :
case 'a'  :
case 'e'  :
case 'i'   :
case 'o'  :
case 'u'  : printf("%c is a Vowel",alpha);
	      break;
default  :  printf("%c is a Consonant",alpha);
}
getch();
}
```
## Program 4 :  WAP to accept two numbers and also accept one operator [+ , - , * , / , %] . Display  the arithmetic operation of numbers acc. to arithmetic operator entered by the user.      								       (M. Imp.)
```
#include<stdio.h>
#include<conio.h>
void main()
{
clrscr();
int a,b;
char op;
printf("Enter two numbers :");
scanf("%d%d",&a,&b);
printf("Enter operator[+,-,*,/,%] :");
fflush(stdin);
scanf("%c",&op);
printf("\n");
switch(op)
{
case '+' : printf("Sum of %d and %d is : %d",a,b,a+b);
	     break;
case '-' :  printf("Difference of %d and %d is : %d ",a,b,a-b);
	     break;
case '*' :  printf("Product of %d and %d is : %d",a,b,a*b);
	     break;
case '/'  : if(b==0)
	       printf("Divide by zero error. Enter divisor other than zero");
	     else
	       printf("Quotient of %d and %d is : %d",a,b,a/b);
	     break;
case '%': if(b==0)
	       printf("Divide by zero error. Enter divisor other than zero");
	     else
	       printf("Remainder of %d and %d is : %d",a,b,a%b);
	     break;
default  : printf("Invalid operator");
}
getch();
}
```



## Program 5 :  WAP to display the area acc. to choices given below :
  1.  Area of a rectangle
  2.  Area of a circle
  3.  Area of a square      

```
#include<stdio.h>
#include<conio.h>
void main()
{
clrscr();
int choice;
printf("     AREA'S");
printf("\n-----------------");
printf("\n1. Rectangle");
printf("\n2. Circle ");
printf("\n3. Square ");
printf("\n-----------------");
printf("\nEnter your choice [1/2/3] : ");
scanf("%d",&choice);
printf("\n");
switch(choice)
{
case 1 : int l,b,ar1;
 	   printf("Enter length and breath of rectangle : ");
	   scanf("%d%d",&l,&b);
  	   ar1=l*b;
	   printf("\nArea of rectangle is :%d",ar1);
	   break;
case 2 : float rad,ar2;
	   printf("Enter radius of circle :");
	   scanf("%f",&rad);
	   ar2=((float)22/7)*rad*rad;
	   printf("\nArea of circle is :%.2f",ar2);
	   break;
case 3 : int len,ar3;
	   printf("Enter length of square :");
	   scanf("%d",&len);
	   ar3=len*len;
	   printf("\nArea of square is :%d",ar3);
	   break;
default : printf("\nInvalid option");
}
getch();
}
```

