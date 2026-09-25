# Replace with your unique project name

## Description

**version 1.0**
the program asks what kind of colorblindness you have, and picks colors that are hard to see with that color blindness and measures the level of difficulty the color will be to see dependent on the 
type of colorblindness you have


## Developer

Diego Schopp

## Example

To run the program, give the following commands:

```
g++ --std=c++11 *.cpp -o cvp
./cvp
```
g++ main.cpp is to compile
./a.out to start
Here is an example of the program running:

```

What type of color blindness would you like to test?
1. Protanopia
2. Deuteranopia
3. Tritanopia
Enter choice: 1

You selected protanopia
How many color combinations would you like to test? 1

Combination #1
Enter the first color: red
Enter the second color: blue

red and blue may be easier to differentiate for someone with protanopia
Accessibility rating: MODERATE

Finished evaluating the color palette.```