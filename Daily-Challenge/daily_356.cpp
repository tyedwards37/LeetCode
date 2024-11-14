/* Daily Question: 2064. Minimized Maximum of Products Distributed to Any Store
 * by Tyler Edwards | November 13th, 2024  
 * Code Credit: lee
 * You are given an integer n indicating there are n specialty retail stores. 
 * There are m product types of varying amounts, which are given as a 0-indexed integer array quantities, where quantities[i] represents the number of products of the ith product type.
 * You need to distribute all products to the retail stores following these rules:
 * - A store can only be given at most one product type but can be given any amount of it.
 * - After distribution, each store will have been given some number of products (possibly 0). Let x represent the maximum number of products given to any store. 
     You want x to be as small as possible, i.e., you want to minimize the maximum number of products that are given to any store. 
 * Return the minimum possible x. */

class Solution {
public:
    int minimizedMaximum(int n, vector<int>& A) {
        int left = 1, right = 100000;
        while (left < right) {
            int mid = (left + right) / 2, sum = 0;
            for (int a : A)
                sum += (a + mid - 1) / mid;
            if (sum > n)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};