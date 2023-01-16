/*
 * @lc app=leetcode.cn id=863 lang=cpp
 *
 * [863] 二叉树中所有距离为 K 的结点
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    unordered_map<TreeNode*, int> pathlen;
    vector<int> res;
    void dfs(TreeNode* root, TreeNode* target, int k, int& dist) {
        if (!root) return;
        if (root == target) {
            if (pathlen.count(root)) return;
            dist = 0;
        }
        if (root->left) {
            if (pathlen.count(root->left)) {
                dist = pathlen[root->left];
                dfs(root->left, target, k, dist);
                dist = pathlen[root];
            }
            else if (dist != -1) {
                dist += 1;
                dfs(root->left, target, k, dist);
                dist -= 1;
            }
            else {
                dfs(root->left, target, k, dist);
                if (dist != -1) dist += 1;
            }
        }
        if (root->right){
            if (pathlen.count(root->right)) {
                dist = pathlen[root->right];
                dfs(root->right, target, k, dist);
                dist = pathlen[root];
            }
            else if (dist != -1) {
                dist += 1;
                dfs(root->right, target, k, dist);
                dist -= 1;
            }
            else {
                dfs(root->right, target, k, dist);
                if (dist != -1) dist += 1;
            }
        }
        if (!pathlen.count(root) && dist != -1) {
            pathlen[root] = dist;
            if (dist == k) res.push_back(root->val);
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        int dist = -1;
        dfs(root, target, k, dist);
        dfs(root, target, k, dist);
        return res;
    }
};
// @lc code=end

