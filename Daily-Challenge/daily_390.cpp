/* Daily Question: 769. Max Chunks To Make Sorted
 * by Tyler Edwards | December 18th, 2024  
 * Code Credit: keval joshi
 * You are given an integer array arr of length n that represents a permutation of the integers in the range [0, n - 1].
 * We split arr into some number of chunks (i.e., partitions), and individually sort each chunk. After concatenating them, the result should equal the sorted array.
 * Return the largest number of chunks we can make to sort the array. */

class Solution {
public:
    int maxChunksToSorted(vector<int>& v) 
    {
        //sum1 is sum of 0.........i
        //co is sum of v[0],v[1].......v[i]
        int i,co=0,sum1=0,ans=0;
        for(i=0;i<v.size();i++)
        {
            sum1+=i;
            co+=v[i];
            if(sum1==co)
                ans++;
        }
        return ans;
    }
};