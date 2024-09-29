/* Daily Question: 641. Design Circular Deque
 * by Tyler Edwards | September 28th, 2024 
 * Code Credit: StefanPochmann
 * Design a data structure to store the strings' count with the ability to return the strings with minimum and maximum counts.
 * Implement the AllOne class:
 * - AllOne() Initializes the object of the data structure.
 * - inc(String key) Increments the count of the string key by 1. If key does not exist in the data structure, insert it with count 1.
 * - dec(String key) Decrements the count of the string key by 1. If the count of key is 0 after the decrement, remove it from the data structure. 
 *   It is guaranteed that key exists in the data structure before the decrement.
 * - getMaxKey() Returns one of the keys with the maximal count. If no element exists, return an empty string "".
 * - getMinKey() Returns one of the keys with the minimum count. If no element exists, return an empty string "". */

class AllOne {
    public:
    
        void inc(string key) {
            
            // If the key doesn't exist, insert it with value 0.
            if (!bucketOfKey.count(key))
                bucketOfKey[key] = buckets.insert(buckets.begin(), {0, {key}});
                
            // Insert the key in next bucket and update the lookup.
            auto next = bucketOfKey[key], bucket = next++;
            if (next == buckets.end() || next->value > bucket->value + 1)
                next = buckets.insert(next, {bucket->value + 1, {}});
            next->keys.insert(key);
            bucketOfKey[key] = next;
            
            // Remove the key from its old bucket.
            bucket->keys.erase(key);
            if (bucket->keys.empty())
                buckets.erase(bucket);
        }
    
        void dec(string key) {
    
            // If the key doesn't exist, just leave.
            if (!bucketOfKey.count(key))
                return;
    
            // Maybe insert the key in previous bucket and update the lookup.
            auto prev = bucketOfKey[key], bucket = prev--;
            bucketOfKey.erase(key);
            if (bucket->value > 1) {
                if (bucket == buckets.begin() || prev->value < bucket->value - 1)
                    prev = buckets.insert(bucket, {bucket->value - 1, {}});
                prev->keys.insert(key);
                bucketOfKey[key] = prev;
            }
            
            // Remove the key from its old bucket.
            bucket->keys.erase(key);
            if (bucket->keys.empty())
                buckets.erase(bucket);
        }
    
        string getMaxKey() {
            return buckets.empty() ? "" : *(buckets.rbegin()->keys.begin());
        }
        
        string getMinKey() {
            return buckets.empty() ? "" : *(buckets.begin()->keys.begin());
        }
    
    private:
        struct Bucket { int value; unordered_set<string> keys; };
        list<Bucket> buckets;
        unordered_map<string, list<Bucket>::iterator> bucketOfKey;
    };