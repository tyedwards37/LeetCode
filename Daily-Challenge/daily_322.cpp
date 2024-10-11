/* Daily Question: 1942. The Number of the Smallest Unoccupied Chair
 * by Tyler Edwards | October 9th, 2024 
 * Code Credit: lee215
 * There is a party where n friends numbered from 0 to n - 1 are attending. There is an infinite number of chairs in this party that are numbered from 0 to infinity. 
 * When a friend arrives at the party, they sit on the unoccupied chair with the smallest number.
 * - For example, if chairs 0, 1, and 5 are occupied when a friend comes, they will sit on chair number 2.
 * When a friend leaves the party, their chair becomes unoccupied at the moment they leave. If another friend arrives at that same moment, they can sit in that chair.
 * You are given a 0-indexed 2D integer array times where times[i] = [arrivali, leavingi], indicating the arrival and leaving times of the ith friend respectively, and an integer targetFriend.
 * All arrival times are distinct. 
 * Return the chair number that the friend numbered targetFriend will sit on. */

class Solution {
public:
    int smallestChair(vector<vector<int>>& a, int t){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        int f = a[t][0];                              //target friend arrival time
        sort(a.begin(), a.end());
        int n=0;                                      //starting seat
        set<int> s;
        for(auto v: a){
            int at = v[0];                            //arrival time
            int lt = v[1];                            //leaving time
            int cs;                                   //current seat
            while(!q.empty() && q.top().first<=at){       //it top of priority queue is less than or equal to arrival time push seat number in set..
                s.insert(q.top().second);
                q.pop();
            }
			//if set size is not 0 then current seat will be s.begin() else current seat will be n
            if(s.size()!=0){         
                cs=*(s.begin());
                s.erase(s.begin());
            }
            else{
                cs=n;
                n++;
            }
            q.push({lt, cs});       //push leaving time and seat number in queue
            if(f==at){               //if arrival time of current friend is equal to arrival time of target friend return current seat number  (it is given all arrival time are distinct)
                return cs;
            }
        }
        return 0;
    }
};