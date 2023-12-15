/* LeetCode Day 11: Unique Number of Occurrences (Easy) 13/75 
 * by Tyler Edwards | November 4th, 2023 
 * Desc: Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise. */

class Solution {
public:
    #include <vector>
    bool uniqueOccurrences(vector<int>& arr) 
    {
        int i = 0;
        sort(arr.begin(), arr.end());

        vector<int> unique;

        while ( i < arr.size())
        {
            int count = 1;
            for (int j = i + 1; j < arr.size(); j++)
            {
                if (arr[i] == arr[j])
                {
                    count++;
                }
            }
            unique.push_back(count);
            i += count;
        }
        sort(unique.begin(), unique.end());

        for (int i = 0; i < unique.size()- 1; i++)
        {
            if ( unique[i] == unique[i + 1])
            {
                return false;
            }
        }

        return true;
    }
};
