#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/jump-game-ii/
# Author: Miao Zhang
# Date:   2021-01-12

class Solution:
    def jump(self, nums: List[int]) -> int:
        '''
        cur the farthest distance
        pos step by step
        '''
        n = len(nums)
        cur = 0
        pos = 0
        step = 0
        while cur < n - 1:
            step += 1
            pre = cur
            while pos <= pre:
                cur = max(cur, pos + nums[pos])
                pos += 1
        return step
