#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/max-consecutive-ones/
# Author: Miao Zhang
# Date:   2021-02-15

class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        return len(max(''.join(map(str, nums)).split('0')))
