#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/find-positive-integer-solution-for-a-given-equation/
# Author: Miao Zhang
# Date:   2021-04-19

"""
   This is the custom function interface.
   You should not implement it, or speculate about its implementation
   class CustomFunction:
       # Returns f(x, y) for any given positive integers x and y.
       # Note that f(x, y) is increasing with respect to both x and y.
       # i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
       def f(self, x, y):
  
"""

class Solution:
    def findSolution(self, customfunction: 'CustomFunction', z: int) -> List[List[int]]:
        res = []
        for x in range(1, 1001):
            if customfunction.f(x, 1) > z: break
            l, r = 1, 1001
            while l < r:
                m = l + (r - l) // 2
                t = customfunction.f(x, m)
                if t > z:
                    r = m
                elif t < z:
                    l = m + 1
                else:
                    res.append([x, m])
                    break
        return res
                
