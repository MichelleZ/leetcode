#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/chalkboard-xor-game/
# Author: Miao Zhang
# Date:   2021-03-13

class Solution:
    def xorGame(self, nums: List[int]) -> bool:
        if len(nums) % 2 == 0: return True
        x = 0
        for num in nums:
            x ^= num
        return x == 0
