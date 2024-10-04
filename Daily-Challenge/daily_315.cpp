/* Daily Question: 2491. Divide Players Into Teams of Equal Skill
 * by Tyler Edwards | October 3rd, 2024 
 * Code Credit: stanislav-iablokov
 * You are given a positive integer array skill of even length n where skill[i] denotes the skill of the ith player. 
 * Divide the players into n / 2 teams of size 2 such that the total skill of each team is equal.
 * The chemistry of a team is equal to the product of the skills of the players on that team.
 *Return the sum of the chemistry of all the teams, or return -1 if there is no way to divide the players into teams such that the total skill of each team is equal. */

class Solution 
{
public:
    long long dividePlayers(vector<int>& ss) 
    {
        int s = 2 * accumulate(ss.begin(), ss.end(), 0) / ss.size();
        long long chemistry = 0;
        
        unordered_map<long long, int> cnt;
        for (int n : ss) ++cnt[n];
        
        for (auto[v,c] : cnt)
            if (!cnt.count(s-v) || cnt[s-v] != c)
                return -1;
            else
                chemistry += c * v * (s-v);
        
        return chemistry / 2;
    }
};