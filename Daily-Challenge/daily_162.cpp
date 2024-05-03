/* Daily Question: 165. Compare Version Numbers
 * by Tyler Edwards | May 2nd, 2024  
 * Code Credit: XUYAN3
 * Given two version numbers, version1 and version2, compare them.
 * Version numbers consist of one or more revisions joined by a dot '.'. Each revision consists of digits and may contain leading zeros. Every revision contains at least one character. 
 * Revisions are 0-indexed from left to right, with the leftmost revision being revision 0, the next revision being revision 1, and so on. 
 * For example 2.5.33 and 0.1 are valid version numbers. 
 * To compare version numbers, compare their revisions in left-to-right order. Revisions are compared using their integer value ignoring any leading zeros. 
 * This means that revisions 1 and 001 are considered equal. If a version number does not specify a revision at an index, then treat the revision as 0. 
 * For example, version 1.0 is less than version 1.1 because their revision 0s are the same, but their revision 1s are 0 and 1 respectively, and 0 < 1.*/

class Solution {
public:
    int compareVersion(string version1, string version2) {
    int i = 0, j = 0; // intialize two ints to 0
    int n1 = version1.size(), n2 = version2.size(); // intialize two ints to the sizes of both given strings 
    int num1 = 0, num2 = 0; // intialize two more ints to zero

    while(i<n1 || j<n2) // checks if the ints are smaller than the size of the two strings 
    {
        while(i<n1 && version1[i]!='.'){ // loop while i is less than the size of version1 and that the character is not '.' at the current index
            num1 = num1*10+(version1[i]-'0'); // set num1 to the current value * 10 + the value of the current character 
            i++; // increment i 
        }
        
        while(j<n2 && version2[j]!='.'){ // loop while j is less than the size of version2 and that the character is not '.' at the current index
            num2 = num2*10+(version2[j]-'0'); // set num2 to the current value * 10 + the value of the current character 
            j++; // increment j 
        }
        
        if(num1>num2) return 1; // checks if num1 is greater than num2 and returns 1 if it is
        else if(num1 < num2) return -1; // checks if num2 is greater than num1 and returns -1 if it is
        
        num1 = 0; // reset num1 to 0
        num2 = 0; // reset num2 to 0
        i++; // increment i
        j++; // increment j
    }
    
    return 0; // return the zero if nothing else is answered
    }
};