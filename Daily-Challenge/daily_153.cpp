/* Daily Question: 1137. N-th Tribonacci Number
 * by Tyler Edwards | April 23rd, 2024  
 * The Tribonacci sequence Tn is defined as follows: 
 * T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.
 * When you select a node x as the root, the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).
 * Given n, return the value of Tn. */

class Solution {
public:
    int tribonacci(int n) {
        if (n < 2) { // checks if the base values can be used
            return n; // returns the given values for 0 and 1 
        }

        int a = 0, b = 1, c = 1, d; // intializes the four variables 
        while(n-- > 2) { // loops while the n value is greater than 2 while decrementing every loop to find the nth value
            d = a + b + c; // gets the next value in the sequence given teh current values
            a = b; // no longer need to rememeber the current a value so set it equal to the current b 
            b = c; // since the current b value is stored in a set it equal to c 
            c = d; // since the current c value is stored in a set it equal to d
        }

        return c; // return c, which by the end of the loop is the Tn value
    }
};