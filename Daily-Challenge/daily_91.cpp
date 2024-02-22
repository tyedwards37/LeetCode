/* Daily Question: 997. Find the Town Judge
 * by Tyler Edwards | February 21st, 2024 
 * Code Credit: lee215
 * In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is secretly the town judge.
 * If the town judge exists, then:
 * 1. The town judge trusts nobody.
 * 2. Everybody (except for the town judge) trusts the town judge.
 * 3. There is exactly one person that satisfies properties 1 and 2.
 * You are given an array trust where trust[i] = [ai, bi] representing that the person labeled ai trusts the person labeled bi. 
 * If a trust relationship does not exist in trust array, then such a trust relationship does not exist.
 * Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise. */

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> count(N + 1, 0);

        for (auto& t : trust) {
            count[t[0]]--, count[t[1]]++;
        }

        for (int i = 1; i <= N; i++) {
            if (count[i] == N - 1) return i;
        }

        return -1;
    }
};