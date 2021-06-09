#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/number-of-different-subsequences-gcds/
# Author: Miao Zhang
# Date:   2021-06-09

class Solution:
    def countDifferentSubsequenceGCDs(self, nums: List[int]) -> int:
        maxnum = max(nums)
        g = [False for _ in range(maxnum + 1)]
        for num in nums: g[num] = True
        res = 0
        for i in range(1, maxnum + 1):
            tmp = 0
            for j in range(i, maxnum + 1, i):
                if g[j] == True:
                    tmp = math.gcd(tmp, j)
            if tmp == i: res += 1
        return res
