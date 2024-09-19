/* Daily Question: 241. Different Ways to Add Parentheses
 * by Tyler Edwards | September 17th, 2024 
 * Code Credit: vishal2720
 * Given a string expression of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. 
 * You may return the answer in any order.
 * The test cases are generated such that the output values fit in a 32-bit integer and the number of different results does not exceed 104. */

class Solution {
public:
    // function to get the result of the operation
    int perform(int x, int y, char op) {
        if(op == '+') return x + y;
        if(op == '-') return x - y;
        if(op == '*') return x * y;
        return 0;
    }
    
    vector<int> diffWaysToCompute(string exp) {
        
        vector<int> results;
        bool isNumber = 1;
    
        for(int i = 0; i < exp.length(); i++) {
            // check if current character is an operator
            if(!isdigit(exp[i])) {
                
                // if current character is not a digit then
                // exp is not purely a number
                isNumber = 0;
                
                // list of first operands
                vector<int> left = diffWaysToCompute(exp.substr(0, i));
                
                // list of second operands
                vector<int> right = diffWaysToCompute(exp.substr(i + 1));
                
                // performing operations
                for(int x : left) {
                    for(int y : right) {
                        int val = perform(x, y, exp[i]);
                        results.push_back(val);
                    }
                }
                
            }
        }
        
        if(isNumber == 1) results.push_back(stoi(exp));
        return results;
    }
};
