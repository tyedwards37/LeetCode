/* LeetCode Day 3: Kids With the Greaest Number of Candies (Easy) 3/75 
 * by Tyler Edwards | October 26th, 2023
 * Desc: There are n kids with candies. You are given an integer array candies, where each candies[i] represents the number of candies the ith kid has, and an integer extraCandies, denoting the number of extra candies that you have.
 * Return a boolean array result of length n, where result[i] is true if, after giving the ith kid all the extraCandies, they will have the greatest number of candies among all the kids, or false otherwise. 
 * Note that multiple kids can have the greatest number of candies. */

class Solution {
public:
    #include <vector>
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) 
    {
        vector<bool> result;
        int maxCandy = 0;
        
        for(int candy : candies)
        {
            maxCandy = max(maxCandy, candy);
        }
        
        for (int candy: candies)
        {
            if (candy + extraCandies >= maxCandy)
            {
                result.push_back(true);
            }

            else
            {
                result.push_back(false);
            }
        }

        return result;
    }
};