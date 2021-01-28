#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/kth-smallest-element-in-a-bst/
# Author: Miao Zhang
# Date:   2021-01-28

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        self.res = []
        self.count = k
        def inorder(root):
            if root:
                inorder(root.left)
                self.count -= 1
                if not self.count:
                    self.res = root.val
                    return
                inorder(root.right)
        
        inorder(root)
        return self.res
