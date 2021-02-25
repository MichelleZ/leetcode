#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/add-one-row-to-tree/
# Author: Miao Zhang
# Date:   2021-02-25

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def addOneRow(self, root: TreeNode, v: int, d: int) -> TreeNode:
        if not root: return None
        if d == 1:
            newroot = TreeNode(v)
            newroot.left = root
            root = newroot
        elif d == 2:
            newleft = TreeNode(v)
            newright = TreeNode(v)
            newleft.left = root.left
            newright.right = root.right
            root.left = newleft
            root.right = newright
        else:
            self.addOneRow(root.left, v, d - 1)
            self.addOneRow(root.right, v, d - 1)
        return root
            
