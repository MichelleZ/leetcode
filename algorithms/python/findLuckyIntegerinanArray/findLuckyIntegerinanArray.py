#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/find-lucky-integer-in-an-array/
# Author: Miao Zhang
# Date:   2021-04-29

class Solution:
    def findLucky(self, arr: List[int]) -> int:
        cnt = collections.Counter(arr)
        res = -1
        for k, v in cnt.items():
            if k == v:
                res = max(res, k)
        return res
