/*
 * @lc app=leetcode.cn id=653 lang=cpp
 *
 * [653] 两数之和 IV - 输入二叉搜索树
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
    vector<int> vals;
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        vals.emplace_back(root->val);
        inorder(root->right);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        inorder(root);
        int ptr1 = 0, ptr2 = vals.size() - 1;
        while (ptr1 != ptr2) {
            if (vals[ptr1] + vals[ptr2] == k) return true;
            if (vals[ptr1] + vals[ptr2] < k) ptr1++;
            else ptr2--;
        }
        return false;
    }
};
// @lc code=end

