#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/reducing-dishes/
# Author: Miao Zhang
# Date:   2021-04-29

class Solution:
    def maxSatisfaction(self, satisfaction: List[int]) -> int:
        satisfaction.sort(reverse=True)
        presum = 0
        res = 0
        for s in satisfaction:
            if presum + s > 0:
                presum += s
                res += presum
            else:
                break
        return res
