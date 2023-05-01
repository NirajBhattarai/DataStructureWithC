# DATA TYPES

C language is rich in its data types. ANSI C supports three classes of data types:

1. Primary (or fundamental) data types
2. Derived data types
3. User defined data types.

All the compilers supports five fundamental data types, namely integer (int), character (char), floating point (float), double-precision floating point (double) and void. Many of them also offer extended data types such as long int and long double. The ranges of basic four types are given in Table (1). 

## CONSTANTS, VARIABLES AND KEYWORDS:
   The alphabets , numbers and special symbols when properly combined form constants, variables and keywords. 

## CONSTANTS:

 A Constant is a quantity that doesn’t change. This quantity can be stored at locations in the memory of the computer.

## Types of C Constants:

C constants can be divided into two major categories:

1. Primary Constants
2. Secondary Constants


## PRIMARY CONSTANTS:

1. Integer constants : Integer constants are whole number without any decimal part. Variables can be declared as integers in the following ways :
	int x=5 , y=6;
	short int x =3, y=10;
	long int x=21 , y=636;

2. Floating point constants : Floating point number are the numbers containing decimal points (Real numbers). They may be written in one of the two forms called fractional form or exponent form.
	A real number in fraction form consists of signed or unsigned digits including a decimal point between digits. The following are some real numbers in fractional form:
	2.0,	17.5, 	- 13.0,    - 0.00625
	A real number in exponent form consists of two parts : mantissa and exponent. For instance 5.8 can be written as 0.58 x 101. The following are some real numbers in exponent form:
	152E05,  1.52E07,  0.152E08,  152.0E08,  152E+8,  1520E-04

3. Character constant: Character constant is single character enclosed in single quotes, as in ‘f’. For example,
	‘A’ ,  ‘a’ ,   ‘:’ ,   ‘+’
Declaration of the character variables:
	char x;
 char x, y, z;
	The char stands for the character datatype for declaring the character constants. 
 (d) String constant: String constant is a sequence of zero or more characters enclosed between double quotes. Following are some examples from string constants.

## VARIABLE
  
  `A Variable is a named location in a memory that holds a data value.` The contents of a variable can change. For example in the equation

	3X + Y = 20

Since 3 and 20 cannot change, they are called constants, whereas the quantities X & Y can vary or change hence they are called variables.
All variables must be declared before they can be used. The general form of a variable declaration is 

```
datatype variablename
```

Here datatype must be a valid data type and variablename may consist of one or more variable names separated by commas. For example

```
int i , j , k ;			  	  // Integer variables declaration
float per ;                                   // Floating point number variables declaration
double balance, profit, loss ;  // double variables declaration
char nm1, nm2;		  	 // Character variables declaration
char name[100];                     // String declaration

```
In C, the name of a variable has nothing to do with its type.

## IDENTIFIER 

  In C, the names of variables, functions, labels and various other user-defined items are called identifiers. The length of these identifiers can vary from one to several characters. The first character must be a letter or an underscore, and subsequent characters must be either letters, digits, or underscores. Some of the correct and incorrect identifier names are given below :
```  
Correct	            	Incorrect
count			1count
test23			hi!there
high_bal		          high…balance

```


## KEYWORDS 

Keywords are the reserved words whose meaning has already been explained to the C compiler. The keywords cannot be used as variable names because if we do so we are trying to assign a new meaning to the keyword, which is not allowed by the computer. There are 32 keywords available in C. The complete list of keywords in C are given below: 
		
	auto	double	if	static
	break	else	int	struct
	case	enum	long	switch
	char	extern	near	typedef
	const	float	register	union
	continue	far	return	unsigned
	default	for	short	void
	do 	goto	signed	while


## Program - 1:   A simple hello program

``` #include<stdio.h>
#include<conio.h>
void main( )
{
    clrscr( );     
    printf("Hello to C-programming");
    getch( );
}
```

```
//              : Single line comment
#include  : preprocessor directive. It is an indication for the C-compiler   to add the 
        particular header file inside C-program.
stdio.h    : standard input output header file. It is used for all input  output 
                  predefined functions.
conio.h   : console input output header file. It is used for all console  window       
                  related predefined functions.
void        : void means empty or null. It means that the function is not  returning 
                  any value.
main( )    : main( ) is the most important function of C-programming because the 
                  program execution always started with main( ) function.
{              : It indicate the start of a particular block.
}              : It indicate the end of a particular block.

clrscr( )  : This function is used to clear the previous console window.
printf( )   : Standard output function.
getch( )  : This function is used to get character from keyboard
;              : Statement terminator     

```

## Program - 2:  WAP to use special characters '\n' and '\t'
   
```
#include<stdio.h>
#include<conio.h>
void main( )
{
   clrscr( );
   printf("Name    : Himani Madan");
   printf("\nAddress : #1261/12,Pkl");
   printf("\nPhone   : 9417565720");
   printf("\n\nNAME\tADDRESS\t\tPHONE");
   printf("\nSurbhi\t#1211/14,Pkl\t8712828");
   getch( );
}

```

## Program - 3 :  WAP for Integer Initialization

```
#include<stdio.h>
#include<conio.h>
void main( )
{
   clrscr( );
   int num = 27;
   printf("Given integer is : %d",num);
   getch( );
}
```

## Program - 4:  WAP for Integer Input from user

```
#include<stdio.h>
#include<conio.h>
void main( )
{
  clrscr( );
  int num;
  printf("Enter any integer : ");
  scanf("%d",&num);   //  & stands for memory address of variable
  printf("\nGiven integer is : %d",num);

  getch( );
}

```

## Program - 5:  WAP for Floating point number Initialization

#include<stdio.h>
#include<conio.h>
void main( )
{
  clrscr( );
  float price;
  price = 500.75;
  printf("Given price is : %.2f",price);
  getch( );
}

## Program - 6:  WAP for Floating point number Input from user

```
#include<stdio.h>
#include<conio.h>
void main( )
{
  clrscr( );
  float price;
  printf("Enter price : ");
  scanf("%f",&price);
  printf("\nGiven price is : %.2f",price);
  getch( );
}

```

## Program - 7:  WAP for character initialization

```
#include<stdio.h>
#include<conio.h>
void main( )
{
   clrscr( );
   char ch;
   ch = 'A';
   printf("\nGiven character is : %c",ch);
   getch( );
}

```

## Program - 8:  WAP for character input from user

```
#include<stdio.h>
#include<conio.h>
void main( )
{
  clrscr( );
  char ch;
  printf("Enter any character value : ");
  scanf("%c",&ch);
  printf("\nGiven character is : %c",ch);
  getch( );
}

```

## Program - 9:  WAP for string initialization

```
#include<stdio.h>
#include<conio.h>
void main( )
{
  clrscr( );
  char name[20] = "Sandeep Sangwan";
  printf("%s",name);
  getch( );
}
````
## Program - 10:  WAP for string input from user

```
#include<stdio.h>
#include<conio.h>
void main( )
{
  clrscr( );
  char name[20];
  printf("Enter name : ");
  gets(name);
  printf("\nMy name is : %s",name);
  getch( );
}

```

 
   




