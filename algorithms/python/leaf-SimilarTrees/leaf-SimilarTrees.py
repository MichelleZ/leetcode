#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/leaf-similar-trees/
# Author: Miao Zhang
# Date:   2021-03-20

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def leafSimilar(self, root1: TreeNode, root2: TreeNode) -> bool:
        def getLeafs(root):
            if not root: return []
            if not root.left and not root.right: return [root.val]
            return getLeafs(root.left) + getLeafs(root.right)
        
        return getLeafs(root1) == getLeafs(root2)
