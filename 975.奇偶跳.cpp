/*
 * @lc app=leetcode.cn id=975 lang=cpp
 *
 * [975] 奇偶跳
 */

// @lc code=start
class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        vector<int> llmin(n, -1);
        vector<int> lsmax(n, -1);
        for (int i = 1; i < n; i++) {
            int j = i - 1, maxnum = -1, minnum = 100010;
            while (j >= 0 && arr[j] <= arr[i]) {
                if (arr[j] > maxnum) {
                    maxnum = arr[j];
                    lsmax[i] = j;
                }
                j--;
            }
            if (j >= 0) {
                while (lsmax[j] != -1 && arr[lsmax[j]] > arr[i]) {
                    j = lsmax[j];
                }
                if (lsmax[j] == -1 && maxnum == -1 || lsmax[j] != -1 && arr[lsmax[j]] > maxnum) lsmax[i] = lsmax[j];
            }
            j = i - 1; 
            while (j >= 0 && arr[j] >= arr[i]) {
                if (arr[j] < minnum) {
                    maxnum = arr[j];
                    llmin[i] = j;
                }
                j--;
            }
            if (j >= 0) {
                while (llmin[j] != -1 && arr[llmin[j]] < arr[i]) {
                    j = llmin[j];
                }
                if (llmin[j] == -1 && minnum == -1 || llmin[j] != -1 && arr[llmin[j]] < minnum) llmin[i] = llmin[j];
            }
        }
        int cnt = 1;
        int k = n - 1;
        bool tag = true;
        while (tag && llmin[k] != -1 || !tag && lsmax[k] != -1) {
            k = tag ? llmin[k] : lsmax[k];
            tag = !tag;
            cnt++;
        }
        tag = false;
        while (tag && llmin[k] != -1 || !tag && lsmax[k] != -1) {
            k = tag ? llmin[k] : lsmax[k];
            tag = !tag;
            cnt++;
        }
        return cnt;
    }
};
// @lc code=end

