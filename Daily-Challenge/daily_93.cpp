/* Daily Question: 2092. Find All People With Secret
 * by Tyler Edwards | February 23rd, 2024 
 * Code Credit: lzl124631x
 * You are given an integer n indicating there are n people numbered from 0 to n - 1. 
 * You are also given a 0-indexed 2D integer array meetings where meetings[i] = [xi, yi, timei] indicates that person xi and person yi have a meeting at timei. 
 * A person may attend multiple meetings at the same time. Finally, you are given an integer firstPerson.
 * Person 0 has a secret and initially shares the secret with a person firstPerson at time 0. 
 * This secret is then shared every time a meeting takes place with a person that has the secret. 
 * More formally, for every meeting, if a person xi has the secret at timei, then they will share the secret with person yi, and vice versa.
 * The secrets are shared instantaneously. That is, a person may receive the secret and share it with people in other meetings within the same time frame.
 * Return a list of all the people that have the secret after all the meetings have taken place. You may return the answer in any order. */

class UnionFind {
    vector<int> id;
public:
    UnionFind(int n) : id(n) {
        iota(begin(id), end(id), 0);
    }
    void connect(int a, int b) {
        id[find(b)] = find(a);
    }
    int find(int a) {
        return id[a] == a ? a : (id[a] = find(id[a]));
    }
    bool connected(int a, int b) {
        return find(a) == find(b);
    }
    void reset(int a) { id[a] = a; }
};

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& A, int firstPerson) {
        sort(begin(A), end(A), [](auto &a, auto &b) { return a[2] < b[2]; }); // Sort the meetings in ascending order of meeting time
        UnionFind uf(n);
        uf.connect(0, firstPerson); // Connect person 0 with the first person
        vector<int> ppl;
        for (int i = 0, M = A.size(); i < M; ) {
            ppl.clear();
            int time = A[i][2];
            for (; i < M && A[i][2] == time; ++i) { // For all the meetings happening at the same time
                uf.connect(A[i][0], A[i][1]); // Connect the two persons
                ppl.push_back(A[i][0]); // Add both persons into the pool
                ppl.push_back(A[i][1]);
            }
            for (int n : ppl) { // For each person in the pool, check if he/she's connected with person 0.
                if (!uf.connected(0, n)) uf.reset(n); // If not, this person doesn't have secret, reset it.
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (uf.connected(0, i)) ans.push_back(i); // Push all the persons who are connected with person 0 into answer array
        }
        return ans;
    }
};