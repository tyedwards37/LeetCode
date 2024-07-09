/* Daily Question: 701. Average Waiting Time
 * by Tyler Edwards | July 8th, 2024 
 * Code Credit: rajat_gupta_
 * There is a restaurant with a single chef. You are given an array customers, where customers[i] = [arrivali, timei]:
 * - arrivali is the arrival time of the ith customer. The arrival times are sorted in non-decreasing order.
 * - timei is the time needed to prepare the order of the ith customer.
 * When a customer arrives, he gives the chef his order, and the chef starts preparing it once he is idle. The customer waits till the chef finishes preparing his order. 
 * The chef does not prepare food for more than one customer at a time. The chef prepares food for customers in the order they were given in the input.
 * Return the average waiting time of all customers. Solutions within 10-5 from the actual answer are considered accepted. */

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& A) {
        double wait = 0, cur = 0; // intialize doubles for the current time and the overall wait time
        for (auto& a: A) { // loop for the values in array
            cur = max(cur, 1.0 * a[0]) + a[1]; // updates the double to the max between the current value and the first arrival time and then adds the waiting time
            wait += cur - a[0]; // adds the current minus the starting time to the overall wait time
        }
        return 1.0 * wait / A.size(); // returns the average by taking the overall weight time and dividing it by the size of the array
    }
};