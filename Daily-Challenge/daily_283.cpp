/* Daily Question: 1894. Find the Student that Will Replace the Chalk
 * by Tyler Edwards | September 1st, 2024 
 * Code Credit: itz_pankaj
 * There are n students in a class numbered from 0 to n - 1. 
 * The teacher will give each student a problem starting with the student number 0, then the student number 1, and so on until the teacher reaches the student number n - 1. 
 * After that, the teacher will restart the process, starting with the student number 0 again.
 * You are given a 0-indexed integer array chalk and an integer k. 
 * There are initially k pieces of chalk. When the student number i is given a problem to solve, they will use chalk[i] pieces of chalk to solve that problem. 
 * However, if the current number of chalk pieces is strictly less than chalk[i], then the student number i will be asked to replace the chalk.
 * Return the index of the student that will replace the chalk pieces. */

 class Solution {
    public:
        int chalkReplacer(vector<int>& chalk, int k) {
        
            size_t sum=0;
            for(auto &x: chalk)
                sum+=x;    // getting sum of all chalk values
            
            k = k%sum;   // modifyig k so that we dont have to do that much iterations
            
            for(int i=0;i<chalk.size();i++)  
            {  if( k-chalk[i] < 0) return i;
                else
                    k-=chalk[i];
            }
        return chalk.size()-1;
        }
    };