/* LeetCode Day 63: 1318. Minimum Flips to Make a OR b Equal to c (Medium) 69/75 
 * Tyler Edwards | January 5th, 2024 
 * Code Credit: techwired8
 * Given 3 positives numbers a, b and c. Return the minimum flips required in some bits of a and b to make ( a OR b == c ). (bitwise OR operation).
 * Flip operation consists of change any single bit 1 to 0 or change the bit 0 to 1 in their binary representation. */

class Solution {
public:
    int minFlips(int a, int b, int c) 
    {
        int flips = 0;

        while (a > 0 || b > 0 || c > 0)
        {
            int bitA = a & 1;
            int bitB = b & 1;
            int bitC = c & 1;

            if (bitC == 0)
            {
                flips += (bitA + bitB);
            }

            else
            {
                if (bitA == 0 && bitB == 0)
                {
                    flips += 1;
                }
            }

            a >>= 1;
            b >>= 1;
            c >>= 1;
        }

        return flips;
    }
};