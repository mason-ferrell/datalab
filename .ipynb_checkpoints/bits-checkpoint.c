/* 
 * CS:APP Data Lab 
 * 
 * Mason Ferrell, 108-42-4192
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
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
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
         
/* 
 * bitNor - ~(x|y) using only ~ and & 
 *   Example: bitNor(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitNor(int x, int y) {
  return (~x & ~y);
}
/* 
 * fitsShort - return 1 if x can be represented as a 
 *   16-bit, two's complement integer.
 *   Examples: fitsShort(33000) = 0, fitsShort(-32768) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int fitsShort(int x) {
  return !(((x<<16)>>16) ^ x);
}
/* 
 * thirdBits - return word with every third bit (starting from the LSB) set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int thirdBits(void) {
    int x, y, z;
    x = 0x49;
    x = (x<<9);
    y = x + 0x49;
    z = (y<<18);
    return (y+z);
}
/* 
 * anyEvenBit - return 1 if any even-numbered bit in word set to 1
 *   Examples anyEvenBit(0xA) = 0, anyEvenBit(0xE) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int anyEvenBit(int x) {
    int y, z1, z2, z3, z4;
    y = 0x55;
    z1 = (x & y);
    x = (x>>8);
    z2 = (x & y);
    x = (x>>8);
    z3 = (x & y);
    x = (x>>8);
    z4 = (x & y);
    return !!(z1 | z2 | z3 | z4);
}
/* 
 * copyLSB - set all bits of result to least significant bit of x
 *   Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int copyLSB(int x) {
  return ((x<<31)>>31);
}
/* 
 * implication - return x -> y in propositional logic - 0 for false, 1
 * for true
 *   Example: implication(1,1) = 1
 *            implication(1,0) = 0
 *   Legal ops: ! ~ ^ |
 *   Max ops: 5
 *   Rating: 2
 */
int implication(int x, int y) {
    return ((!x) | (!!y));
}
/* 
 * bitMask - Generate a mask consisting of all 1's 
 *   lowbit and highbit
 *   Examples: bitMask(5,3) = 0x38
 *   Assume 0 <= lowbit <= 31, and 0 <= highbit <= 31
 *   If lowbit > highbit, then mask should be all 0's
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int bitMask(int highbit, int lowbit) {
    int x, y, z;
    x = (0x1 << 31);
    z = (~highbit)+1;
    x = (x >> (31+z));
    x = ~x;
    x = (x << 1);
    x = x + 1;
    
    y = (0x1 << 31);
    z = (~lowbit)+1;
    y = (y >> (31+z));
    
    return (x & y);
}
/*
 * ezThreeFourths - multiplies by 3/4 rounding toward 0,
 *   Should exactly duplicate effect of C expression (x*3/4),
 *   including overflow behavior.
 *   Examples: ezThreeFourths(11) = 8
 *             ezThreeFourths(-9) = -6
 *             ezThreeFourths(1073741824) = -268435456 (overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 3
 */
int ezThreeFourths(int x) {
    int sign;
    x = (x+x+x);
    sign = x >> 31;
    return ((x + (0x3&sign)) >> 2);
}
/*
 * satMul3 - multiplies by 3, saturating to Tmin or Tmax if overflow
 *  Examples: satMul3(0x10000000) = 0x30000000
 *            satMul3(0x30000000) = 0x7FFFFFFF (Saturate to TMax)
 *            satMul3(0x70000000) = 0x7FFFFFFF (Saturate to TMax)
 *            satMul3(0xD0000000) = 0x80000000 (Saturate to TMin)
 *            satMul3(0xA0000000) = 0x80000000 (Saturate to TMin)
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 3
 */
int satMul3(int x) {
    int y, xSign, midSign, ySign, min, max, sat = 0;
    y = (x<<1);
    
    xSign = (x>>31);
    midSign = (y >> 31);
    y = y + x;
    ySign = (y >> 31);
    min = (1 << 31);
    max = ~min;

    sat = (xSign ^ midSign)  | (midSign ^ ySign);

    x = (y & ~sat) | (sat & ((xSign & min) | (~xSign & max)));
    return x;
}
/*
 * bitParity - returns 1 if x contains an odd number of 0's
 *   Examples: bitParity(5) = 0, bitParity(7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int bitParity(int x) {
    int p16, p8, p4, p2, p = 0;
    p16 = x ^ (x>>16);
    p8 = p16 ^ (p16 >> 8);
    p4 = p8 ^ (p8 >> 4);
    p2 = p4 ^ (p4 >> 2);
    p = p2 ^ (p2 >> 1);
    return (p&0x1);
}
/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x) {
    int ilog2 = 0;
    ilog2 = (!!(x >> 16)) << 4;
    ilog2 = ilog2 + ((!!(x >> (ilog2 + 8))) << 3);
    ilog2 = ilog2 + ((!!(x >> (ilog2 + 4))) << 2);
    ilog2 = ilog2 + ((!!(x >> (ilog2 + 2))) << 1);
    ilog2 = ilog2 + (!!(x >> (ilog2 + 1)));
    return ilog2;
}
/*
 * trueThreeFourths - multiplies by 3/4 rounding toward 0,
 *   avoiding errors due to overflow
 *   Examples: trueThreeFourths(11) = 8
 *             trueThreeFourths(-9) = -6
 *             trueThreeFourths(1073741824) = 805306368 (no overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int trueThreeFourths(int x)
{
    int r, s;
    s = (x>>31);
    r = (x&0x3);
    x = (x>>2);
    x = x+(x<<1);
    x = x+((r+(r<<1) + (s&0x3)) >> 2);
    return x;
}
/*
 * Extra credit
 */
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
    int sign, mask, test1, test2;
    
    test1 = 0x7f800000;
    test2 = 0x7fffff;
    
    if(((test1&uf)==test1) && ((test2&uf)!=0)){
        return uf;
    }
    
    sign = (uf>>31);
    mask = 0x80000000;
    if(sign==0){
        return (uf|mask);
    }
    else{
        mask = ~mask;
        return (uf&mask);
    }
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
    unsigned sign, e, f, mask = 0;
    mask = (1<<31);
    sign = x&mask;
    e = 158;
    
    if(x==mask){
        return (mask|e<<23);
    }
    if(!x){
        return 0;
    }
    if(sign){
        x = ~x+1;
    }
    while(!(x&mask)){
        x = x<<1;
        e--;
    }
    
    f = (x&(~mask)) >> 8;
    if(x&0x80 && ((x&0x7f)>0 || (f&1))){
        f++;
    }
    
    return (sign+(e<<23)+f);
}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
    int sign, e, f = 0;
    if((0x7f800000&uf) == 0x7f800000){
        if((uf&0x7fffff)>0){
            return uf;
        }
        else{
            return uf;
        }
    }
    
    sign = (uf&0x80000000);
    e = ((uf >> 23)&0xff);
    f = (uf&0x7fffff);
    
    if(e==0){
        f = (f<<1);
        return (sign + f);
    }
    else if(e==0xfe){
        e = e+1;
        f = 0;
        return (sign + (e<<23));
    }
    else{
        e = e + 1;
        return (sign + (e<<23) + f);
    }
}