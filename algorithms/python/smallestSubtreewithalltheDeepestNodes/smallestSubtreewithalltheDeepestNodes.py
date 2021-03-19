#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/
# Author: Miao Zhang
# Date:   2021-03-19

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def subtreeWithAllDeepest(self, root: TreeNode) -> TreeNode:
        def depth(root):
            if not root: return (-1, None)
            dl, sl = depth(root.left)
            dr, sr = depth(root.right)
            if dl == dr: return (dl + 1, root)
            return (dl + 1, sl) if dl > dr else (dr + 1, sr)
        return depth(root)[1]
