/* Daily Question: 2073. Time Needed to Buy Tickets
 * by Tyler Edwards | April 8th, 2024 
 * There are n people in a line queuing to buy tickets, where the 0th person is at the front of the line and the (n - 1)th person is at the back of the line.
 * You are given a 0-indexed integer array tickets of length n where the number of tickets that the ith person would like to buy is tickets[i].
 * Each person takes exactly 1 second to buy a ticket. A person can only buy 1 ticket at a time and has to go back to the end of the line (which happens instantaneously) in order to buy more tickets. 
 * If a person does not have any tickets left to buy, the person will leave the line.
 * Return the time taken for the person at position k (0-indexed) to finish buying tickets. */

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int count = 0; // intialize a variable to track the total number of seconds
        while(tickets[k] != 0) { // loop while the target customer still wants to buy tickets
            for (int i = 0; i < tickets.size(); i++) { // loop for the number of people in line
                if (tickets[i] > 0) { // check if they still want to buy tickets (their value isn't zero) 
                    tickets[i]--; // they buy a ticket (decrement the value at this spot)
                    count++; // increment the toal number of seconds taken
                }

                if(tickets[k] == 0) { // check if the target customer has reached 0
                    break; // if they have bought all the tickets they need break
                }
            }
        }
        return count; // return the total number of seconds
    }
};
