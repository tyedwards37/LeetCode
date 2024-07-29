/* Daily Question: 1395. Count Number of Teams
 * by Tyler Edwards | July 28th, 2024 
 * Code Credit: votrubac
 * There are n soldiers standing in a line. Each soldier is assigned a unique rating value.
 * You have to form a team of 3 soldiers amongst them under the following rules:
 * - Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j], rating[k]).
 * - A team is valid if: (rating[i] < rating[j] < rating[k]) or (rating[i] > rating[j] > rating[k]) where (0 <= i < j < k < n).
 * Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams). */

int numTeams(vector<int>& rating) {
    int res = 0;
    for (auto i = 1; i < rating.size() - 1; ++i) {
        int less[2] = {}, greater[2] = {};
        for (auto j = 0; j < rating.size(); ++j) {
            if (rating[i] < rating[j])
                ++less[j > i];
            if (rating[i] > rating[j])
                ++greater[j > i];
        }
        res += less[0] * greater[1] + greater[0] * less[1];
    }
    return res;
}