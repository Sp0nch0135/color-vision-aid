# Color Vision Palette Advisor

## Description

**version 1.0**

The version 1.0 program asked the user to select a type of color blindness
and enter two color names. It then evaluated how difficult that color pair
might be to differentiate and displayed an accessibility rating.

## Developer

Diego Schopp

## Getting Started

**version 2.0 Updates**

The goal of version 2.0 is to build on the original program by using RGB
values for the color comparisons and saving the results in a file. The user
can type common names such as `red` or `blue`, and the program looks up their
RGB values. For example, blue is stored as RGB `(0, 0, 255)`.

To use the program, type `1`, `2`, or `3` to select protanopia, deuteranopia,
or tritanopia. Then enter the number of color combinations to check and type
two color names for each combination. The color list includes common colors:
red, green, blue, yellow, purple, orange, pink, brown, gray, black, and white.
It does not use technical color names or shade names such as dark red or light
blue.

The program gives each pair a poor, moderate, or good rating. The program
checks for invalid menu choices, invalid numbers, and color names that are not
in the color list.

The color list is stored in a vector. The `makeColorList` function creates the
vector, `findColor` searches it, and `rateColors` compares two RGB colors.
These functions demonstrate pass-by-value and pass-by-reference parameters as
well as different return types. The program uses `ofstream` to create
`colorvision_report.txt` and save the results after the combinations are
checked.

To compile and run the program, use:

```bash
g++ --std=c++11 main.cpp -o cvp
./cvp
```

Here is an example of the program running:

```text
RGB Color Vision Palette Advisor
Enter common color names such as blue, red, or green.

1. Protanopia
2. Deuteranopia
3. Tritanopia
Type 1, 2, or 3 for the type you would like to test: 1
How many color combinations would you like to test? 1

Combination #1
Enter the first color: red
Enter the second color: green
red is RGB(255, 0, 0).
green is RGB(0, 128, 0).
These colors may be difficult to differentiate.
Accessibility rating: POOR

A report was saved to colorvision_report.txt.
Finished evaluating the color palette.
```
