#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/jump-game/
# Author: Miao Zhang
# Date:   2021-01-12

class Solution:
    def canJump(self, nums: List[int]) -> bool:
        max_jump = 0
        for i in range(len(nums)):
            if i > max_jump:
                return False
            max_jump = max(max_jump, i + nums[i])
        
        if max_jump >= len(nums) - 1:
            return True
        return False
