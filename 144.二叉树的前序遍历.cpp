/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    vector<int> preorderTraversal(TreeNode* root) {
        
        /* 递归
        vector<int> res;
        if (root == nullptr) return res;
        res.push_back(root->val);
        vector<int> leftTraversal = preorderTraversal(root->left);
        res.insert(res.end(), leftTraversal.begin(), leftTraversal.end());
        vector<int> rightTraversal = preorderTraversal(root->right);
        res.insert(res.end(), rightTraversal.begin(), rightTraversal.end());
        return res;
        */
        
        /* 迭代
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode* p = root;
        while (p) {
            res.push_back(p->val);
            stk.push(p);
            p = p->left;
        }
        while (!stk.empty()) {
            p = stk.top()->right;
            stk.pop();
            while (p) {
                res.push_back(p->val);
                stk.push(p);
                p = p->left;
            }
        }
        return res;
        */
        
        // Morris
        vector<int> res;
        TreeNode *p1 = root, *p2 = nullptr;
        while (p1) {
            if (p1->left == nullptr) {
                res.push_back(p1->val);
                p1 = p1->right;
            }
            else {
                p2 = p1->left;
                while (p2->right && p2->right != p1) {
                    p2 = p2->right;
                }
                if (p2->right == nullptr) {
                    p2->right = p1;
                    res.push_back(p1->val);
                    p1 = p1->left;
                }
                else {
                    p2->right = nullptr;
                    p1 = p1->right;
                }
            }
        }
        return res;
    }
};
// @lc code=end

