#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/
# Author: Miao Zhang
# Date:   2021-03-22

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def constructFromPrePost(self, pre: List[int], post: List[int]) -> TreeNode:
        if not pre and not post: return None
        if pre[0] == post[0]: return TreeNode(pre[0])
        val = pre[0]
        root = TreeNode(val)
        idx = post.index(pre[1])
        root.left = self.constructFromPrePost(pre[1: 2 + idx], post[:idx + 1])
        root.right = self.constructFromPrePost(pre[idx + 2:], post[idx + 1: -1])
        return root
