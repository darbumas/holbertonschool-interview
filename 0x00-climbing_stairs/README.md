# Climbing Stairs

*Prompt:* You are climbing a staircase. It takes `n` steps to reach the top.
Each time you can either climb 1 or 2 steps. How many distinct ways can you
climb to the top?

## Dynamic Programming Solution

1. Create a memoization array to store the number of distinct ways to climb to
   each step. Initialize it with 0s.
2. Base cases:
   - If the number of steps is 1, there is only 1 distinct way to climb to the
     top (by taking 1 step).
   - If the number of steps is 2, there are 2 distinct ways to reach the  top
     (by taking 2 steps or 1 step twice).
3. For each step from `3` to `n`, calculate the number of distinct ways to reach
   that step by summing up the number of distinct ways to reach the previous two
   steps.
4. Return the number of distinct ways to reach the top, which is stored in the
   memoization array at index `n`.

### Pseudocode
```
function climbStairs(n):
  if n == 1:
    return 1
  if n == 2:
    return 2

  memo = [0] * (n + 1)
  memo[1] = 1
  memo[2] = 2

  for i from 3 to n:
    memo[i] = memo[i - 1] + memo[i - 2]

  return memo[n]
```
*Time Complexity:* _O(n)_ - We iterate from 3 to n once to calculate the number
of distinct ways to reach each step.

*Space Complexity:* _O(n)_ - We create a memoization array of size n + 1.

## Recursive Approach

1. Base case:
   If the number of steps is 1 (or 0) there is only 1 distinct way to reach the
   top (by either taking 1 steps or not taking any steps).
2. Otherwise, recursively calculate the number of distinct ways to reach the top
   by considering two possibilities:
   - Take 1 step and recursively solve for the remaining steps (n - 1).
   - Take 2 steps and recursively solve for the remaining steps (n - 2).
3. Return the sum of the results from the above two recursive calls.

### Pseudocode
```
function climbStair(n):
  if n == 0 or n == 1:
    return 1

  return climbStair(n - 1) + climbStair(n - 2)
```
*Time Complexity:* _O(2^n)_ - We make two recursive calls for each step; hence
this is an exponential time algorithm.

*Space Complexity:* _O(n)_ - The maximum depth of the recursion tree is n.

## Recursive with Memoization Approach

1. Create a memoization array to store the results of the subproblems.
   Initialize it with -1 to indicate that the result has not been computed yet.
2. Define a helper function that takes the number of steps and the memoization
   array as parameters.
3. Base cases:
   - If the number of steps is 1 (or 0) there is only 1 distinct way to
     reach the top.
4. Check if the result for the current number of steps is already memoized. If
   so, return the memoized result.
5. Otherwise, recursively calculate the number of distinct ways to reach the top
   by considering the two possibilities mentioned above in the recursive
   approach.
6. Memoize the result and return it.

### Pseudocode
```
function climbStairs(n):
  memo = [-1] * (n + 1)
  return climbStairsHelper(n, memo)
  
function climbStairsHelper(n, memo):
  if n == 0 or == 1:
    return 1
  
  if memo[n] != -1:
    return memo[n]
  
  memo[n] = climbStairsHelper(n - 1, memo) + climbStairsHelper(n - 2, memo)
    return memo[n]
```
*Time Complexity:* _O(n)_ - By memoizing the results, we avoid redundant
computations and improve the time complexity from exponential to linear.

*Space Complexity:* _O(n)_ - We create a memoization array of size n + 1. The
maximum depth of the recursion tree is n, hence the space complexity is O(n).

## Optimized Approach (Fibonacci sequence)

1. Base cases:
   - If the number of steps is 0 or 1, return 1.
2. Initialize two variables to store the number of distinct ways to reach the
   top for the previous two steps:
   	`prev1 = 1` and `prev2 = 1` .
3. Iterate from 3 to n, updating `prev1` and `prev2` at each step as follows:
	* `temp = prev1 + prev2` Temporary variable to store the sum of the
	  previous two steps.
	* `prev2 = prev1` Update the number of distinct ways to reach the top
	  for the previous two steps.
	* `prev1 = temp` Update the number of distinct ways to reach the top
	  for the previous step.
4. Return `prev1` which stores the number of distinct ways to reach the top.

### Pseudocode
```
function climbStairs(n):
  if n == 0 or n == 1:
    return 1
  
  prev1 = 1
  prev2 = 1
  
  for i from 3 to n:
    temp = prev1 + prev2
    prev2 = prev1
    prev1 = temp
    
  return prev1
```

The optimized approach achieves the same result as the dynamic programming
approach with memoization but without the need for additional space or recursive
calls. It is a more efficient and straightforward solution.

## How to run

```
user@computer:/0x00-climbing_stairs$ gcc -Wall -Werror -Wextra -pedantic climbStairs.c -o climbStairs
user@computer:/0x00-climbing_stairs$ ./climbStairs 15
Number of distinct ways to climb 15 stairs is [987]
user@computer:/0x00-climbing_stairs$
```


