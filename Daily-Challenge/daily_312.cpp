/* Daily Question: 1497. Check If Array Pairs Are Divisible by k
 * by Tyler Edwards | September 30th, 2024 
 * Code Credit: jinTaeJin
 * Given an array of integers arr of even length n and an integer k.
 * We want to divide the array into exactly n / 2 pairs such that the sum of each pair is divisible by k.
 * Return true If you can find a way to do that or false otherwise. */

//(x%k + k)%k is done to counter negative integers in the array.

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        if(arr.size()&1) return false;
        unordered_map<int,int>m;
        for(auto x:arr) m[(x%k + k)%k]++;          //store the count of remainders in a map.
        for(auto x:arr)
        {
            int rem=(x%k + k)%k;
            if(rem==0)                         //if the remainder for an element is 0 then the count of numbers that give this remainder must be even.
            { 
                if(m[rem] & 1) return false;            //if count of numbers that give this remainder is odd all pairs can't be made hence return false.
            }         
            else if(m[rem] != m[k - rem]) return false;    //if the remainder rem and k-rem do not have the same count then pairs can not be made 
        }
        return true;
    }
};