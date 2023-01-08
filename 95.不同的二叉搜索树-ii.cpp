/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
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
public:
    vector<TreeNode*> generateTrees(int n) {
        return build(1, n);
    }

    vector<TreeNode*> build(int l, int r) {
        vector<TreeNode*> trees;
        if (l > r) return trees;
        for (int i = l; i <= r; i++) {
            vector<TreeNode*> leftTrees = build(l, i-1);
            vector<TreeNode*> rightTrees = build(i+1, r);
            if (leftTrees.size() == 0) {
                if (rightTrees.size() == 0) {
                    TreeNode* tree = new TreeNode(i);
                    tree->left = nullptr;
                    tree->right = nullptr;
                    trees.push_back(tree);
                }
                else for (auto k = rightTrees.begin(); k < rightTrees.end(); k++) {
                    TreeNode* tree = new TreeNode(i);
                    tree->left = nullptr;
                    tree->right = *k;
                    trees.push_back(tree);
                }
            }
            else for (auto j = leftTrees.begin(); j < leftTrees.end(); j++) {
                if (rightTrees.size() == 0) {
                    TreeNode* tree = new TreeNode(i);
                    tree->left = *j;
                    tree->right = nullptr;
                    trees.push_back(tree);
                }
                for (auto k = rightTrees.begin(); k < rightTrees.end(); k++) {
                    TreeNode* tree = new TreeNode(i);
                    tree->left = *j;
                    tree->right = *k;
                    trees.push_back(tree);
                }
            }
            
        }
        return trees;
    }
};
// @lc code=end

