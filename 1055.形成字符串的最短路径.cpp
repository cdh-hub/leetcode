/*
 * @lc app=leetcode.cn id=1055 lang=cpp
 *
 * [1055] 形成字符串的最短路径
 */

// @lc code=start
class Solution {
public:
    int shortestWay(string source, string target) {
        int n1 = source.size();
        vector<int> pos[26];
        for (int i = 0; i < 26; i++) pos[i] = vector<int>();
        for (int i = 0; i < n1; i++) pos[source[i]-'a'].push_back(i);
        int cur = n1, ans = 0;
        for (char ch: target) {
            if (pos[ch-'a'].empty()) return -1;
            int l = 0, r = pos[ch-'a'].size()-1;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (pos[ch-'a'][mid] <= cur) l = mid + 1;
                else r = mid - 1;
            }
            if (l < pos[ch-'a'].size()) cur = pos[ch-'a'][l];
            else {
                cur = pos[ch-'a'][0];
                ++ans;
            }
        }
        return ans;
    }
};
// @lc code=end

