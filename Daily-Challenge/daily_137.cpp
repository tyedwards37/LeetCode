/* Daily Question: 1700. Number of Students Unable to Eat Lunch
 * by Tyler Edwards | April 7th, 2024 
 * Code Credit: lee215
 * The school cafeteria offers circular and square sandwiches at lunch break, referred to by numbers 0 and 1 respectively. 
 * All students stand in a queue. Each student either prefers square or circular sandwiches.
 * The number of sandwiches in the cafeteria is equal to the number of students. The sandwiches are placed in a stack. At each step:
 * - If the student at the front of the queue prefers the sandwich on the top of the stack, they will take it and leave the queue.
 * - Otherwise, they will leave it and go to the queue's end.
 * This continues until none of the queue students want to take the top sandwich and are thus unable to eat.
 * You are given two integer arrays students and sandwiches where sandwiches[i] is the type of the i​​​​​​th sandwich in the stack (i = 0 is the top of the stack) and students[j] is the preference of the j​​​​​​th student in the initial queue (j = 0 is the front of the queue). 
 * Return the number of students that are unable to eat. */

class Solution {
public:
        int countStudents(vector<int>& A, vector<int>& B) {
            int count[] = {0, 0}, n = A.size(), k; // start an unordered set, set two varaibles equal to the size of A
            for (int a : A) // loop for all the integers in the first array
                count[a]++; // increase the count of that value integer by one
            for (k = 0; k < n && count[B[k]] > 0; ++k) // loop as long as k is lesss than n and the count of the balue of B at index k is greater than 0
                count[B[k]]--; // decrement the count of the value of the integer at index k 
            return n - k; // return the size minus the final k value
    }
};