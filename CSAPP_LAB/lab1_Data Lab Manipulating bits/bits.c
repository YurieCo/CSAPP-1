/*
 * CS:APP Data Lab
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

#include "btest.h"
#include <limits.h>

/*
 * Instructions to Students:
 *
 * STEP 1: Fill in the following struct with your identifying info.
 */
team_struct team =
{
   /* Team name: Replace with either:
      Your login ID if working as a one person team
      or, ID1+ID2 where ID1 is the login ID of the first team member
      and ID2 is the login ID of the second team member */
    "Sore Knees",
   /* Student name 1: Replace with the full name of first team member */
   "Spencer Smith",
   /* Login ID 1: Replace with the login ID of first team member */
   "sls54",

   /* The following should only be changed if there are two team members */
   /* Student name 2: Full name of the second team member */
   "Roderic W. Lewis Jr.",
   /* Login ID 2: Login ID of the second team member */
   "ric"
};

#if 0
/*
 * STEP 2: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

CODING RULES:

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


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function.
     The max operator count is checked by dlc. Note that '=' is not
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.
#endif

/*
 * STEP 3: Modify the following functions according the coding rules.
 *
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the btest test harness to check that your solutions produce
 *      the correct answers. Watch out for corner cases around Tmin and Tmax.
 */



/*
 * bitNor - ~(x|y) using only ~ and &
 *   Example: bitNor(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitNor(int x, int y) {

  return ((~x) & (~y));

}






/*
 * bitXor - x^y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 2
 */
int bitXor(int x, int y) {


  return (~((~x) & (~y)) & ~(x & y));

}






/*
 * isNotEqual - return 0 if x == y, and 1 otherwise
 *   Examples: isNotEqual(5,5) = 0, isNotEqual(4,5) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNotEqual(int x, int y) {

  return !!((~x+1) + y);

}






/*
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {


  return (x >> (n << 3)) & 0xff;
}






/*
 * copyLSB - set all bits of result to least significant bit of x
 *   Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int copyLSB(int x) {


  return ((x << 31) >> 31);

}






/*
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 1 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int logicalShift(int x, int n) {

  int a;
  int b;
  int c;

  a = (x >> 1);      /*we can safely shift one, since we know n >= 1*/
  b = ~(0x1 << 31);  /*create a mask to set the first bit to zero*/
  c = n + (~1 + 1);  /*set c = (n - 1) */

  return ((a & b) >> c);

}






/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {

  int m4bit = 0;
  int m4add = 0;
  int m8add = 0;
  int m16add = 0;
  int total = 0;

  //Make a mask that has 1 every 4 bits.
  m4bit = (17<<8) + 17;
  m4bit = (m4bit<<16) + m4bit;

  //Add the bits in 4 bit segments by shifting and adding.
  total = x & m4bit;
  total = total + ((x>>1) & m4bit);
  total = total + ((x>>2) & m4bit);
  total = total + ((x>>3) & m4bit);

  //Make a mask that passes 4 bit segments alternatly.
  m4add = (15<<8) + 15;
  m4add = (m4add<<16) + m4add;

  //Add the 4 bit segments into 8 bit segments.
  total = (total & m4add) + ((total>>4) & m4add);

  //Make a mask that passes 8 bit segments alternatly.
  m8add = (255<<16) + 255;

  //Add the 8 bit segments into 16 bit segments.
  total = (total & m8add) + ((total>>8) & m8add);

  //Mask that passes the 16 least significant bits.
  m16add = (255<<8) + 255;

  //Add the 16 bit totals into the final total.
  total = (total & m16add) + ((total>>16) & m16add);

  return total;
}






/*
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int bang(int x) {

  int a;
  int b;
  int c;

  a = ~x;
  /*and all the bits together by halving then anding.
    If there's a zero in the ~x, then x was non-zero*/

  b = (a >> 16);
  c = a & b;

  a = (c >> 8);
  b = a & c;

  a = (b >> 4);
  c = a & b;

  a = (c >> 2);
  b = a & c;

  a = (b >> 1);
  c = a & b;

  a = 0x1 & c;

  return (a);
}







/*
 * leastBitPos - return a mask that marks the position of the
 *               least significant 1 bit. If x == 0, return 0
 *   Example: leastBitPos(96) = 0x20
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 4
 */
int leastBitPos(int x) {

  return (x & (~x + 1));

}







/*
 * TMax - return maximum two's complement integer
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void) {

  return (~(0x1 << 31));

}






/*
 * isNonNegative - return 1 if x >= 0, return 0 otherwise
 *   Example: isNonNegative(-1) = 0.  isNonNegative(0) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 3
 */
int isNonNegative(int x) {

  return !(x >> 31);

}

/*
 * isGreater - if x > y  then return 1, else return 0
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y) {

  int sb_x;
  int sb_y;
  int sb_equal;
  int diff_yx;
  int is_non_neg;


  sb_x     = (x >> 31);
  sb_y     = (y >> 31);
  sb_equal = !(sb_x ^ sb_y);

  diff_yx  = (y + (~x + 1));

  is_non_neg = !(diff_yx >> 31);

  return !((sb_equal & is_non_neg) | !(sb_equal | sb_y));

}






/*
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {


    int sb_x;
    int neg_base;


    sb_x = (x >> 31);    /*the sign bit of x, copied through the word size*/
    neg_base = (x + (1 << n) + ~0);  /*used if x is negative*/

    return ((sb_x & neg_base) + (~sb_x & x)) >> n;
    /*if sb_x is 1, (negative) then the biased x will be used,
      otherwise the normal value of x is used for calculation*/
}






/*
 * abs - absolute value of x (except returns TMin for TMin)
 *   Example: abs(-1) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int abs(int x) {

  int sb;

  sb = x >> 31;

  return (sb & (~x + 1)) + (~sb & x);
  /*if the sb is 1 (negative) then return the negation of x
    otherwise, just return x*/
}






/*
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1,
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y) {

  int hb_mask;

  int hb_x; /*high bit (sign bit) of x*/
  int hb_y; /*high bit (sign bit) of y*/

  int a;
  int hb_a; /*high bit (sign bit) of a*/

  hb_mask = (1 << 31);  /*0x80000000*/

  a  = (~hb_mask & x) + (~hb_mask & y); /*cuts off the top bit of x and y
                                          and adds them together*/

  hb_x    = !(hb_mask & x); /*the ! is used here to move the high bit value*/
  hb_y    = !(hb_mask & y); /* to a more useful position (the LSB)*/

  hb_a    = !(hb_mask & a);

  return ~(((hb_x + hb_y + hb_a) >> 1) ^ hb_a) + 2;
  /*if the carry bit going into the MSB is the same as the carry bit going
    out of the MSB, then there's no overflow, otherwise, there is overflow*/
  }
