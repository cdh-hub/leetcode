/*
 * @lc app=leetcode.cn id=1145 lang=java
 *
 * [1145] 二叉树着色游戏
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
    int leftNum = 0, rightNum = 0;
    private int helper(TreeNode root, int x) {
        if (root == null) return 0;
        int l = helper(root.left, x), r = helper(root.right, x);
        if (root.val == x) {
            leftNum = l;
            rightNum = r;
        }
        return l + r + 1;
    }
    public boolean btreeGameWinningMove(TreeNode root, int n, int x) {
        helper(root, x);
        return n > 2 * (leftNum + rightNum + 1) || n < 2 * leftNum || n < 2 * rightNum;
    }
}
// @lc code=end

