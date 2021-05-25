#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/create-sorted-array-through-instructions/
# Author: Miao Zhang
# Date:   2021-05-25

class FenwickTree:
    def __init__(self, n):
        self.sums = [0 for _ in range(n + 1)]
    
    def update(self, i, delta):
        while i < len(self.sums):
            self.sums[i] += delta
            i += self.lowbit(i)
    
    def query(self, i):
        res = 0
        while i > 0:
            res += self.sums[i]
            i -= self.lowbit(i)
        return res
    
    def lowbit(self, x):
        return x & (-x)
    

class Solution:
    def createSortedArray(self, instructions: List[int]) -> int:
        n = len(instructions)
        kMod = 10 ** 9 + 7
        tree = FenwickTree(10 ** 5)
        res = 0
        for i in range(n):
            lt = tree.query(instructions[i] - 1)
            gt = i - tree.query(instructions[i])
            res += min(lt, gt)
            tree.update(instructions[i], 1)
        return res % kMod
