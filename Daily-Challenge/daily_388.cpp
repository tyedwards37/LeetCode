/* Daily Question: 2182. Construct String With Repeat Limit
 * by Tyler Edwards | December 16th, 2024  
 * Code Credit: Venkata Sai Tanish Jonnadula
 * You are given a string s and an integer repeatLimit. 
 * Construct a new string repeatLimitedString using the characters of s such that no letter appears more than repeatLimit times in a row. You do not have to use all characters from s.
 * Return the lexicographically largest repeatLimitedString possible.
 * A string a is lexicographically larger than a string b if in the first position where a and b differ, string a has a letter that appears later in the alphabet than the corresponding letter in b. 
 * If the first min(a.length, b.length) characters do not differ, then the longer string is the lexicographically larger one. */

class Solution {
public:
    string repeatLimitedString(string s, int k) { // k is the repeatLimit
        int n = s.length();
        unordered_map<char,int> m;
        for(int i=0;i<n;i++) m[s[i]]++;
        priority_queue<pair<char,int>> pq;
        for(auto i: m){
            pq.push({i.first,i.second}); // pushing the characters with their frequencies.
        }
        
        string ans = "";
        while(!pq.empty()){
            char c1 = pq.top().first;
            int n1 = pq.top().second;
            pq.pop();
                
            int len = min(k,n1); // Adding characters upto minimum of repeatLimit and present character count.
            for(int i=0;i<len;i++){ // adding the highest priority element to the ans.
                ans += c1;
            }
            
            char c2;
            int n2=0;
            if(n1-len>0){ // If the cnt of present character is more than the limit.
                if(!pq.empty()){ //Getting the next priority character.
                    c2 = pq.top().first;
                    n2 = pq.top().second;
                    pq.pop();
                }
                else{
                    return ans; // if there is no another letter to add, we just return ans.
                }
                ans += c2; // Adding next priority character to ans.
                
                // If the elements are left out, pushing them back into priority queue for next use.
                pq.push({c1,n1-len});
                if(n2-1>0) pq.push({c2,n2-1}); 
            }
        }
        return ans;
    }
};