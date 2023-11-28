/* LeetCode Day 34: Decode String (294) (Medium) 36/75 
 * by Tyler Edwards | November 27th, 2023 
 * Given an encoded string, return its decoded string.
 * The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.
 * You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. 
 * Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4]. 
 * The test cases are generated so that the length of the output will never exceed 105. */

class Solution {
public:
    string decodeString(string s) 
    {
        stack<char> temp;
        int n = s.size();
        string answer = "";

        for (int i = 0; i < n; i++)
        {
            if(s[i] != ']')
            {
                temp.push(s[i]);
            }

            else
            {
                string curr = "";

                while (temp.top() != '[')
                {
                    curr = temp.top() + curr;
                    temp.pop();
                }

                temp.pop();
                string number = "";

                while (!temp.empty() && isdigit(temp.top()))
                {
                    number = temp.top() + number;
                    temp.pop();
                }

                int time = stoi(number);

                for (int j = 0; j < time; j++)
                {
                    for (char c : curr)
                    {
                        temp.push(c);
                    }
                }
            }
        }

        while (!temp.empty())
        {
            answer = temp.top() + answer;
            temp.pop();
        }

        return answer;
    }
};
