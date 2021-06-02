#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/building-boxes/
# Author: Miao Zhang
# Date:   2021-06-02

class Solution:
    def minimumBoxes(self, n: int) -> int:
        level = 1
        cell = 0
        while cell + (1 + level) * level // 2 <= n:
            cell += (1 + level) * level // 2
            level += 1
        level -= 1
        area = (1 + level) * level // 2
        
        increase = 0
        while cell < n:
            area += 1
            cell += increase + 1
            increase += 1
        return area
