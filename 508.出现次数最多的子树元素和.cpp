/*
 * @lc app=leetcode.cn id=508 lang=cpp
 *
 * [508] 出现次数最多的子树元素和
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
    unordered_map<int, int> mapping;
    int calculateSum(TreeNode* root) {
        if (!root) return 0;
        int sum = calculateSum(root->left) + calculateSum(root->right) + root->val;
        mapping[sum]++;
        return sum;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        calculateSum(root);
        int maxNum = 0;
        vector<int> sums;
        for (auto kv : mapping) {
            if (kv.second > maxNum) {
                maxNum = kv.second;
                sums.clear();
                sums.push_back(kv.first);
            }
            else if (kv.second == maxNum) {
                sums.push_back(kv.first);
            }
        }
        return sums;
    }
};
// @lc code=end

