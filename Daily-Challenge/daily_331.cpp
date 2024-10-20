/* Daily Question: 1106. Parsing A Boolean Expression
 * by Tyler Edwards | October 19th, 2024 
 * Code Credit: binayKr
 * A boolean expression is an expression that evaluates to either true or false. It can be in one of the following shapes:
 * - 't' that evaluates to true.
 * - 'f' that evaluates to false.
 * - '!(subExpr)' that evaluates to the logical NOT of the inner expression subExpr.
 * - '&(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical AND of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.
 * - '|(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical OR of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.
 * Given a string expression that represents a boolean expression, return the evaluation of that expression.
 * It is guaranteed that the given expression is valid and follows the given rules. */

class Solution {
private:
    bool parse_or (vector<int> &res)
    {
        int mask = res[0];
        for(int i=1; i<res.size(); i++)
        {
            mask |= res[i];
        }
        return mask;
    }
    
    bool parse_and (vector<int> &res)
    {
        int mask = res[0];
        for(int i=1; i<res.size(); i++)
        {
            mask &= res[i];
        }
        return mask;
    }
    
public:
    bool parseBoolExpr(string s) {
        int n = s.size();
        stack<int> st;
        for(int i =0; i<n; i++)
        {
            if(s[i] == ',') continue;
            if(s[i]==')')
            {
                vector<int> res;
                while(st.top()!='&' && st.top()!='|' && st.top()!='!')
                {
                    char c = st.top();
                    st.pop();
                    if(c=='t') res.push_back(1);
                    if(c=='f') res.push_back(0);
                }
                char c = st.top();
                st.pop();
                if(c=='&')
                {
                    if(parse_and(res)) st.push('t');
                    else st.push('f');
                }
                else if(c=='|') 
                {
                    if(parse_or(res)) st.push('t');
                    else st.push('f');
                }
                else if(c=='!')
                {
                    if(res[0] == 0) st.push('t'); 
                    else st.push('f');
                }
            }
            else st.push(s[i]);
        }
        return (st.top()=='t');
    }
};