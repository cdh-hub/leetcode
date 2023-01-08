/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    vector<int> preorder, inorder;
    TreeNode* helper(int pl, int pr, int il, int ir) {
        if (pl > pr) return nullptr;
        TreeNode* root = new TreeNode(preorder[pl]);
        for (int i = il; i <= ir; i++) {
            if (inorder[i] == preorder[pl]) {
                root->left = helper(pl+1, pl+i-il, il, i-1);
                root->right = helper(pl+i-il+1, pr, i+1, ir);
                break;
            }
        }
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->preorder = preorder;
        this->inorder = inorder;
        return helper(0, preorder.size()-1, 0, inorder.size()-1);
    }
};
// @lc code=end

