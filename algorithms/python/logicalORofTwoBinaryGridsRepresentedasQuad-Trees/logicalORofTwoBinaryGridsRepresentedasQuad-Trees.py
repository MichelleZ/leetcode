#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/logical-or-of-two-binary-grids-represented-as-quad-trees/
# Author: Miao Zhang
# Date:   2021-02-22

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
    def intersect(self, quadTree1: 'Node', quadTree2: 'Node') -> 'Node':
        if quadTree1.isLeaf:
            return quadTree1 if quadTree1.val else quadTree2
        if quadTree2.isLeaf:
            return quadTree2 if quadTree2.val else quadTree1
        
        tl = self.intersect(quadTree1.topLeft, quadTree2.topLeft)
        tr = self.intersect(quadTree1.topRight, quadTree2.topRight)
        bl = self.intersect(quadTree1.bottomLeft, quadTree2.bottomLeft)
        br = self.intersect(quadTree1.bottomRight, quadTree2.bottomRight)
        
        if tl.val == tr.val and tl.val == bl.val and tl.val == br.val and tl.isLeaf and tr.isLeaf and bl.isLeaf and br.isLeaf:
            return Node(tl.val, True, None, None, None, None)
        else:
            return Node(0, False, tl, tr, bl, br)
