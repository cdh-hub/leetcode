/*
 * @lc app=leetcode.cn id=621 lang=cpp
 *
 * [621] 任务调度器
 */

// @lc code=start
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int count[26] = {0};
        int maxCount = 0;
        for (char ch: tasks) {
            count[ch-'A']++;
            maxCount = max(maxCount, count[ch-'A']);
        }
        int maxCountNum = 0, cur = 0;
        for (int i = 0; i < 26; i++) {
            if (count[i] == maxCount) maxCountNum++;
            else cur += count[i];
        }
        if (maxCount == 1 || cur / (maxCount-1) + maxCountNum > n) return cur + maxCount * maxCountNum;
        else return (n+1) * (maxCount-1) + maxCountNum; 
    }
};
// @lc code=end

