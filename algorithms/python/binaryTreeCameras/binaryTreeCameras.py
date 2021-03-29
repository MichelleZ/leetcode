#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/binary-tree-cameras/
# Author: Miao Zhang
# Date:   2021-03-29

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from enum import Enum, unique

@unique
class State(Enum):
    NONE = 1
    COVERED = 2
    CAMERA = 3

class Solution:
    def __init__(self):
        self.res = 0
    
    def minCameraCover(self, root: TreeNode) -> int:
        if self.dfs(root) == State.NONE:
            self.res += 1
        return self.res
    
    def dfs(self, root: TreeNode) -> 'State':
        if not root: return State.COVERED
        l = self.dfs(root.left)
        r = self.dfs(root.right)
        if l == State.NONE or r == State.NONE:
            self.res += 1
            return State.CAMERA
        if l == State.CAMERA or r == State.CAMERA:
            return State.COVERED
        return State.NONE
