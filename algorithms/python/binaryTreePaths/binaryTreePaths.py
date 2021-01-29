#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/binary-tree-paths/
# Author: Miao Zhang
# Date:   2021-01-29

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def binaryTreePaths(self, root: TreeNode) -> List[str]:
        res = []
        self.dfs(root, '', res)
        return res
    
    def dfs(self, node: TreeNode, path: str, res: List[str]) -> None:
        if not node: return
        if not node.left and not node.right:
            res.append(path + str(node.val))
            return
        if node.left:
            self.dfs(node.left, path + str(node.val) + '->', res)
        if node.right:
            self.dfs(node.right, path + str(node.val) + '->', res)
