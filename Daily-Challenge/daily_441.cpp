/* Daily Question: 2349. Design a Number Container System
 * by Tyler Edwards | February 7th, 2025 
 * Code Credit: Shubham Baban Shinde
 * Design a number container system that can do the following:
 * - Insert or Replace a number at the given index in the system.
 * - Return the smallest index for the given number in the system.
 * Implement the NumberContainers class:
 * - NumberContainers() Initializes the number container system.
 * - void change(int index, int number) Fills the container at index with the number. If there is already a number at that index, replace it.
 * -int find(int number) Returns the smallest index for the given number, or -1 if there is no index that is filled by number in the system. */

class NumberContainers {
    unordered_map<int,int> m;
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> d;
public:
    NumberContainers(){}
    void change(int i, int n) {
        if(m.count(i) && m[i]==n)return;
        m[i]=n;
        d[n].push(i);
    }
    int find(int n) {
        if(!d.count(n)) return -1;
        auto &pq = d[n];
        while(!pq.empty() && m[pq.top()]!=n) pq.pop();
        return pq.empty()? -1 : pq.top();
    }
};