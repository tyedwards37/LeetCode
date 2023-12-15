/* LeetCode Day 3: Can Place Flowers (Easy) 4/75 
 * by Tyler Edwards | October 26th, 2023
 * Desc: You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.
 * Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return true if n new flowers 
 * can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise. */

class Solution {
public:
    #include <vector> 

    bool canPlaceFlowers(vector<int>& flowerbed, int n) 
    {
        if(n == 0)
        {
            return true;
        }

        int space = 0;
        int count = 0;
        for(int flower : flowerbed)
        {
            count++;
            if(flower == 0)
            {
                if(count == 1 || count == flowerbed.size())
                {
                    if(n == 1 && flowerbed.size() == 1)
                    {
                        space += 3;
                    }
                    else
                    {
                        space += 2;
                    }
                }
                else
                {
                    space++;
                }
            }
            else
            {
                space = 0;
            }

            if(space >= 3)
            {
                n--;
                space = 1;
                if(n == 0)
                {
                    return true;
                }
            }
        }

        return false;
    }
};
