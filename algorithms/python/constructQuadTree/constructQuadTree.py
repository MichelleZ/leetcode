#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/construct-quad-tree/
# Author: Miao Zhang
# Date:   2021-02-10

"""
# Definition for a QuadTree node.
class Node:
    def __init__(self, val, isLeaf, topLeft, topRight, bottomLeft, bottomRight):
        self.val = val
        self.isLeaf = isLeaf
        self.topLeft = topLeft
        self.topRight = topRight
        self.bottomLeft = bottomLeft
        self.bottomRight = bottomRight
"""

class Solution:
    def construct(self, grid: List[List[int]]) -> 'Node':
        return self.cons(grid, 0, 0, len(grid))
    
    def cons(self, grid: List[List[int]], i: int, j: int, n: int) -> 'Node':
        if n == 0: return None
        if n == 1: return Node(grid[i][j], True, None, None, None, None)
        
        topleft = self.cons(grid, i, j, n // 2)
        topright = self.cons(grid, i, j + n // 2, n // 2)
        bottomleft = self.cons(grid, i + n // 2, j, n // 2)
        bottomright = self.cons(grid, i + n // 2, j + n // 2, n // 2)
        
        if topleft.isLeaf and topright.isLeaf and bottomleft.isLeaf and bottomright.isLeaf and topleft.val == topright.val and topleft.val == bottomleft.val and topleft.val == bottomright.val:
            return Node(topleft.val, True, None, None, None, None)
        return Node(True, False, topleft, topright, bottomleft, bottomright)
