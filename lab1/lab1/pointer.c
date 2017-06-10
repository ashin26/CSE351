/*
 * CSE 351 Lab 1 (Data Lab - Pointers)
 *
 * Aigerim Shintemirova, 1550398, ashin26@uw.edu
 *
 * pointer.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, the following function declaration should prevent a
 * compiler warning. In general, it's not good practice to ignore
 * compiler warnings, but in this case it's OK.
 */
int printf(const char *, ...);

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to this homework by
editing the collection of functions in this source file.

INTEGER CODING RULES:

  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code
  must conform to the following style:

  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. For 1-3, only the Pointer operations *, & and Binary integer
      operations - + * are allowed. For the last three, you may also
      use shifts (<<, >>), ~, ==, and ^.

  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, ?:, sizeof, 
     !, or binary (bitwise & or |)
  6. Use the [] operator to index into arrays for reading or writing.

  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has *undefined* behavior when shifting by a negative amount or an amount
  greater than or equal to the number of bits in the value being shifted.
  e.g. For x >> n, shifts by n < 0 or n >= *size of x* are undefined 
  e.g. if x is a 32-bit int, shifts by >= 32 bits are undefined 
  Undefined means you do not know what result you will get from the operation.

/*
 * STEP 2: Modify the following functions according the coding rules.
 *
 * Test the code below in your own 'main' program.
 *
 */

#endif

/*
 * Return the size of an integer in bytes.
 */
int intSize() {
  int intArray[10];
  int * intPtr1;
  int * intPtr2;
  // Write code to compute size of an integer.
  intPtr1 = intArray;
  intPtr2 = intArray + 1; //address one integer up

  int start = intPtr1;
  int end = intPtr2;
  // returns a difference in bytes that equals to one integer
  return end - start;
}

/*
 * Return the size of a double in bytes.
 */
int doubleSize() {
  double doubArray[10];
  double * doubPtr1;
  double * doubPtr2;
  
  doubPtr1 = doubArray;
  doubPtr2 = doubArray + 1;
  int doubStart = doubPtr1;
  int doubEnd = doubPtr2;
  
  // returns a difference in bytes that equals to one double
  return doubEnd - doubStart;
}

/*
 * Return the size of a pointer in bytes.
 */
int pointerSize() {
  double * ptrArray[10];
  double ** ptrPtr1;
  double ** ptrPtr2;
  
  ptrPtr1 = ptrArray;
  ptrPtr2 = ptrArray + 1;
  int ptrStart = ptrPtr1;
  int ptrEnd = ptrPtr2;

  return ptrEnd - ptrStart;
}

/*
 * Modify intArray[5] to be the value 351 using only &intArray and pointer arithmetic.
 */
int changeValue() {
  int intArray[10];
  int * intPtr1 = intArray;
  // Write code to change value of intArray[5] to 351 using only intPtr1 and the + operator.
  // Remember not to use constants greater than 255.
  int * intPtr2;
  // point to intArray[5] 
  intPtr2 = intPtr1 + 5;
  // assign a new value to intArray[5]
  *intPtr2 = 255 + 96;
  
  return *intPtr2;
}


/*
 * Return 1 if ptr1 and ptr2 are within the *same* 64-byte aligned  block 
 * of memory. Return zero otherwise.
 * Operators / and % and loops are NOT allowed.
 */
int withinSameBlock(int * ptr1, int * ptr2) {
  // picked 25 based on the test cases in ptest
  int maskBlock = (0x1 << 31) >> 25;
  int addrPtr1 = ptr1;
  int addrPtr2 = ptr2;
  // returns 1 if the addresses are within the same 64-byte aligned block 
  return (addrPtr1 & maskBlock) == (addrPtr2 & maskBlock);
}

/*
 * Return 1 if ptr points to an element within the specified intArray, 0 otherwise.
 * size is the size of intArray in number of ints.
 * Pointing anywhere in the array is fine, ptr does not have to 
 * point to the beginning of an element.
 */
int withinArray(int * intArray, int size, int * ptr) {
  // similar to withinSameBlock but the size is restricted by pointer to the first element
  // of the array and the value of size
  int addrArray = intArray;
  int addrPtr = ptr;
  int maskArray = ~(0x1 << 31) & (addrArray - addrPtr);
  return size == (addrPtr & maskArray);
}
