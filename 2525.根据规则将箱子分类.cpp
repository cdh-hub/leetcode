/*
 * @lc app=leetcode.cn id=2525 lang=cpp
 *
 * [2525] 根据规则将箱子分类
 */

// @lc code=start
class Solution {
private:
    bool isBulky(int l, int w, int h) {
        if (l >= 1e4) return true;
        if (w >= 1e4) return true;
        if (h >= 1e4) return true;
        long long mul = 1;
        if (mul*l*w*h >= 1e9) return true;
        return false;
    }
    bool isHeavy(int m) {
        return m >= 100;
    }
public:
    string categorizeBox(int length, int width, int height, int mass) {
        bool b = isBulky(length, width, height), h = isHeavy(mass);
        if (b && h) return "Both";
        if (!b && !h) return "Neither";
        return b ? "Bulky" : "Heavy";
    }
};
// @lc code=end

