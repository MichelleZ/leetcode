#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/arranging-coins/
# Author: Miao Zhang
# Date:   2021-02-11

class Solution:
    def arrangeCoins(self, n: int) -> int:
        level = 0
        cnt = 0
        while cnt + level + 1 <= n:
            level += 1
            cnt += level
        return level
