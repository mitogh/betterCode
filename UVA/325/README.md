#Identifying Legal Pascal Real Constants 

Pascal requires that real constants have either a decimal point, or an exponent (starting with the letter e or E, and officially called a scale factor), or both, in addition to the usual collection of decimal digits.  If a decimal point is included it must have at least one decimal digit on each side of it. As expected, a sign (+ or -) may precede the entire number, or the exponent, or both. Exponents may not include fractional digits. Blanks may precede or follow the real constant, but they may not be embedded within it. Note that the Pascal syntax rules for real constants make no assumptions about the range of real values, and neither does this problem.

Your task in this problem is to identify legal Pascal real constants.

## Input and Output

Each line of the input data contains a candidate which you are to
classify. For each line of the input, display your finding as
illustrated in the example shown below. The input terminates with a line
that contains only an asterisk in column one.

###Sample Input

```
1.2
   1.
  1.0e-55
  e-12
    6.5E
     1e-12
  +4.1234567890E-99999
   7.6e+12.5
99
*
```

##Sample Output

```
1.2 is legal.
1. is illegal.
1.0e-55 is legal.
e-12 is illegal.
6.5E is illegal.
1e-12 is legal.
+4.1234567890E-99999 is legal.
7.6e+12.5 is illegal.
99 is illegal.
```
