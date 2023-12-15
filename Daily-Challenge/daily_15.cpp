/* Daily Question: 191. Number of 1 Bits
 * by Tyler Edwards | November 28th, 2023 
 * Write a function that takes the binary representation of an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight). */

class Solution {
public:
    int hammingWeight(uint32_t n) 
    {
        int count = 0;

        for (int i = 0; i < 32; i++)
        {
            if (n & 1)
            {
                count++;
            }

            n >>= 1;
        }

        return count;
    }
};
