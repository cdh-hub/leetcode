/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
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
    int targetSum;
    unordered_map<long long, int> prefixSum;
    int dfs(TreeNode* root, long long cur) {
        if (!root) return 0;
        cur += root->val;
        int res = 0;
        if (prefixSum.count(cur - targetSum)) {
            res += prefixSum[cur - targetSum];
        }
        prefixSum[cur]++;
        res += dfs(root->left, cur);
        res += dfs(root->right, cur);
        prefixSum[cur]--;
        return res;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        this->targetSum = targetSum;
        prefixSum[0] = 1;
        return dfs(root, 0);
    }
};
// @lc code=end

