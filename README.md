# functional-language-interpreter
An interpreter for a simple functional programming language. The project was a part of my university course Data Structures and Algorithms. The following is the requirements that were given to me when the project was assigned.

Topic 5: Interpreter for the functional language ThisFunc.

The interpreter must be able to work in interactive mode, in which it allows the user to write a line of code that is evaluated and the result of the evaluation is displayed. Also, your interpreter must be able to run on files that are to be executed and the result of them to be printed on the output of your program.

Let's look at how the ThisFunc language is defined. In this language, there is only one type of literal and they are real numbers that we will mark in this description with <real-number>. For this language to be functional, we will need to be able to define and execute functions. The execution of a function will be done through its name, and the list of arguments of the function enclosed in parentheses. As there can be functions without arguments (with an empty argument list).

<expression> ::= <real-number> | <function-call>
<function-call> ::= <function-name>([<expression>, ...])

Your interpreter should provide several pre-implemented functions that can be called out of the box: add, sub, mul, div, pow, sqrt, sin, cos, eq, le, nand.
nand(#0, #1) returns the boolean evaluation of !#0 || !#1
eq(#0, #1) returns the boolean evaluation of #0 == #1

In addition, the language should allow functions to be declared - with a name and an expression containing their arguments. The arguments of the function will be defined by an integer, the index of the argument, preceded by the symbol ‘#’

<param-expression>::=<expression> | #integer | <function-name>([<param-expression>,...])
<function-declaration>::=<function-name> <- <param-expression>
Evaluating a function declaration does not return a result.

You must also support several special functions:
- The if function, which takes 3 arguments: <test>, <if-true>, <if-false>. This function must evaluate the first argument and if it is non-zero, the result must be the evaluation of the second argument. If the first argument evaluates to 0, the function must return the evaluation of its third argument.
- The list function, which takes any number of arguments. Its evaluation is a list of the arguments.
- The head function, which takes one argument of type list and returns the first element of the list.
- The tail function, which takes one argument of type list and returns a new list whose elements are the elements of the one passed but without the first one.
- The map function, which takes 2 arguments <function-name>, <list>. The result of this function is a list of elements obtained by applying the function to the values ​​of each element of the input list.
- The filter function, which accepts 2 arguments <function-name>, <list>. The result of this function is a list obtained from those elements of the passed list for which the evaluation of the function-argument is different from 0.
In some cases, functions such as if and nand do not need to evaluate the value of all their arguments to calculate their result.

When reading and executing the code, several types of errors can occur - errors when using undeclared functions, using invalid characters in function names, errors when executing the code (for example, division by zero), or others. For each error, you should take care to notify the user with an appropriate message.

Note that when declaring and evaluating functions, it is possible to get recursion that you must support.

Let's look at a few examples:
Calling the function to add two numbers:
add(3, 7)
/> 10
Nested call to the function to add:
add(add(3, 5), add(10, 10))
/> 28
Declaring and calling a function with no arguments that always returns a constant:
myConst <- 7
>
myConst()
> 7
Declaring and calling a function with arguments:
doubleArg <- add(#0, #0)
>
doubleArg(5)
> 10
Declaring and calling a more complex function with arguments:
sumSqr <- add(mul(#0, #0), mul(#1, #1))
>
sumSqr(5, 10)
> 125
Using the conditional function:
if(1, 7, 11)
> 7
if(0, 7, 11)
> 11
if(add(5, -5), 3, 5)
> 5
Using lists:
myList <- list(1, 2, 3, 4)
>
myList()
> [1, 2, 3, 4]
double <- mul(#0, #0)
>
map(double, myList())
> [1, 4, 9, 16]
biggerThanTwo <- nand(le(#0, 2), 1)
>
filter(biggerThanTwo, myList())
> [3, 4]
Recursion:
fact <- if(eq(#0, 0), 1, mul(#0, fact(sub(#0, 1))))
>
fact(0)
> 1
fact(5)
> 120
