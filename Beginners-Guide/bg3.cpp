/* LeetCode Beginner's Guide: 412. Fizz Buzz (3/6)
 * by Tyler Edwards | January 14th, 2024 
 * Given an integer n, return a string array answer (1-indexed) where:
 * - answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
 * - answer[i] == "Fizz" if i is divisible by 3.
 * - answer[i] == "Buzz" if i is divisible by 5.
 * - answer[i] == i (as a string) if none of the above conditions are true. */

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> answer(n);

        for (int i = 1; i < n + 1; i++) {
            if (i % 3 == 0 && i % 5 == 0) {
                answer[i - 1] = "FizzBuzz";
            }
            
            else if (i % 3 == 0) {
                answer[i - 1] = "Fizz";
            }

            else if (i % 5 == 0) {
                answer[i - 1] = "Buzz";
            }

            else {
                answer[i - 1] = to_string(i);
            }
        }
        
        return answer;
    }
};