#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/
# Author: Miao Zhang
# Date:   2021-05-13

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def countPairs(self, root: TreeNode, distance: int) -> int:
        self.res = 0
        self.dfs(root, distance)
        return self.res
    
    def dfs(self, root: TreeNode, distance: int) -> List[int]:
        if not root: return []
        if not root.left and not root.right: return [0]
        ret = []
        left = self.dfs(root.left, distance)
        for i in range(len(left)):
            left[i] += 1
            if left[i] > distance: continue
            ret.append(left[i])
        right = self.dfs(root.right, distance)
        for i in range(len(right)):
            right[i] += 1
            if right[i] > distance: continue
            ret.append(right[i])
        for l in left:
            for r in right:
                if l + r <= distance:
                    self.res += 1
        return ret
