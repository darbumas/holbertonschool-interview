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
