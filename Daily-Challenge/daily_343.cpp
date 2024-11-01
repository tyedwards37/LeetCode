/* Daily Question: 1957. Delete Characters to Make Fancy String
 * by Tyler Edwards | October 31st, 2024 (Happy Halloween!)
 * Code Credit: tojuna
 * A fancy string is a string where no three consecutive characters are equal.
 * Given a string s, delete the minimum possible number of characters from s to make it fancy.
 * Return the final string after the deletion. It can be shown that the answer will always be unique. */

class Solution {
public:
    string makeFancyString(string s) {
        int cnt=1;
        string ans="";    ans.push_back(s[0]);
		
        for(int i=1;i<s.length();++i) {
            cnt=s[i]==s[i-1]? cnt+1:1;

            if(cnt<3) {
                ans.push_back(s[i]);
            }
        }
        return ans;

    }
};