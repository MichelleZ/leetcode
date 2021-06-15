#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-speed-to-arrive-on-time/
# Author: Miao Zhang
# Date:   2021-06-15

class Solution:
    def minSpeedOnTime(self, dist: List[int], hour: float) -> int:
        if hour <= len(dist) - 1:
            return -1
        l, r = 1, max(dist) * 100
        
        def cost(m):
            res = 0
            for i in dist[:-1]:
                res += (i + m - 1) // m
                if res > hour:
                    return True
            res += dist[-1] / m
            if res > hour: return True
            return False
                
        while l < r:
            mid = l + (r - l) // 2
            if cost(mid):
                l = mid + 1
            else:
                r = mid
        return -1 if l == 10 ** 9 else l
