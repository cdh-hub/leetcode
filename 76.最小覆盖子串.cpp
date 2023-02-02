// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem76.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mapT, mapS, mapT2;
        for (auto ch: t) {
            mapT[ch]++;
            mapT2[ch]++;
        }
        string minStr = s;
        int i = 0, j = 0; 
        while (j < s.size()) {
            mapS[s[j]]++;
            if (mapT2.count(s[j])) {
                mapT2[s[j]]--;
                if (mapT2[s[j]] == 0) {
                    mapT2.erase(s[j]);
                    if (mapT2.empty()) break;
                }
            }
            j++;
        }
        if (j == s.size()) return "";
        minStr = s.substr(i, j-i+1);
        while (j < s.size()) {
            while (i <= j) {
                mapS[s[i]]--;
                i++;
                if (mapT.count(s[i-1]) && mapS[s[i-1]] < mapT[s[i-1]]) {
                    break;
                }
            }
            if (i-1 <= j && j < s.size() && j - i + 2 < minStr.size()) {
                minStr = s.substr(i - 1, j - i + 2);
            }
            j++;
            while (j < s.size()) {
                mapS[s[j]]++;
                if (s[j] == s[i-1]) {
                    break;
                }
                j++;
            }
        }
        return minStr;
    }
};
// @lc code=end

