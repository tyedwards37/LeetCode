/* Daily Question: 2037. Minimum Number of Moves to Seat Everyone
 * by Tyler Edwards | June 12th, 2024 
 * Code Credit: amanrathore48
 * There are n seats and n students in a room. You are given an array seats of length n, where seats[i] is the position of the ith seat. 
 * You are also given the array students of length n, where students[j] is the position of the jth student.
 * You may perform the following move any number of times:
 * - Increase or decrease the position of the ith student by 1 (i.e., moving the ith student from position x to x + 1 or x - 1)
 * Return the minimum number of moves required to move each student to a seat such that no two students are in the same seat.
 * Note that there may be multiple seats or students in the same position at the beginning. */

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end()); // sorts the seats in increasing order
        sort(students.begin(), students.end()); // sorts the students in increasing order

        int count = 0; // intializes an integer for the number of changes made
        for (int i = 0; i < seats.size() ; i++) { // loops for the size of the arrays
            while(seats[i] != students[i]) { //  loops while the student position value at the current index doesn't match the seat value
                if (seats[i] < students[i]) students[i] = students[i] - 1; // checks if the seat pos is less than the student pos and decrements the studen't position
                else students[i] = students[i] + 1; // if the seat pos is not less or equal it must be more than the student pos so increment the student position
                count++; // a move has occured so increment the count variable
            }
        }

        return count; // return the final count variable once out of both the while and for loops
    }
};