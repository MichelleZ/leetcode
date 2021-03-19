#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
# Author: Miao Zhang
# Date:   2021-03-19

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def distanceK(self, root: TreeNode, target: TreeNode, K: int) -> List[int]:
        def dfs(node, par = None):
            if node:
                node.par = par
                dfs(node.left, node)
                dfs(node.right, node)
        
        dfs(root)
        q = collections.deque([(target , 0)])
        seen = {target}
        while q:
            if q[0][1] == K:
                return [node.val for node, d in q]
            node, d = q.popleft()
            for nxt in (node.left, node.right, node.par):
                if nxt and nxt not in seen:
                    seen.add(nxt)
                    q.append((nxt, d + 1))
        return []
