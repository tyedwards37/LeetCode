/* Daily Question: 907. Sum of Subarray Minimums
 * by Tyler Edwards | January 19th, 2024 
 * Code Credit: nitink_33
 * Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. 
 * Since the answer may be large, return the answer modulo 109 + 7. */

class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        int n = A.size();
        int MOD = 1e9 + 7;
        vector<int> left(n), right(n);

        stack<int>st;
        st.push(0);
        left[0] = 1; 
        for(int i = 1; i < n; i++)
        {
            while(!st.empty() && A[i] < A[st.top()]) 
                st.pop();
            
            if(st.empty()) 
                left[i] = i + 1; 
            else 
                left[i] = i - st.top(); 
            
            st.push(i);
        }
        
        while(st.size()) 
            st.pop();
        
        st.push(n-1);
        right[n-1] = 1; 
        for(int i = n - 2; i >= 0; i--)
        {
            while(!st.empty() && A[i] <= A[st.top()]) 
                st.pop();
            
            if(st.empty()) 
                right[i] = n - i; // distance
            else 
                right[i] = st.top() - i;
            
            st.push(i);
        }

        for(int i=0; i<n; i++) 
             cout << left[i] << " : " << right[i] << endl;

        int res = 0;
        for(int i=0; i<n; i++)
        {
            long long prod = (left[i]*right[i])%MOD;
            prod = (prod*A[i])%MOD;
            res = (res + prod)%MOD;
        }
        
        return res%MOD;
    }
};