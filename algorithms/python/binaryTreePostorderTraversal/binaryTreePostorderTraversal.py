#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/binary-tree-postorder-traversal/
# Author: Miao Zhang
# Date:   2021-01-21

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        res = []
        if not root:
            return res
        res += self.postorderTraversal(root.left)
        res += self.postorderTraversal(root.right)
        res.append(root.val)
        return res

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        '''
        left->right->root = reverse(root->right->left)
        '''
        res = []
        if not root:
            return res
        stack = []
        while stack or root:
            if root:
                res.append(root.val)
                stack.append(root)
                root = root.right
            else:
                root = stack.pop()
                root = root.left
        return res[::-1]
