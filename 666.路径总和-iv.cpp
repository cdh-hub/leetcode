/*
 * @lc app=leetcode.cn id=666 lang=cpp
 *
 * [666] 路径总和 IV
 */

// @lc code=start
class Solution {
private:
    int calPath(int a[], int pos, int& pathNum) {
        if (pos >= 100 || a[pos] == -1) {
            pathNum = 0;
            return 0;
        }
        int lpathNum, rpathNum;
        int lpath = calPath(a, pos<<1, lpathNum);
        int rpath = calPath(a, (pos<<1)+1, rpathNum);
        if (lpathNum || rpathNum) {
            pathNum = lpathNum + rpathNum;
        }
        else {
            pathNum = 1;
        }
        return lpath + rpath + a[pos]*pathNum;
    }
public:
    int pathSum(vector<int>& nums) {
        int a[100];
        memset(a, -1, sizeof(a));
        for (auto num: nums) {
            a[(1<<(num/100-1))+(num/10)%10-1] = num % 10;
        }
        int pathNum;
        return calPath(a, 1, pathNum);
    }
};
// @lc code=end

