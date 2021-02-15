#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/heaters/
# Author: Miao Zhang
# Date:   2021-02-15

class Solution:
    def findRadius(self, houses: List[int], heaters: List[int]) -> int:
        res = 0
        n = len(heaters)
        j = 0
        heaters.sort()
        houses.sort()
        for h in houses:
            while j < n - 1 and abs(heaters[j + 1] - h) <= abs(heaters[j] - h):
                j += 1
            res = max(res, abs(heaters[j] - h))
        return res
