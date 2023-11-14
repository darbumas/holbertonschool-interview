# Image Smoother

An image smoother is a filter of the size `3 x 3` that can be applied to each
cell of an image by rounding down the average of the cell and the eight
surrounding cells (i.e., the average of the nine cells in the blue smoother). If
one or more cells of a cell is not present, we do not consider it in the
average.

## Sample Data

### Input Example 1

* `img = [[1,1,1],[1,0,1],[1,1,1]]`

### Output Example 1

* `[[0,0,0],[0,0,0],[0,0,0]`

### Explanation Example 1

* For the points (0,0), (0,2), (2,0), (2,2): floor(3/4) = floor(0.75) = 0
* For the points (0,1), (1,0), (1,2), (2,1): floor(5/6) = floor(0.83333333) = 0

### Input Example 2

* `img = [[100,200,100],[200,50,200],[100,200,100]]`

### Output Example 2

* [[137,141,137],[141,138,141],[137,141,137]]

### Explanation Example 2

* For the point (0,0), (0,2), (2,0), (2,2): floor((100+200+200+50)/4) =
  floor(137.5) = 137
* For the point (0,1), (1,0), (1,2), (2,1): floor((100+200+50+200+200+100)/6) =
  floor(141.666667) = 141

## Concepts

* *Matrix* - A two-dimensional array of elements
* *Image Processing* - Manipulating an image to achieve a desired output.
* *Rounding down* - Truncating the decimal part of a number to obtain the
  integer part.
* *Matrix Traversal* - Iterating through the elements of a matrix.

# Solution

## Approach

* We will traverse the input matrix and calculate the smoothed value for each cell
* Store the smoothed values in a new output matrix
* To calculate a smoothed value:
	* Initialize sum to 0
	* Initialize count to 0
	* Loop through the cell and its 8 surrounding cells
		* If the surrounding cell exists, add its value to sum and increment count
	* Calculate the average as sum/count
	* Take the floor of the average to get the smoothed value

## Pseudocode

```
initialize output matrix with same dimensions as input matrix

for each row in input matrix:
  for each col in input matrix:
  
    sum = 0
    count = 0
  
    for i in [row-1, row, row+1]:
      for j in [col-1, col, col+1]:
      
        if i,j is valid index in input matrix:
        
          sum += inputMatrix[i][j]  
          count++
            
    average = sum / count
    smoothedValue = floor(average)
      
    outputMatrix[row][col] = smoothedValue
    
return outputMatrix
```
## Time and Space Complexity

* Time: `O(rows*columns)`

### Brute force vs. Optimal Approach

* Brute force approach would be to traverse the input matrix and for each cell,
  calculate the average of its surrounding cells. This would take
  `O(rows*columns*rows*columns)` time, i.e., checks bounds each time.
  
* Optimal approach is to traverse the input matrix and for each cell, calculate 
  the average of its surrounding cells. This would take `O(rows*columns)` time,
  i.e., uses modular arithmetic to check bounds.
