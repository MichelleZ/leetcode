#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
# Author: Miao Zhang
# Date:   2021-02-05

class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        l = matrix[0][0]
        r = matrix[-1][-1]
        while l < r:
            mid = (l + r) // 2;
            c = sum(bisect.bisect_right(row, mid) for row in matrix)
            if c < k:
                l = mid + 1
            else:
                r = mid
        return l
