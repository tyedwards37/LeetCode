/* Daily Question: 2125. Number of Laser Beams in a Bank
 * by Tyler Edwards | January 2nd, 2024 
 * Code Credit: tojuna
 * You are given an integer array nums. You need to create a 2D array from nums satisfying the following conditions:
 * - The 2D array should contain only the elements of the array nums.
 * - Each row in the 2D array contains distinct integers.
 * - The number of rows in the 2D array should be minimal.
 * Return the resulting array. If there are multiple answers, return any of them. */

class Solution {
public:
    int numberOfBeams(vector<string>& bank) 
    {
        int ans = 0, prev = 0, count = 0;

        for (string s: bank)
        {
            count = 0;

            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] == '1')
                {
                    count++;
                }
            }

            if (count)
            {
                ans += prev * count;
                prev = count;
            }
        }

        return ans;
    }
};