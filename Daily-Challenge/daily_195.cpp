/* Daily Question: 846. Hand of Straights
 * by Tyler Edwards | June 5th, 2024 
 * Code Credit: lancertech6
 * Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.
 * Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise. */

class Solution {
public:
   bool findSuccessors(vector<int>& hand, int groupSize, int i, int n) {
        int next = hand[i] + 1; // intialize an integer to the value in the hand array at the given index i plus 1 
        hand[i] = -1;  // mark as used with a -1
        int count = 1; // intialize a count integer starting at 1
        i++; // incement the i index by 1
        while (i < n && count < groupSize) { // loop while the index is less than the given value n and count is less than the group size
            if (hand[i] == next) { // check if the value at the new index i is the same as the next value
                next = hand[i] + 1; // set next to the value at the new index i in the hand array plus 1
                hand[i] = -1; // set the value at the new index i to -1 to mark it as read
                count++; // increment the count variable
            }
            i++; // increment the index variable
        }
        return count == groupSize; // return if the count is equal to the group size
    }

    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size(); // intialize an integer to the size of the hand array 
        if (n % groupSize != 0) return false; // check if the size is divisible by the group size and if it isnt return false
        std::sort(hand.begin(), hand.end()); // sort the hand array
        for (int i = 0; i < n; i++) { // loop for the size of the hand array
            if (hand[i] >= 0) { // check if the value at the current index is not -1
                if (!findSuccessors(hand, groupSize, i, n)) return false; // checks if find sucessor is false then returns false
            }
        }
        return true; // returns true if the find sucessors is true
    }
};