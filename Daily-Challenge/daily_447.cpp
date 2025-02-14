/* Daily Question: 1352. Product of the Last K Numbers
 * by Tyler Edwards | February 13th, 2025 
 * Code Credit: lee
 * Design an algorithm that accepts a stream of integers and retrieves the product of the last k integers of the stream.
 * Implement the ProductOfNumbers class:
 * - ProductOfNumbers() Initializes the object with an empty stream.
 * - void add(int num) Appends the integer num to the stream.
 * - int getProduct(int k) Returns the product of the last k numbers in the current list. You can assume that always the current list has at least k numbers.
 * The test cases are generated so that, at any time, the product of any contiguous sequence of numbers will fit into a single 32-bit integer without overflowing. */

class ProductOfNumbers {
public:
    vector<int> A = {1};
    void add(int a) {
        if (a)
            A.push_back(A.back() * a);
        else
            A = {1};
    }

    int getProduct(int k) {
        return k < A.size() ? A.back() / A[A.size() - k - 1]  : 0;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */