#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/diagonal-traverse-ii/
# Author: Miao Zhang
# Date:   2021-05-06

class Solution:
    def findDiagonalOrder(self, nums: List[List[int]]) -> List[int]:
        m = []
        for i, r in enumerate(nums):
            for j, v in enumerate(r):
                if i + j >= len(m):
                    m.append([])
                m[i + j].append(v)
        return [v for d in m for v in reversed(d)]
