#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
# Author: Miao Zhang
# Date:   2021-01-18

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []
        queue = [root]
        res = []
        flag = 1
        while queue:
            tmplist = []
            for _ in range(len(queue)):
                node = queue.pop(0)
                tmplist.append(node.val)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            if flag == -1:
                tmplist = tmplist[::-1]
            res.append(tmplist)
            flag *= -1
        return res
