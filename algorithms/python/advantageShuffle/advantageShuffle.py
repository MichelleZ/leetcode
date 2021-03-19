#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/advantage-shuffle/
# Author: Miao Zhang
# Date:   2021-03-19

class Solution:
    def advantageCount(self, A: List[int], B: List[int]) -> List[int]:
        A.sort()
        res = []
        for b in B:
            idx = bisect.bisect_right(A, b)
            if idx == len(A): idx = 0
            res.append(A[idx])
            A.pop(idx)
        return res
