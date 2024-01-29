/* Daily Question: 232. Implement Queue using Stacks
 * by Tyler Edwards | January 28th, 2024 
 * Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).
 * Implement the MyQueue class:
 * - void push(int x) Pushes element x to the back of the queue.
 * - int pop() Removes the element from the front of the queue and returns it.
 * - int peek() Returns the element at the front of the queue.
 * - boolean empty() Returns true if the queue is empty, false otherwise. */

 class MyQueue {
public:
    stack<int> s;

    MyQueue() {
        
    }
    
    void push(int x) {
        stack<int> temp;

        while (s.size() != 0)
        {
            temp.push(s.top());
            s.pop();
        }

        s.push(x);

        while (temp.size() != 0) {
            s.push(temp.top());
            temp.pop();
        }
    }
    
    int pop() {
        int data = s.top();
        s.pop();
        return data;
    }
    
    int peek() {
        return s.top();
    }
    
    bool empty() {
        return (s.size() == 0);
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */