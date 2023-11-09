/* LeetCode Day 16: Guess Number Higher or Lower (Easy) 18/75 
 * by Tyler Edwards | November 9th, 2023 
 * Desc: I pick a number from 1 to n. You have to guess which number I picked. 
 * Every time you guess wrong, I will tell you whether the number I picked is higher or lower than your guess.
 * Return the number that I picked. */

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int binarySearch(int start, int end)
    {
        int mid = start + (end - start) / 2;
        int check = guess(mid);

        if(check == 0)
        {
            return mid;
        }

        else if (check == -1)
        {
            return binarySearch(start, mid - 1);
        }

        else
        {
            return binarySearch(mid + 1, end);
        }
    }

    int guessNumber(int n) 
    {
        return binarySearch(1, n);
    }
};