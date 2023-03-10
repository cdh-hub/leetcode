/*
 * @lc app=leetcode.cn id=173 lang=cpp
 *
 * [173] 二叉搜索树迭代器
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
class BSTIterator {
private:
    vector<TreeNode*> nodes;
    vector<TreeNode*>::iterator iter;
    void inorderTraversal(TreeNode* root) {
        if (root == nullptr) return;
        if (root->left) inorderTraversal(root->left);
        nodes.push_back(root);
        if (root->right) inorderTraversal(root->right);
    }
public:
    BSTIterator(TreeNode* root) {
        nodes.push_back(new TreeNode(-1));
        inorderTraversal(root);
        iter = nodes.begin();
    }
    
    int next() {
        iter++;
        return (*iter)->val;
    }
    
    bool hasNext() {
        return iter+1 != nodes.end();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

