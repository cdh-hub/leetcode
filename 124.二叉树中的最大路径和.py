#
# @lc app=leetcode.cn id=124 lang=python3
#
# [124] 二叉树中的最大路径和
#

# @lc code=start
# Definition for a binary tree node.
from typing import List, Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def helper(self, root: Optional[TreeNode]) -> List[int]:
        if root == None:
            return [0, 0]
        l = self.helper(root.left)
        r = self.helper(root.right)
        longestPath1 = max(l[0], r[0], 0) + root.val
        if root.left == None and root.right == None:
            longestPath2 = root.val
        elif root.left == None:
            longestPath2 = max(longestPath1, r[1])
        elif root.right == None:
            longestPath2 = max(longestPath1, l[1])
        else:
            longestPath2 = max(l[1], r[1], max(0, l[0]) + max(0, r[0]) + root.val)
        return [longestPath1, longestPath2]
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        ans = self.helper(root)
        return ans[1]
# @lc code=end

