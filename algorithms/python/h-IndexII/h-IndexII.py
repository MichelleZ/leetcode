#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/h-index-ii/
# Author: Miao Zhang
# Date:   2021-01-29

class Solution:
    def hIndex(self, citations: List[int]) -> int:
        n = len(citations)
        l = 0
        r = n - 1
        res =0
        while l <= r:
            mid = (l + r) // 2
            cnt = n - mid
            if citations[mid] >= cnt:
                res = cnt
                r = mid - 1
            else:
                l = mid + 1
        return res
