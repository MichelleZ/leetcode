#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/partition-array-into-disjoint-intervals/
# Author: Miao Zhang
# Date:   2021-03-24

class Solution:
    def partitionDisjoint(self, A: List[int]) -> int:
        leftmax = A[0]
        curmax = A[0]
        leftlen = 1
        for i in range(1, len(A)):
            if A[i] < leftmax:
                leftmax = curmax
                leftlen = i + 1
            else:
                curmax = max(curmax, A[i])
        return leftlen
