/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
    vector<int> mode;
    int maxNum = 0;
    void inorder(TreeNode* root, int& curVal, int& curNum) {
        if (!root) return;
        inorder(root->left, curVal, curNum);
        if (root->val == curVal) {
            curNum++;
        }
        else {
            if (curNum > maxNum) {
                maxNum = curNum;
                mode.clear();
                mode.push_back(curVal);
            }
            else if (curNum == maxNum) {
                mode.push_back(curVal);
            }
            curNum = 1;
            curVal = root->val;
        }
        inorder(root->right, curVal, curNum);
    }
public:
    vector<int> findMode(TreeNode* root) {
        int curVal = -100001, curNum = -1;
        inorder(root, curVal, curNum);
        if (curNum > maxNum) {
            mode.clear();
            mode.push_back(curVal);
        }
        else if (curNum == maxNum) {
            mode.push_back(curVal);
        }
        return mode;
    }
};
// @lc code=end

