/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    vector<int> postorderTraversal(TreeNode* root) {
        /* 递归
        vector<int> res;
        if (root == nullptr) return res;
        vector<int> leftTraversal = postorderTraversal(root->left);
        vector<int> rightTraversal = postorderTraversal(root->right);
        res.insert(res.end(), leftTraversal.begin(), leftTraversal.end());
        res.insert(res.end(), rightTraversal.begin(), rightTraversal.end());
        res.push_back(root->val);
        return res;
        */
    
        /*迭代
        vector<int> res;
        stack<TreeNode*> stk;
        if (root == nullptr) return res;
        stk.push(root);
        while (!stk.empty()) {
            while (stk.top()->left || stk.top()->right) {
                if (stk.top()->left) {
                    stk.push(stk.top()->left);
                }
                else {
                    stk.push(stk.top()->right);
                }
            }
            TreeNode* p = stk.top();
            stk.pop();
            res.push_back(p->val);
            while (!stk.empty() && (stk.top()->left != p || stk.top()->right == nullptr)) {
                p = stk.top();
                stk.pop();
                res.push_back(p->val);
            }
            if (!stk.empty()) {
                stk.push(stk.top()->right);
            }
        }
        return res;
        */
        
        // Morris
        vector<int> res;
        TreeNode *p1 = root, *p2 = nullptr;
        while (p1) {
            if (p1->left) {
                p2 = p1->left;
                while (p2->right && p2->right != p1) {
                    p2 = p2->right;
                }
                if (p2->right == nullptr) {
                    p2->right = p1;
                    p1 = p1->left;
                }
                else {
                    p2->right = nullptr;
                    p2 = p1->left;
                    int count = 0;
                    while (p2) {
                        count++;
                        res.push_back(p2->val);
                        p2 = p2->right;
                    }
                    reverse(res.end()-count, res.end());
                    p1 = p1->right;
                }
            }
            else {
                p1 = p1->right;
            }
        }
        p2 = root;
        int count = 0;
        while (p2) {
            count++;
            res.push_back(p2->val);
            p2 = p2->right;
        }
        reverse(res.end() - count, res.end());
        return res;
    }
};
// @lc code=end

