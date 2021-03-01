#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/24-game/
# Author: Miao Zhang
# Date:   2021-02-28

class Solution:
    def judgePoint24(self, nums: List[int]) -> bool:
        self.TARGET = 24
        self.EPS = 1e-6
        self.ADD, self.MULTIPLY, self.SUBTRACT, self.DIVIDE = 0, 1, 2, 3
        return self.solve(nums)

    def solve(self, nums: List[float]) -> bool:
        if not nums: return False
        if len(nums) == 1: return abs(nums[0] - self.TARGET) < self.EPS
        for i, x in enumerate(nums):
            for j, y in enumerate(nums):
                if i == j: continue
                t = []
                for k, z in enumerate(nums):
                    if k != i and k != j:
                        t.append(z)
                for op in range(4):
                    if op < 2 and i > j: continue
                    if op == self.ADD:
                        t.append(x + y)
                    elif op == self.MULTIPLY:
                        t.append(x * y)
                    elif op == self.SUBTRACT:
                        t.append(x - y)
                    elif op == self.DIVIDE:
                        if abs(y) < self.EPS: continue
                        t.append(x / y)
                    if self.solve(t): return True
                    t.pop()
        return False
