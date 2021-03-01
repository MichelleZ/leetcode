#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/baseball-game/
# Author: Miao Zhang
# Date:   2021-03-01

class Solution:
    def calPoints(self, ops: List[str]) -> int:
        nums = []
        for op in ops:
            if op == '+': nums.append(nums[-1] + nums[-2])
            elif op == 'C': nums.pop()
            elif op == 'D': nums.append(nums[-1] * 2)
            else: nums.append(int(op))
        return sum(nums)
