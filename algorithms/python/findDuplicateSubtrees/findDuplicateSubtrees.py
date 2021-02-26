#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/find-duplicate-subtrees/
# Author: Miao Zhang
# Date:   2021-02-26

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findDuplicateSubtrees(self, root: TreeNode) -> List[TreeNode]:
        cnts = collections.defaultdict(int)
        res = []
        self.serialize(root, cnts, res)
        return res
    
    def serialize(self, root: TreeNode, cnts: defaultdict, res: List[TreeNode]) -> str:
        if not root: return '#'
        key = str(root.val) + ',' \
              + self.serialize(root.left, cnts, res) + ',' \
              + self.serialize(root.right, cnts, res)
        cnts[key] += 1
        if cnts[key] == 2: res.append(root)
        return key
