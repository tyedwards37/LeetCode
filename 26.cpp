/* LeetCode Day 24: String Compression (443) (Medium) 26/75 
 * by Tyler Edwards | November 17th, 2023 
 * Desc: Given an array of characters chars, compress it using the following algorithm: 
 * Begin with an empty string s. For each group of consecutive repeating characters in chars:
 * If the group's length is 1, append the character to s.
 * Otherwise, append the character followed by the group's length.
 * The compressed string s should not be returned separately, but instead, be stored in the input character array chars.
 *  Note that group lengths that are 10 or longer will be split into multiple characters in chars.
 * After you are done modifying the input array, return the new length of the array. */

class Solution {
public:
    int compress(vector<char>& chars) 
    {
      int i = 0;
      for (int j = 1, count = 1; j <= chars.size(); j++, count++)
      {
          if (j == chars.size() || chars[j] != chars[j - 1])
          {
              chars[i++] = chars[j - 1];
              if (count >= 2)
              {
                  for (char amount : to_string(count))
                  {
                      chars[i++] = amount;
                  }
              }
              count  = 0;
          }
      }  
      
      return i;
    }
};