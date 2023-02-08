/*
 * @lc app=leetcode.cn id=2531 lang=cpp
 *
 * [2531] 使字符串总不同字符的数目相等
 */

// @lc code=start
class Solution {
public:
    bool isItPossible(string word1, string word2) {
        map<int, int> w1, w2;
        for (auto word: word1) w1[word]++;
        for (auto word: word2) w2[word]++;
        int a = w1.size(), b = w2.size();
        if (a > b) swap(a, b), swap(w1, w2);
        if (b - a > 2) return false;
        if (b == a) {
            for (auto [k1, v1]: w1) {
                for (auto [k2, v2]: w2) {
                    if (k1 == k2) return true;
                    if (v1 > 1) {
                        if (!w2.count(k1)) {
                            if (v2 > 1 && !w1.count(k2) || v2 == 1 && w1.count(k2)) return true;
                        }
                        else {
                            if (v2 > 1 && w1.count(k2)) return true;
                        }
                    }
                    else {
                        if (!w2.count(k1)) {
                            if (v2 == 1 && !w1.count(k2)) return true;
                        }
                        else {
                            if (v2 == 1 && w1.count(k2) || v2 > 1 && !w1.count(k2)) return true;
                        }
                    }
                }
            }
        }
        else if (b == a + 1) {
            for (auto [k1, v1]: w1) {
                for (auto [k2, v2]: w2) {
                    if (k1 == k2) continue;
                    if (v1 > 1) {
                        if (w2.count(k1)) {
                            if (v2 == 1 && w1.count(k2) || v2 > 1 && !w1.count(k2)) return true;
                        }
                    }
                    else {
                        if (w2.count(k1)) {
                            if (v2 == 1 && !w1.count(k2)) return true;
                        }
                    }
                }
            }
        }
        else {
            for (auto [k1, v1]: w1) {
                for (auto [k2, v2]: w2) {
                    if (k1 == k2) continue;
                    if (v1 > 1) {
                        if (w2.count(k1)) {
                            if (v2 == 1 && !w1.count(k2)) return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};
// @lc code=end

