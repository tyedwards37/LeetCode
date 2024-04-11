/* Daily Question: 402. Remove K Digits
 * by Tyler Edwards | April 10th, 2024 
 * Code Credit: KnockCat
 * Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num. */

class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.length() <= k) { // check if the length of the string is shorter than the amount of digits we are told to remove
            return "0"; // returns 0 if you have to remove more digits than there are in the string
        }
        
        if(k == 0) { // checks if none need to be removed 
            return num; // returns the base string
        }
        
        string res = ""; // intializes an empty string. to record the result
        stack <char> s; // intailizes a stack of characters
        
        s.push(num[0]); // pushes the first character from the string into the stack
        
        for(int i = 1; i < num.length(); ++i) { // loops for the length of the string, starting from index 1
            while(k > 0 && !s.empty() && num[i] < s.top()) { // loops while the amount of digits to remove is greater than 0 still, the stack isn't empty, and the current index i is less than the top value string
                --k; // decrements the amount of digits to remove
                s.pop(); // removes the top value of the stack
            }
            
            s.push(num[i]); // push the current index character in the string onto the stack
            
            if(s.size() == 1 && num[i] == '0') { // check if the size of the stack is one and if the number at the current index is a zero
                s.pop(); // pops the zero at that index
            }
        }
        
        while(k && !s.empty()) { // loops while k is still a value and the stack isn't empty
            --k; // decrements the number of digits to remove
            s.pop(); // pops a character off the stack
        }
        
        while(!s.empty()) { // loops while the stack isn't empty
            res.push_back(s.top()); // pushing the character on top of the stack to string
            s.pop(); // pop the top element of the stack
        }
        
        reverse(res.begin(),res.end()); // reverse the string 
        
        if(res.length() == 0) { // check if the length of the result string is zero
            return "0"; // return a zero 
        }
        
        return res;  // return the result string
    }
};