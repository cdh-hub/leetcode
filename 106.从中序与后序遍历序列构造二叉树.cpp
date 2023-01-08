/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty()) return nullptr;
        TreeNode *root = new TreeNode(postorder.back());
        for (auto iter = inorder.begin(), iterPost = postorder.begin(); iter != inorder.end(); iter++, iterPost++) {
            if (*iter == postorder.back()) {
                vector<int> inorderleft, postorderleft, inorderright, postorderright;
                inorderleft.assign(inorder.begin(), iter);
                postorderleft.assign(postorder.begin(), iterPost);
                inorderright.assign(iter+1, inorder.end());
                postorderright.assign(iterPost, postorder.end());
                postorderright.pop_back();
                root->left = buildTree(inorderleft, postorderleft);
                root->right = buildTree(inorderright, postorderright);
            }
        }
        return root;
    }
};
// @lc code=end

