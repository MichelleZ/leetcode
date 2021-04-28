#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/balance-a-binary-search-tree/
# Author: Miao Zhang
# Date:   2021-04-28

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def balanceBST(self, root: TreeNode) -> TreeNode:
        self.res = []
        def inorder(root):
            if not root: return
            inorder(root.left)
            self.res.append(root.val)
            inorder(root.right)
        def build(nums):
            if not nums: return None
            idx = len(nums) // 2
            root = TreeNode(nums[idx])
            root.left = build(nums[: idx])
            root.right = build(nums[idx + 1:])
            return root
        inorder(root)
        return build(self.res)
