/*
 * @lc app=leetcode.cn id=536 lang=cpp
 *
 * [536] 从字符串生成二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int parseInt(string& s, int& pos) {
        bool tag = false;
        if (s[pos] == '-') {
            tag = true;
            pos++;
        }
        int num = 0;
        while (pos < s.size() && s[pos] != '(' && s[pos] != ')') {
            num = 10 * num + (s[pos] - '0');
            pos++;
        }
        return tag ? (-num) : num;
    }
    TreeNode* helper(string& s, int& pos) {
        if (pos == s.size()) return nullptr;
        int rVal = parseInt(s, pos);
        if (pos < s.size() && s[pos] == '(') {
            pos++;
            TreeNode* l = helper(s, pos);
            if (pos < s.size() && s[pos] == '(') {
                pos++;
                TreeNode* r = helper(s, pos);
                if (pos < s.size()) pos++;
                return new TreeNode(rVal, l, r);
            }
            else {
                if (pos < s.size()) pos++;
                return new TreeNode(rVal, l, nullptr);
            }
        }
        else {
            if (pos < s.size()) pos++;
            return new TreeNode(rVal);
        }
    }
public:
    TreeNode* str2tree(string s) {
        int pos = 0;
        return helper(s, pos);
    }
};
// @lc code=end

