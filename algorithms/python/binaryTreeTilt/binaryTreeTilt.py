#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/binary-tree-tilt/
# Author: Miao Zhang
# Date:   2021-02-22

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findTilt(self, root: TreeNode) -> int:
        self.res = 0
        self.postorder(root)
        return self.res

    def postorder(self, root: TreeNode) -> int:
        if not root:
            return 0
        leftsum = self.postorder(root.left)
        rightsum = self.postorder(root.right)
        self.res += abs(leftsum - rightsum)
        return leftsum + rightsum + root.val
