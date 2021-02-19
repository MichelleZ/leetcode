#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/most-frequent-subtree-sum/
# Author: Miao Zhang
# Date:   2021-02-19

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findFrequentTreeSum(self, root: TreeNode) -> List[int]:
        if not root: return []
        vals = []
        self.getSums(root, vals)
        counter = collections.Counter(vals)
        freq = counter.most_common()
        maxfreq = freq[0][1]
        return [v for v, c in freq if c == maxfreq]
    
    def getSums(self, root: TreeNode, vals: List[int]) -> None:
        if not root: return 0
        s = root.val + self.getSums(root.left, vals) + self.getSums(root.right, vals)
        vals.append(s)
        return s
