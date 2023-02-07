/*
 * @lc app=leetcode.cn id=2331 lang=java
 *
 * [2331] 计算布尔二叉树的值
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean evaluateTree(TreeNode root) {
        if (root.val == 0 || root.val == 1) return root.val == 0 ? false : true;
        if (root.val == 2) return evaluateTree(root.left) || evaluateTree(root.right);
        else return evaluateTree(root.left) && evaluateTree(root.right);
    }
}
// @lc code=end

