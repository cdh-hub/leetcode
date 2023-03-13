/*
 * @lc app=leetcode.cn id=2383 lang=cpp
 *
 * [2383] 赢得比赛需要的最少训练时长
 */

// @lc code=start
class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int n = energy.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (initialEnergy <= energy[i]) {
                ans += energy[i] + 1 - initialEnergy;
                initialEnergy = energy[i] + 1;
            }
            if (initialExperience <= experience[i]) {
                ans += experience[i] + 1 - initialExperience;
                initialExperience = experience[i] + 1;
            }
            initialExperience += experience[i];
            initialEnergy -= energy[i];
        }
        return ans;
    }
};
// @lc code=end

