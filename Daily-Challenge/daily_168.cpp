/* Daily Question: 3075. Maximize Happiness of Selected Children
 * by Tyler Edwards | May 8th, 2024 
 * Code Credit: ayushnemmaniwar12
 * You are given an array happiness of length n, and a positive integer k.
 * There are n children standing in a queue, where the ith child has happiness value happiness[i]. You want to select k children from these n children in k turns.
 * In each turn, when you select a child, the happiness value of all the children that have not been selected till now decreases by 1. 
 * Note that the happiness value cannot become negative and gets decremented only if it is positive.
 * Return the maximum sum of the happiness values of the selected children you can achieve by selecting k children. */

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(),happiness.end()); // sorts the happiness array 
        long long ans = 0; // creates a long long to hold the answer
        int n = happiness.size() - 1; // size of the happiness array minus 1 (the max index of the array)
        int c = 0; // intialize an integer c to 0

        while(n >= 0 && k > 0) { // loops while n is positive and k is greater than 0 
            if(happiness[n] - c >= 0) // checks if the value at index n - the current c value is positive
                ans = ans + happiness[n] - c; // add the value at index n - c to the current value of the answer value
            else // if the value is negative
                break; // breaks the loop

            c++; // increment c 
            n--; // decrement n
            k--; // decrement k
        }

        return ans; // return the answer variable
    }
};