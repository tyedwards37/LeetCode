/* Daily Question: 1381. Design a Stack With Increment Operation
 * by Tyler Edwards | September 29th, 2024 
 * Code Credit: lee215
 * Design a stack that supports increment operations on its elements.
 * Implement the CustomStack class:
 * - CustomStack(int maxSize) Initializes the object with maxSize which is the maximum number of elements in the stack.
 * - void push(int x) Adds x to the top of the stack if the stack has not reached the maxSize.
 * - int pop() Pops and returns the top of the stack or -1 if the stack is empty.
 * - void inc(int k, int val) Increments the bottom k elements of the stack by val. If there are less than k elements in the stack, increment all the elements in the stack. */

    vector<int> stack, inc;
    int n;
    CustomStack(int maxSize) {
        n = maxSize;
    }

    void push(int x) {
        if (stack.size() == n) return;
        stack.push_back(x);
        inc.push_back(0);
    }

    int pop() {
        int i = stack.size() - 1;
        if (i < 0) return -1;
        if (i > 0) inc[i - 1] += inc[i];
        int res = stack[i] + inc[i];
        stack.pop_back();
        inc.pop_back();
        return res;
    }

    void increment(int k, int val) {
        int i = min(k, (int)stack.size()) - 1;
        if (i >= 0) inc[i] += val;
    }