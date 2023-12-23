/* LeetCode Day 53: 2300. Successful Pairs of Spells and Potions (Medium) 57/75 
 * Tyler Edwards | December 22nd, 2023
 * Code Credit: Vikas-Pathak-123
 * You are given two positive integer arrays spells and potions, of length n and m respectively, where spells[i] represents the strength of the ith spell and potions[j] represents the strength of the jth potion.
 * You are also given an integer success. A spell and potion pair is considered successful if the product of their strengths is at least success.
 * Return an integer array pairs of length n where pairs[i] is the number of potions that will form a successful pair with the ith spell. */

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) 
    {
        int n = spells.size();
        int m = potions.size();

        vector<int> pairs(n, 0);
        sort(potions.begin(), potions.end());

        for (int i = 0; i < n; i++) 
        {
            int spell = spells[i];
            int left = 0;
            int right = m - 1;

            while (left <= right) 
            {
                int mid = left + (right - left) / 2;
                long long product = (long long)spell * (long long)potions[mid];
                
                if (product >= success) 
                {
                    right = mid - 1;
                } 
                
                else 
                {
                    left = mid + 1;
                }
            }
            pairs[i] = m - left;
        }
        return pairs;
    }
};