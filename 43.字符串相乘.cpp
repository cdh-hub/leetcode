// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem43.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */

// @lc code=start
class Solution {
private:
    string add(string num1, string num2) {
        if (num1.size() > num2.size()) swap(num1, num2);
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string ans;
        int r = 0, i = 0;
        while (i < num1.size()) {
            int sum = (num1[i] - '0') + (num2[i] - '0') + r;
            if (sum >= 10) {
                r = 1;
                sum = sum % 10;
            }
            else r = 0;
            ans.push_back('0' + sum);
            i++;
        }
        while (i < num2.size()) {
            int sum = (num2[i] - '0') + r;
            if (sum >= 10) {
                r = 1;
                sum = sum % 10;
            }
            else r = 0;
            ans.push_back('0' + sum);
            i++;
        }
        if (r == 1) ans.push_back('1');
        reverse(ans.begin(), ans.end());
        return ans;
    }
    string helper(string num1, int num2) {
        reverse(num1.begin(), num1.end());
        int r = 0, i = 0;
        string ans;
        while (i < num1.size()) {
            int mul = (num1[i] - '0') * num2 + r;
            r = mul / 10;
            ans.push_back('0' + (mul % 10));
            i++;
        }
        if (r > 0) ans.push_back('0' + r);
        reverse(ans.begin(), ans.end());
        return ans;
    }
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        if (num1.size() > num2.size()) swap(num1, num2);
        string ans;
        for (int i = num1.size()-1; i >= 0; i--) {
            string s = helper(num2, num1[i] - '0');
            for (int j = 0; j < num1.size()-1-i; j++) s.push_back('0');
            ans = add(ans, s);
        }
        return ans;
    }
};
// @lc code=end

