#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/bulb-switcher-iv/
# Author: Miao Zhang
# Date:   2021-05-13

class Solution:
    def minFlips(self, target: str) -> int:
        res = 0
        cur = 0
        for t in target:
            if int(t) != cur:
                cur ^= 1
                res += 1
        return res
