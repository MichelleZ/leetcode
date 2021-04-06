#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/moving-stones-until-consecutive-ii/
# Author: Miao Zhang
# Date:   2021-04-06

class Solution:
    def numMovesStonesII(self, stones: List[int]) -> List[int]:
        stones.sort()
        n = len(stones)
        i = 0
        low = n
        for j in range(n):
            while stones[j] - stones[i] + 1 > n:
                i += 1
            if j - i + 1 == n - 1 and stones[j] - stones[i] + 1 == n - 1:
                low = min(low, 2)
            else:
                low = min(low, n - (j - i + 1))
        return [low, max(stones[-1] - stones[1] - n + 2, stones[n-2] - stones[0] - n + 2)]
            
