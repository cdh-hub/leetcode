/*
 * @lc app=leetcode.cn id=333 lang=cpp
 *
 * [333] 最大 BST 子树
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
    int maxnum = 0;
    bool helper(TreeNode* root, int& left, int& right, int& nums) {
        if (!root) return true;
        if (!root->left && !root->right) {
            left = root->val;
            right = root->val;
            nums = 1;
            maxnum = max(maxnum, nums);
            return true;
        }
        if (!root->left) {
            left = root->val;
            int left1;
            if (helper(root->right, left1, right, nums) && root->val < left1) {
                nums += 1;
                maxnum = max(maxnum, nums);
                return true;
            }
            else {
                nums += 1;
                return false;
            }
        }
        if (!root->right) {
            right = root->val;
            int right1;
            if (helper(root->left, left, right1, nums) && root->val > right1) {
                nums += 1;
                maxnum = max(maxnum, nums);
                return true;
            }
            else {
                nums += 1;
                return false;
            }
        }
        int left1, right1, nums1, nums2;
        bool l = helper(root->left, left, right1, nums1);
        bool r = helper(root->right, left1, right, nums2);
        nums = nums1 + nums2 + 1;
        if (l && r && root->val > right1 && root->val < left1) {
            maxnum = max(maxnum, nums);
            return true;
        }
        return false;
    }
public:
    int largestBSTSubtree(TreeNode* root) {
        int left, right, nums;
        helper(root, left, right, nums);
        return maxnum;
    }
};
// @lc code=end

