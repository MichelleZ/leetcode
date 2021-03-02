#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/search-in-a-binary-search-tree/
# Author: Miao Zhang
# Date:   2021-03-02

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def searchBST(self, root: TreeNode, val: int) -> TreeNode:
        if not root: return None
        if root.val == val: return root
        elif root.val > val: return self.searchBST(root.left, val)
        else: return self.searchBST(root.right, val)
