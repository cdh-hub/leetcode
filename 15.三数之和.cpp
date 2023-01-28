/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        map<int, int> map;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            map[nums[i]]++;
        }
        for (auto it1 = map.begin(); it1 != map.end(); it1++) {
            int k1 = (*it1).first, v1 = (*it1).second;
            for (auto it2 = it1; it2 != map.end(); it2++) {
                int k2 = (*it2).first, v2 = (*it2).second;
                int k3 = 0 - k1 - k2;
                if (map.count(k3)) {
                    int v3 = map[k3];
                    if (k1 == k2 && k1 == k3 && v1 >= 3) ans.push_back(vector<int>(3, k1));
                    else if (k1 == k2 && k2 < k3 && v1 >= 2) ans.push_back({k1,k2,k3});
                    else if (k1 < k2 && k2 == k3 && v2 >= 2) ans.push_back({k1,k2,k3});
                    else if (k1 < k2 && k2 < k3) ans.push_back({k1,k2,k3});
                }
            }
        }
        return ans;
    }
};
// @lc code=end

