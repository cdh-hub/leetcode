/*
 * @lc app=leetcode.cn id=663 lang=cpp
 *
 * [663] 均匀树划分
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
    vector<int> vec;
    int sum(TreeNode* root) {
        if (!root) return 0;
        int thisSum = sum(root->left) + sum(root->right) + root->val;
        vec.push_back(thisSum);
        return thisSum;
    }
public:
    bool checkEqualTree(TreeNode* root) {
        sum(root);
        for (int i = 0; i < vec.size() - 1; i++) {
            if (vec[i] * 2 == *(vec.end() - 1)) return true;
        }
        return false;
    }
};
// @lc code=end

