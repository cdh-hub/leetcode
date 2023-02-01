/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0, j = nums.size()-1;
        for (int k = 0; k < nums.size(); k++) {
            while (k < nums.size() && nums[k] != 1) {
                if (nums[k] == 0) {
                    if (i < k) {
                        swap(nums[i], nums[k]);
                        i++;
                    }
                    else {
                        i++;
                        k++;
                    }
                }
                else {
                    if (k < j) {
                        swap(nums[j], nums[k]);
                        j--;
                    }
                    else break;
                }
            }
        }
    }
};
// @lc code=end

