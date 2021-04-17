#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position/
# Author: Miao Zhang
# Date:   2021-04-17

class Solution:
    def minCostToMoveChips(self, position: List[int]) -> int:
        odd = 0
        even = 0
        for p in position:
            if p % 2:
                odd += 1
            else:
                even += 1
        return min(odd, even)
