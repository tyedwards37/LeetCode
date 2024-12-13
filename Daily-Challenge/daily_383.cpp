/* Daily Question: 2558. Take Gifts From the Richest Pile
 * by Tyler Edwards | December 11th, 2024  
 * Code Credit: Kishan Kumar Patel
 * You are given an integer array gifts denoting the number of gifts in various piles. Every second, you do the following:
 * - Choose the pile with the maximum number of gifts.
 * - If there is more than one pile with the maximum number of gifts, choose any.
 * - Leave behind the floor of the square root of the number of gifts in the pile. Take the rest of the gifts.
 * The beauty of the array is the length of the longest subsequence consisting of equal elements.
 * Return the maximum possible beauty of the array nums after applying the operation any number of times.
 * Note that you can apply the operation to each index only once.
 * A subsequence of an array is a new array generated from the original array by deleting some elements (possibly none) without changing the order of the remaining elements. */

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long ans = 0;
        priority_queue<int> maxHeap;
        for(auto n: gifts) maxHeap.push(n);
        while(k--){ maxHeap.push(sqrt(maxHeap.top())); maxHeap.pop(); }
        while(maxHeap.size() > 0){ ans+= maxHeap.top(); maxHeap.pop(); }
        return ans;
    }
};