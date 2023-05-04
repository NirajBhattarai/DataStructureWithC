# LOOPING:

There are some situations in C programming in which a particular set of statements are repeated again and again. To avoid the repetition of the statements, C allows a set of instructions to be performed repeatedly until a certain condition is fulfilled by using looping. The main advantage of using loops in C is that it reduces program size and complexity of the program. Looping consists of mainly three parts:

### Initialization
### Test Condition
### Incrementer or Decrementor

Accordingly, there are three types of loops available in C.
while loop
for loop
do-while loop

## while statement :

The simple of all the looping statements in C is the while statement. While loop is entry-controlled loop i.e. the condition is test before executing the body of the loop. The basic syntax of the while statement is:

```
initialization;
while(test condition)
{   
    statement(s);
    incrementor/decrementor;
}
```

Initialization of the control variables is done first, using assignment statements such as i = 1 or count=0. The variables i and count are loop control variables.

The value of the control variable is tested using the test-condition. The test-condition is a relational expression, such as i<=10 that determines when the loop will exit. If the condition is true, the body of the loop is executed, otherwise the loop is terminated and the execution continues with the statement that immediately follows the loop.

When the body of the loop is executed, the statement(s) are executed first and then the control variable is incremented or decremented using an assignment statement such as i++ (or i=i+1) or j – – (or j=j+1) and the new value of control variable is again tested to see whether it satisfies the loop condition. If the condition is satisfied, the body of the loop is again executed. This process continues till the value of the control variables fails to satisfy the test-condition.
```
For example:
	i=1;
	while(i<=10)
	{
	     printf(“%d\t”, i);
	     i++;
           }
Output :
1	2	3	4	5	6	7	8	9	10
```

## for statement :

The for loop is another entry-controlled loop that provides a more concise loop control structure. The general form of for loop is: 
```

for (initialization; test-condition; incrementor/decrementor)
{
        statement(s);						// body of the loop
}

The working of while and for loop is same. (Please note from (a), (b) and (c) of while loop)

For example :

	for(i=1 ; i<=10 ; i++)
	{
	     printf(“%d\t”, i);
           }

Output :
1	2	3	4	5	6	7	8	9	10

```
## do while loop :
The while loop construct makes a test of condition before the loop is executed. Therefore, the body of the loop may not be executed at all if the conditions is not satisfied at the very first attempt. On some occasions it might be necessary to execute the body of the loop before the test is performed. Such situations can be handled with the help of the do while loop. The syntax of do while loop is :


	initialization;
	do
	{
	      statement(s);	
	      incrementor/decrementor;
          }while(test-condition);	

          

On reaching the do statement, the program proceeds to evaluate the body of the loop first. At the end of the loop, the test-condition in the while statement is evaluated. If the condition is true, the program continues to evaluate the body of the loop once again. This process continues as long as the condition is true. When the condition becomes false, the loop will be terminated and the control goes to the statement that appears immediately after the while statement.
Since the test-condition is evaluated at the bottom of the loop, the do..while construct provides an exit-controlled loop and therefore the body of the loop is always executed at least once.

```
For example:
		do
		{
                         printf(“\nInput a number : “);
                         scanf(“%d”,&n);
                    }while(n>0);
```

The above statements of the program reads a number from the keyboard until a zero or a negative number is accepted from the keyboard.

   
## Break statement :

The break statement enables a program to skip over part of the code. A break statement terminates the smallest enclosing while, do-while, for or switch statement. A break within a loop should always be protected within an if statement which provides the test to control the exit condition. For example:

		for (i=1 ; i<=10 ; i++)
		{
     		     if(i = =5)
                         {
		         break;
                         } 
                         printf(“%d\t”,i);
		}
		printf(“\nOut of loop”);
	A break statement skips the rest of the loop and jumps over to the statement following the loop. So the output of the above program is :
		1	2	3	4
		Out of loop

##  Continue statement :

The continue statement is another jump statement like the break statement as both the statements skip over a part of the code. But the difference between the break statement and continue statement is that the continue statement skips the rest of the loop statements and causes the next loop statements to be executed. For example:
		for (i=1 ; i<=10 ; i++)
		{
     		     if(i = =5)
                         {
		         continue;
                         } 
                         printf(“%d\t”,i);
		}
		printf(“\nOut of loop”);

	A continue statement skips the rest of the loop statements for 5th iteration when i=5 and jumps directly to the next iteration i.e. i = 6.. So the output of the above program is :
		1	2	3	4	6	7	8	9	10
		Out of loop

## Go To statement :

 The goto statement is used to change the program execution sequence by transferring the control to some other part of the program. The general syntax of the goto statement is :

goto label;

where label is a valid C++ identifier used to label the destination such that control could be transferred. For example :

	void main()
	{
     clrscr();
	int a,b;
	printf(”Enter two numbers : “);
      scanf(“%d%d”,&a,&b);
	if(a>b)
	   goto output1;
	else
	   goto output2;
	output1 :
	    printf(“Largest value : %d“,a);
	    goto stop;

	output2 :
	    printf(“Largest value : %d“,b);
	    goto stop;
	stop :
     getch(); 
             	}



## INCREMENT ( + + ) AND DECREMENT ( – – ) OPERATORS

C provides ++ and -- operators. These operators are called increment and decrement operators. The increment operator ++ adds 1 to its operand:

	++ x means x = x + 1		x ++ means x = x + 1
	- - x means x = x – 1		x - - means  x = x – 1

These operators exist in 2 types
```
Prefix
Postfix
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
In this example, in the first statement  the value of y is assigned as 5. In the second statement, this value of y is first incremented by 1 and then the incremented value of y is assigned to x. After the second statement, the values of x and y are:

			x = 6;
			y = 6;
Postfix increment or decrement operators (For e.g. x++ or x--) follow the FIRST USE THEN CHANGE rule. They first use the value of the operand in the expression and then increment or decrement the value of the operand. For Example take the following expression :

			int x,y = 5;
			x = y++;
In this example, in the first statement  the value of y is assigned as 5. In the second statement, this value of y is first assigned to x  and then the value of y is incremented by 1. After the second statement, the values of x and y are

			x = 5;
			y = 6; 
