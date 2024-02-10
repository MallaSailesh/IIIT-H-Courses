# CSO Tutorial - 2
## Running these files
- For "1.c" and "1.s": 
	- ```gcc 1.c 1.s``` 
	- ```./a.out```
	- Give inputs as asked for and get the answer
- Run "2.c" and "2.s" similarly
- "1.c" and "1.s" give you the sum of two numbers
- "2.c" and "2.s" tells if the first or second number is greater between two give numbers by returning 1 if the first number is greater than or equal to the second and 0 otherwise

## Theory Recap
- I/O related operations are done in main where as all the computation is done in the assembly code
- In order to call a function from another file in ```C``` programming language, we need to use the "extern" keyword (this is nothing specific to assembly, but related to the C programming language)
- To define a function in the assembly file, firstly add the following line: ```.global <function name>``` in the file
- Then, define the function there. You can use "1.s" and "2.s" as reference for how to write functions in assembly

### Branching
- "2.s" implements branching. You can use branching to jump from one part of the code to another. For conditional branching, you can use commands like "jle", "jge" etc. 
- To implement a loop, you would need to jump back to a same branch repeatedly till your termination condition is not met. Once termination condition is met, you can jump out of the branch

## Solution for ```exercise.png```
- Video link: https://youtu.be/wy3e52A7Lu8?t=1