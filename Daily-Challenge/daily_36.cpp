/* Daily Question: 1758. Minimum Changes To Make Alternating Binary String
 * by Tyler Edwards | December 23rd, 2023 
 * Code Credit: lancertech6
 * You are given a string s consisting only of the characters '0' and '1'. In one operation, you can change any '0' to '1' or vice versa.
 * The string is called alternating if no two adjacent characters are equal. For example, the string "010" is alternating, while the string "0100" is not.
 * Return the minimum number of operations needed to make s alternating. */

class Solution {
public:
    int minOperations(string s) 
    {
        int answer = 0, n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (s[i] - '0' != i % 2)
            {
                answer++;
            }
        }

        return min(answer, n - answer);
    }
};