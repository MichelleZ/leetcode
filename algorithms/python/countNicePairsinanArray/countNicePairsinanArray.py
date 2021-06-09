#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/count-nice-pairs-in-an-array/
# Author: Miao Zhang
# Date:   2021-06-09

class Solution:
    def countNicePairs(self, nums: List[int]) -> int:
        kMod = 10 ** 9 + 7
        m = collections.defaultdict(int)
        res = 0
        for num in nums:
            s = str(num)[::-1]
            res += m[num - int(s)]
            m[num - int(s)] += 1
        return res % kMod
