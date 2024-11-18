/* Daily Question: 1652. Defuse the Bomb
 * by Tyler Edwards | November 17th, 2024  
 * Code Credit: Piotr Maminski
 * You have a bomb to defuse, and your time is running out! Your informer will provide you with a circular array code of length of n and a key k.
 * To decrypt the code, you must replace every number. All the numbers are replaced simultaneously.
 * - If k > 0, replace the ith number with the sum of the next k numbers.
 * - If k < 0, replace the ith number with the sum of the previous k numbers.
 * - If k == 0, replace the ith number with 0.
 * As code is circular, the next element of code[n-1] is code[0], and the previous element of code[0] is code[n-1].
 * Given the circular array code and an integer key k, return the decrypted code to defuse the bomb! */

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) 
    {
        int n=code.size();
        vector<int>res(n,0);
        
        if(k==0)
            return res;
        
		// Taking a window of k elements
		
		// First window will be from index 1 to index k
        int start=1,end=k;
        if(k<0)
        {
		   // if k is negative then the first window will be the last k elements
            k*=-1;
            start=n-k;
            end=n-1;
        }
        int sum=0;
        // maintaining first window
        for(int i=start;i<=end;i++)
            sum+=code[i];
        
        for(int i=0;i<n;i++)
        {
            res[i]=sum;
            // sliding the window 
            sum-=code[(start++)%n];
            sum+=code[(++end)%n];
        }
        
        return res;
        
    }
};