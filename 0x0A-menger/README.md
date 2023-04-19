# 0x0A. Menger Sponge

A 2D illustration of the Menger sponge

## Construction instructions
1st Begin with a cube.

2nd Divide every face of the cube into nine squares, like Rubik's Cube.
This sub-divides the cube into 27 smaller cubes.

3rd Remove the smaller cube in the middle of each face, and remove the smaller
cube in the center of the more giant cube, leaving 20 smaller cubes.
This is a level-1 Menger sponge (resembling a void cube).

4th Repeat steps two and three for each of the remaining smaller cubes, and
continue to iterate ad infinitum.

## Our implementation

We will only draw a 2D version of the Menger sponge

A level N sponge is a 3x3 square of level N-1 sponges, except for the center one, which is left empty
A level 0 sponge is represented by the # character
Examples:
A level 0 sponge is a simple 1x1 square
A level 1 sponge is a 3x3 square of level 0 sponges, except for the center one, which is left empty
A level 2 sponge is a 3x3 square of level 1 sponges, except for the center one, which is left empty
