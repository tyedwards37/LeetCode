/* Daily Question: 2264. Largest 3-Same-Digit Number in String
 * by Tyler Edwards | December 3rd, 2023 
 * You are given a string num representing a large integer. An integer is good if it meets the following conditions:
 * - It is a substring of num with length 3.
 * - It consists of only one unique digit.
 *  Return the maximum good integer as a string or an empty string "" if no such integer exists. */

class Solution {
public:
    string largestGoodInteger(string num) 
    {
        int answer = -1;

        for (int i = 0; i + 2 < num.length(); i++)
        {
            if (num[i] == num[i + 1] && num[i] == num[i + 2])
            {
                answer = max(answer, num[i] - '0');
            }
        }

        return (answer == -1) ? "" : string(3, '0' + answer);
    }
};
