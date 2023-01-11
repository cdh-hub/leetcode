/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
    pair<int, int> helper(TreeNode* root) {
        if (!root) return make_pair(0, 0);
        if (!root->left && !root->right) return make_pair(1, root->val);
        pair<int, int> l = helper(root->left);
        pair<int, int> r = helper(root->right);
        return l.first >= r.first ? make_pair(l.first+1, l.second) : make_pair(r.first+1, r.second);
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        return helper(root).second;          
    }
};
// @lc code=end

