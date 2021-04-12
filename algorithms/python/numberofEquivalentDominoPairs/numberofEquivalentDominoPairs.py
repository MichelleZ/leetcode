#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/number-of-equivalent-domino-pairs/
# Author: Miao Zhang
# Date:   2021-04-12

class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        num = [0] * 100
        res = 0
        for x, y in dominoes:
            val = (x * 10 + y if x <= y else y * 10 + x)
            res += num[val]
            num[val] += 1
        return res
