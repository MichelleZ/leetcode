#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/path-sum-ii/
# Author: Miao Zhang
# Date:   2021-01-19

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# bfs
class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        res = []
        q = deque()
        q.append((root, [], 0))
        while q:
            node, path, path_sum = q.popleft()
            if not node:
                continue
            if not node.left and not node.right:
                if path_sum + node.val == sum:
                    res.append(path + [node.val])
            q.append((node.left, path + [node.val], path_sum + node.val))
            q.append((node.right, path + [node.val], path_sum + node.val))
        return res

class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        res = []
        self.dfs(root, sum, res, [])
        return res
    
    def dfs(self, root: TreeNode, sum: int, res: List[List[int]], path: List[int]):
        if not root:
            return
        if root.val == sum and not root.left and not root.right:
            res.append(path + [root.val])
        self.dfs(root.left, sum - root.val, res, path + [root.val])
        self.dfs(root.right, sum - root.val, res, path + [root.val])
