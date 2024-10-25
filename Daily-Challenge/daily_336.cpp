/* Daily Question: 1233. Remove Sub-Folders from the Filesystem
 * by Tyler Edwards | October 23rd, 2024 
 * Code Credit: PhoenixDD
 * Given a list of folders folder, return the folders after removing all sub-folders in those folders. You may return the answer in any order.
 * If a folder[i] is located within another folder[j], it is called a sub-folder of it. 
 * A sub-folder of folder[j] must start with folder[j], followed by a "/". For example, "/a/b" is a sub-folder of "/a", but "/b" is not a sub-folder of "/a/b/c".
 * The format of a path is one or more concatenated strings of the form: '/' followed by one or more lowercase English letters.
 * - For example, "/leetcode" and "/leetcode/problems" are valid paths while an empty string and "/" are not. */

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) 
    {
        sort(folder.begin(),folder.end());
        vector<string> result;
        for(string &s:folder)
            if(result.empty()                          //Check if 1. This is the first string, 
				|| result.back().compare(0,result.back().length(),s,0,result.back().length())!=0 //2.parent at back is not the parent of `s` by comparing.
				|| s[result.back().length()]!='/')    //3. If the entire parent matches `s` check if last folder name in parent does not match the folder of same depth in `s`. for cases like `/a/b, /a/bc`.
                result.push_back(s);                                  
        return result;
    }
};