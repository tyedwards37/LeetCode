/* Daily Question: 3043. Find the Length of the Longest Common Prefix
 * by Tyler Edwards | September 23rd, 2024 
 * Code Credit: kreakEmp
 * You are given two arrays with positive integers arr1 and arr2.
 * A prefix of a positive integer is an integer formed by one or more of its digits, starting from its leftmost digit. For example, 123 is a prefix of the integer 12345, while 234 is not.
 * A common prefix of two integers a and b is an integer c, such that c is a prefix of both a and b. 
 * For example, 5655359 and 56554 have a common prefix 565 while 1223 and 43456 do not have a common prefix.
 * You need to find the length of the longest common prefix between all pairs of integers (x, y) such that x belongs to arr1 and y belongs to arr2.
 * Return the length of the longest common prefix among all pairs. If no common prefix exists among them, return 0. */

class Solution {
public:
    class Node{
        public:
            Node* digits[10];   
    };
    void add(Node* head, int num){
        string t = to_string(num);
        Node* ptr = head;
        for(auto c: t){
            if(!ptr->digits[c - '0']) ptr->digits[c - '0'] = new Node();
            ptr = ptr->digits[c-'0'];
        }
    }
    int check(Node* head, int num){
        Node* ptr = head;
        string t = to_string(num);
        int len = 0;
        for(auto c: t){
            if(ptr->digits[c - '0']) len++;
            else break;
            ptr = ptr->digits[c-'0'];
        }
        return len;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int ans = 0;
        Node* head = new Node();
        for(auto num: arr1) add(head, num);
        for(auto num: arr2) ans = max(ans, check(head, num));
        return ans;
    }
};