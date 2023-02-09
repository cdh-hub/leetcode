/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */

// @lc code=start
class Solution {
private:
    int partition(vector<int>& nums, int l, int r, int x) {
        int i = l, j = r;
        while (i <= j) {
            while (i <= j && nums[i] <= x) i++;
            while (i <= j && nums[j] > x) j--; 
            if (i <= j) swap(nums[i], nums[j]);
        }
        return i;
    }
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size()-1;
        int l = 0, r = n, lVal = 1, rVal = n;
        while (lVal != rVal) {
            int pos = partition(nums, l, r, lVal + (rVal - lVal) / 2);
            int leftNum = pos - l, rightNum = r - pos + 1;
            if ((rVal - lVal + 1) % 2 == 0) {
                if (leftNum < rightNum) {
                    l = pos;
                    lVal = lVal + (rVal - lVal) / 2 + 1;
                }
                else {
                    r = pos - 1;
                    rVal = lVal + (rVal - lVal) / 2;
                }
            }
            else {
                if (leftNum <= rightNum) {
                    l = pos;
                    lVal = lVal + (rVal - lVal) / 2 + 1;
                }
                else {
                    r = pos - 1;
                    rVal = lVal + (rVal - lVal) / 2;
                }
            }
        }
        return lVal;
    }
};
// @lc code=end

