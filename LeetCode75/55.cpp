/* LeetCode Day 51: 2336. Smallest Number in Infinite Set (Medium) 55/75 
 * Tyler Edwards | December 20th, 2023
 * Code Credit: aryan_0077
 * You have a set which contains all positive integers [1, 2, 3, 4, 5, ...].
 * Implement the SmallestInfiniteSet class:
 * - SmallestInfiniteSet() Initializes the SmallestInfiniteSet object to contain all positive integers.
 * - int popSmallest() Removes and returns the smallest integer contained in the infinite set.
 * - void addBack(int num) Adds a positive integer num back into the infinite set, if it is not already in the infinite set. */

class SmallestInfiniteSet {
public:
    int cur;
    set<int> s;
    SmallestInfiniteSet() 
    {
        cur = 1;
    }
    
    int popSmallest() 
    {
        if(s.size())
        {
            int res =* s.begin(); s.erase(res);
            return res;
        }
        
        else
        {
            cur++;
            return cur - 1;
        }
    }
    
    void addBack(int num) {
        if(cur>num) 
        {
            s.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */