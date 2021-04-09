#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/delete-nodes-and-return-forest/
# Author: Miao Zhang
# Date:   2021-04-09

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def delNodes(self, root: TreeNode, to_delete: List[int]) -> List[TreeNode]:
        res = []
        de = set(to_delete)
        
        def process(root):
            if not root: return None
            root.left, root.right = process(root.left), process(root.right)
            if root.val not in de: return root
            if root.left: res.append(root.left)
            if root.right: res.append(root.right)
        
        root = process(root)
        if root: res.append(root)
        return res
