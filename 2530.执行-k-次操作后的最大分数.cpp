/*
 * @lc app=leetcode.cn id=2530 lang=cpp
 *
 * [2530] 执行 K 次操作后的最大分数
 */

// @lc code=start
class Cmp {
public:
    bool operator()(const int& a, const int& b) const {
        return a > b;
    }
};
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long score = 0;
        map<int, int, Cmp> map;
        for (auto num: nums) {
            map[num]++;
        }
        while (k--) {
            int key = (*map.begin()).first;
            score += key;
            map[(key + 2) / 3]++;
            map[key]--;
            if (map[key] == 0) map.erase(key);
        }
        return score;
    }
};
// @lc code=end

