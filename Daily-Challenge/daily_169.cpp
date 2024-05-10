/* Daily Question: 786. K-th Smallest Prime Fraction
 * by Tyler Edwards | May 9th, 2024 (rough day)
 * Code Credit: ayushnemmaniwar12
 * You are given a sorted integer array arr containing 1 and prime numbers, where all the integers of arr are unique. You are also given an integer k.
 * For every i and j where 0 <= i < j < arr.length, we consider the fraction arr[i] / arr[j].
 * Return the kth smallest fraction considered. Return your answer as an array of integers of size 2, where answer[0] == arr[i] and answer[1] == arr[j]. */

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double, pair<int, int>>> maxHeap;
        int n = arr.size();

        for(int i = 0; i < n - 1; i++) {
            for(int j =i + 1; j < n; j++) {
                maxHeap.push({((double) arr[i] / arr[j]), {arr[i], arr[j]}});

                if(maxHeap.size() > k) {
                    maxHeap.pop();
                }
            }
        }

        auto res = maxHeap.top().second;
        return {res.first, res.second};
    }
};