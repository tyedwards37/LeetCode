/* Daily Question: 2523. Closest Prime Numbers in Range
 * by Tyler Edwards | March 6th, 2025 
 * Code Credit: Otabek Kholmirzaev
 * Given two positive integers left and right, find the two integers num1 and num2 such that: 
 * - left <= num1 < num2 <= right .
 * - Both num1 and num2 are prime numbers.
 * - num2 - num1 is the minimum amongst all other pairs satisfying the above conditions.
 * Return the positive integer array ans = [num1, num2]. If there are multiple pairs satisfying these conditions, return the one with the smallest num1 value. 
 * If no such numbers exist, return [-1, -1]. */

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> sieve(right + 1, true);
        sieve[0] = sieve[1] = false;
        
        for (int i = 2; i * i <= right; ++i) {
            if (sieve[i]) {
                for (int j = i * i; j <= right; j += i) {
                    sieve[j] = false;
                }
            }
        }
        
        vector<int> primes;
        for (int i = left; i <= right; ++i) {
            if (sieve[i]) {
                primes.push_back(i);
            }
        }
        
        if (primes.size() < 2) {
            return {-1, -1};
        }
        
        int min_gap = INT_MAX;
        vector<int> result = {-1, -1};
        
        for (int i = 1; i < primes.size(); ++i) {
            int gap = primes[i] - primes[i - 1];
            if (gap < min_gap) {
                min_gap = gap;
                result = {primes[i - 1], primes[i]};
            }
        }
        
        return result;
    }
};