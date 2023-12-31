/* LeetCode Day 2: Greatest Common Divisor of Strings (Easy) 2/75 
 * by Tyler Edwards | October 25th, 2023
 * Desc: For two strings s and t, we say "t divides s" if and only if s = t + ... + t (i.e., t is concatenated with itself one or more times)
 * Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2. */
 
 
class Solution {
public:
    #include <string>
    
    string gcdOfStrings(string str1, string str2) 
    {
        string x = "";
        if (str1 + str2 == str2 + str1)
        {
            int gcdLength = gcd(str1.length(), str2.length());
            x = str1.substr(0, gcdLength);
        }

        return x;
    }
};
