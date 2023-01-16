/*
 * @lc app=leetcode.cn id=955 lang=cpp
 *
 * [955] 删列造序 II
 */

// @lc code=start
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int cnt = 0;
        vector<bool> record(strs.size(), true);
        for (int j = 0; j < strs[0].size(); j++) {
            char pre = strs[0][j];
            vector<int> index;
            for (int i = 1; i < strs.size(); i++) {
                if (record[i]) {
                    if (strs[i][j] < pre) {
                        cnt++;
                        index.clear();
                        break;
                    }
                    else if (strs[i][j] > pre) {
                        index.push_back(i);
                    }
                }
                pre = strs[i][j];
            }
            for (int k = 0; k < index.size(); k++) {
                record[index[k]] = false;
            }
            bool tag = false;
            for (int i = 1; i < record.size(); i++) {
                if (record[i]) {
                    tag = true;
                    break;
                } 
            }
            if (!tag) return cnt;
        }
        return cnt;
    }
};
// @lc code=end

