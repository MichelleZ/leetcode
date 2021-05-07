#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/
# Author: Miao Zhang
# Date:   2021-05-07

class Solution:
    def kLengthApart(self, nums: List[int], k: int) -> bool:
        d = k + 1
        for n in nums:
            if n == 0:
                d += 1
            else:
                if d < k: return False
                d = 0
        return True
