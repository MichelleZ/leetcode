#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/image-overlap/
# Author: Miao Zhang
# Date:   2021-03-16

class Solution:
    def largestOverlap(self, img1: List[List[int]], img2: List[List[int]]) -> int:
        n = len(img1)
        la = [(i, j) for i in range(n) for j in range(n) if img1[i][j]]
        lb = [(i, j) for i in range(n) for j in range(n) if img2[i][j]]
        cnt = collections.Counter([(xa - xb, ya - yb) for (xa, ya) in la for (xb, yb) in lb])
        return max(cnt.values()) if cnt else 0
