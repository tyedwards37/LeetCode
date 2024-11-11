/* Daily Question: 2601. Prime Subtraction Operation
 * by Tyler Edwards | November 10th, 2024  
 * Code Credit: Abhinav Prajapati
 * You are given a 0-indexed integer array nums of length n.
 * You can perform the following operation as many times as you want:
 * - Pick an index i that you haven’t picked before, and pick a prime p strictly less than nums[i], then subtract p from nums[i].
 * Return true if you can make nums a strictly increasing array using the above operation and false otherwise.
 * A strictly increasing array is an array whose each element is strictly greater than its preceding element. */

class Solution {
public:
    void seive_algo(vector<bool> &v, int n){
        v[0] = v[1] = false;
        for(int i=2; i*i<n; i++){
            for(int j=2*i; j<n; j+=i){
                v[j] = false;
            }
        }
    }

    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        vector<bool> isPrime(1005, true);
        seive_algo(isPrime, 1005);

        vector<int> prime;
        for(int i=0; i<1004; i++)
            if(isPrime[i]) prime.push_back(i);
        
        int flg = 0;
        int prev = nums[n-1];
        for(int i=n-2; i>=0; i--){
            if(nums[i]<prev){prev = nums[i]; continue;}
            flg = 1;
            for(int sub=0; sub<prime.size() && prime[sub]<nums[i]; sub++){
                if(nums[i]-prime[sub]<prev){
                    prev = nums[i]-prime[sub];
                    flg = 0;
                    break;
                }
            }
            if(flg) break;

        }
        return !flg;
    }
};