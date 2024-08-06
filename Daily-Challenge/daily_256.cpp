/* Daily Question: 3016. Minimum Number of Pushes to Type Word II
 * by Tyler Edwards | August 5th, 2024 
 * Code Credit: anwendeng
 * You are given a string word containing lowercase English letters.
 * Telephone keypads have keys mapped with distinct collections of lowercase English letters, which can be used to form words by pushing them. 
 * For example, the key 2 is mapped with ["a","b","c"], we need to push the key one time to type "a", two times to type "b", and three times to type "c".
 * It is allowed to remap the keys numbered 2 to 9 to distinct collections of letters. The keys can be remapped to any amount of letters, but each letter must be mapped to exactly one key. 
 * You need to find the minimum number of times the keys will be pushed to type the string word. 
 * Return the minimum number of pushes needed to type word after remapping the keys. 
 * An example mapping of letters to keys on a telephone keypad is given below. Note that 1, *, #, and 0 do not map to any letters. */

class Solution {
public:
    static  void print(auto& c){
        for(int x: c) cout<<x<<", "; 
        cout<<endl;
    }
    static int minimumPushes(string& word) {
        int freq[26]={0};
        for(char c: word) 
            freq[c-'a']++;
        nth_element(freq, freq+7, end(freq), greater<int>());
        nth_element(freq+8, freq+15, end(freq), greater<int>());
        nth_element(freq+16, freq+23, end(freq), greater<int>());

        int i=0; 
        return accumulate(freq, freq+26, 0,  [&i](int sum, int f){
            return sum+=(f*(i++/8+1));
        });
    }
};