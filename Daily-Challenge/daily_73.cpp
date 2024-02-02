/* Daily Question: 1291. Sequential Digits
 * by Tyler Edwards | February 1st, 2024 (Happy Birthday Emily!)
 * Code Credit: gagandeepahuja09
 * An integer has sequential digits if and only if each digit in the number is one more than the previous digit.
 * Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits. */

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> q;

        for (int i = 1; i <= 9; i++) {
            q.push(i);
        }

        vector<int> ret;

        while (!q.empty()) {
            int f = q.front();
            q.pop();

            if (f <= high && f >= low) {
                ret.push_back(f);
            }

            if (f > high) {
                break;
            }

            int num = f % 10;

            if (num < 9) {
                q.push(f * 10 + (num + 1));
            }
        }

        return ret;
    }
};