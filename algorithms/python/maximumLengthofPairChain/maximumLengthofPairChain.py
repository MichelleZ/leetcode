#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-length-of-pair-chain/
# Author: Miao Zhang
# Date:   2021-02-26

class Solution:
    def findLongestChain(self, pairs: List[List[int]]) -> int:
        cur, res = float('-inf'), 0
        pairs.sort(key = lambda x: x[1])
        for s, e in pairs:
            if cur < s:
                cur = e
                res += 1
        return res
