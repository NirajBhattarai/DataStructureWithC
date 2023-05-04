# TYPE CONVERSION:

The process of converting one predefined type into another is called Type conversion. When constants and variables of different types are mixed in an expression, they are converted to the same type. There are two types of type conversions:

## Implicit type conversion
## Explicit type conversion

An Implicit type conversion is a conversion performed by the compiler without programmer’s intervention. An implicit conversion is applied generally whenever data types are intermixed in an expression, so as not to lose information. The compiler converts all operands upto the type of the largest operand, which is called type promotion. This is done operation by operation in this order : double, float, long, int, char . For e.g.

```
float a=5.5,c;
int b=3;
c=a+b;            // implicit type conversion
printf(”c : %.2f”,c);
```
	An Explicit type conversion is user-defined that forces an expression to be of specific type. The explicit conversion of an operand to a specific type is called Type casting. Type casting in C is done as shown below :

				(datatype) expression

	where type is a valid C data type to which the conversion is to be done. For example, to make sure that the expression (x + y/2) evaluates to type float, write it as:
				(float) (x + y/2)

           float pi;
           pi=(float)22/7;       // explicit type conversion
 	       printf(“pi : %.2f”,pi);

           