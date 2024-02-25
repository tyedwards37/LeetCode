/* Daily Question: 2709. Greatest Common Divisor Traversal
 * by Tyler Edwards | February 24th, 2024 
 * Code Credit: cpcs
 * You are given a 0-indexed integer array nums, and you are allowed to traverse between its indices. 
 * You can traverse between index i and index j, i != j, if and only if gcd(nums[i], nums[j]) > 1, where gcd is the greatest common divisor.
 * Your task is to determine if for every pair of indices i and j in nums, where i < j, there exists a sequence of traversals that can take us from i to j.
 * Return true if it is possible to traverse between all such pairs of indices, or false otherwise.*/

class Solution {
    int getf(vector<int> &f, int x) {
        return f[x] == x ? x : (f[x] = getf(f, f[x]));
    }
    
    void merge(vector<int> &f, vector<int> &num, int x, int y) {
        x = getf(f, x);
        y = getf(f, y);
        if (x == y) {
            return;
        }
        if (num[x] < num[y]) {
            swap(x, y);
        }
        f[y] = x;
        num[x] += num[y];
    }
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        const int n = nums.size();
        if (n == 1) {
            return true;
        }
        vector<int> f(n), num(n);
        for (int i = 0; i < n; ++i) {
            f[i] = i;
            num[i] = 1;
        }
        unordered_map<int, int> have;
        for (int i = 0; i < n; ++i) {
            int x = nums[i];
            if (x == 1) {
                return false;
            }
            for (int d = 2; d * d <= x; ++d) {
                if (x % d == 0) {
                    if (have.count(d)) {
                        merge(f, num, i, have[d]);
                    } else {
                        have[d] = i;
                    }
                    while (x % d == 0) {
                        x /= d;
                    } 
                }
            }
            if (x > 1) {
                if (have.count(x)) {
                    merge(f, num, i, have[x]);
                } else {
                    have[x] = i;
                }
            }
        }
        return num[getf(f, 0)] == n;
        
    }
};
     