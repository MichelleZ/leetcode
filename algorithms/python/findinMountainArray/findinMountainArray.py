#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/find-in-mountain-array/
# Author: Miao Zhang
# Date:   2021-04-08

# """
# This is MountainArray's API interface.
# You should not implement it, or speculate about its implementation
# """
#class MountainArray:
#    def get(self, index: int) -> int:
#    def length(self) -> int:

class Solution:
    def findInMountainArray(self, target: int, mountain_arr: 'MountainArray') -> int:
        def binarySearch(l, r, cond):
            while l < r:
                m = l + (r - l) // 2
                if cond(m):
                    r = m
                else:
                    l = m + 1
            return l

        n = mountain_arr.length()
        p = binarySearch(0, n - 1, lambda i: mountain_arr.get(i) > mountain_arr.get(i + 1))
        l = binarySearch(0, p, lambda i: mountain_arr.get(i) >= target)
        if mountain_arr.get(l) == target: return l
        r = binarySearch(p, n - 1, lambda i: mountain_arr.get(i) <= target)
        if mountain_arr.get(r) == target: return r
        return -1
