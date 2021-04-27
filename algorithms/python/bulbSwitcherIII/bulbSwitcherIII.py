#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/bulb-switcher-iii/
# Author: Miao Zhang
# Date:   2021-04-27

class Solution:
    def numTimesAllBlue(self, light: List[int]) -> int:
        res = 0
        right = 0
        for i in range(len(light)):
            right = max(right, light[i])
            res += right == i + 1
        return res
