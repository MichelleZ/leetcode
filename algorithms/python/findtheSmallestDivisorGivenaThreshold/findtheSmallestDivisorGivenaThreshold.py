#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
# Author: Miao Zhang
# Date:   2021-04-21

class Solution:
    def smallestDivisor(self, nums: List[int], threshold: int) -> int:
        def sums(d):
            s = 0
            for n in nums:
                s += (n + (d - 1)) // d
            return s
        l = 1
        r = 10 ** 6
        while l < r:
            m = l + (r - l) // 2
            if sums(m) <= threshold:
                r = m
            else:
                l = m + 1
        return l
        
