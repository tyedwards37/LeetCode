/* Daily Question: 703. Kth Largest Element in a Stream
 * by Tyler Edwards | August 11th, 2024 
 * Code Credit: MichaelZ
 * Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, not the kth distinct element.
 * Implement KthLargest class:
 * - KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of integers nums.
 * - int add(int val) Appends the integer val to the stream and returns the element representing the kth largest element in the stream. */

 class KthLargest {
    public:
        priority_queue<int, vector<int>, greater<int>> pq;
        int size;
        KthLargest(int k, vector<int> nums) {
            size=k;
            for(int i=0;i<nums.size();i++) {
                pq.push(nums[i]);
                if(pq.size()>k) pq.pop();
            }
        }
        
        int add(int val) {
            pq.push(val);
            if(pq.size()>size) pq.pop();
            return pq.top();
        }
    };
    
    /**
     * Your KthLargest object will be instantiated and called as such:
     * KthLargest* obj = new KthLargest(k, nums);
     * int param_1 = obj->add(val);
     */