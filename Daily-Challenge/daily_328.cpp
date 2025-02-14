/* Daily Question: 670. Maximum Swap
 * by Tyler Edwards | October 16th, 2024 
 * Code Credit: TimmyLu926
 * You are given an integer num. You can swap two digits at most once to get the maximum valued number.
 * Return the maximum valued number you can get. */

class Solution {
public:
    int maximumSwap(int num) {
        string numstr = std::to_string(num);

        int maxidx = -1; int maxdigit = -1;
        int leftidx = -1; int rightidx = -1;        

        for (int i = numstr.size() - 1; i >= 0; --i) {
            // current digit is the largest by far
            if (numstr[i] > maxdigit) {
                maxdigit = numstr[i];
                maxidx = i;
                continue;
            }

            // best candidate for max swap if there is no more 
            // such situation on the left side
            if (numstr[i] < maxdigit) {
                leftidx = i;
                rightidx = maxidx;
            }
        }

        // num is already in order
        if (leftidx == -1) return num;

        std::swap(numstr[leftidx], numstr[rightidx]);

        return std::stoi(numstr);
    }
};