#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/n-ary-tree-preorder-traversal/
# Author: Miao Zhang
# Date:   2021-02-23

"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def preorder(self, root: 'Node') -> List[int]:
        res = []
        self.pre(root, res)
        return res

    def pre(self, root: 'Node', res: List[int]):
        if not root: return;
        res.append(root.val)
        for ch in root.children:
            self.pre(ch, res)

class Solution:
    def preorder(self, root: 'Node') -> List[int]:
        res = []
        if not root: return res
        stack = []
        stack.append(root)
        while stack:
            node = stack.pop()
            res.append(node.val)
            stack.extend(node.children[::-1])
        return res
