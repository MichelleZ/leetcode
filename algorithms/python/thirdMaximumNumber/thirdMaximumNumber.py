#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/third-maximum-number/
# Author: Miao Zhang
# Date:   2021-02-09

class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        s = set()
        for n in nums:
            s.add(n)
            if len(s) > 3: s.remove(min(s))
        return min(s) if len(s) == 3 else max(s)
