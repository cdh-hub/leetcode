/*
 * @lc app=leetcode.cn id=1093 lang=cpp
 *
 * [1093] 大样本统计
 */

// @lc code=start
class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        double minimum = 300, maximum = 0, mean = 0, median = 0, mode = 0;
        int nums = 0;
        for (int i = 0; i < count.size(); i++) {
            if (count[i]) {
                if (minimum == 300) minimum = i;
                maximum = i;
                mean += count[i] * (double)i;
                if (count[i] > count[mode]) mode = i;
                nums += count[i];
            }
        }
        int cnt = 0, last = -1;
        for (int i = 0; i < count.size(); i++) {
            if (count[i]) {
                cnt += count[i];
                if ((nums & 1) && cnt > nums / 2) {
                    median = i;
                    break;
                }
                if (!(nums & 1) && cnt > nums / 2) {
                    if (cnt - count[i] == nums / 2) {
                        median = ((double)last + i) / 2;
                    }
                    else {
                        median = i;
                    }
                    break;
                }
                last = i;
            }
        }
        mean /= nums;
        return {minimum, maximum, mean, median, mode};
    }
};
// @lc code=end

