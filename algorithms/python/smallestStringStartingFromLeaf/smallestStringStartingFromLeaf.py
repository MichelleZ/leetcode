#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/smallest-string-starting-from-leaf/
# Author: Miao Zhang
# Date:   2021-03-31

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def smallestFromLeaf(self, root: TreeNode) -> str:
        self.res = '|'
        
        def dfs(node, a):
            if node:
                a.append(chr(node.val + ord('a')))
                if not node.left and not node.right:
                    self.res = min(self.res, ''.join(reversed(a)))
                dfs(node.left, a)
                dfs(node.right, a)
                a.pop()
        
        dfs(root, [])
        return self.res

