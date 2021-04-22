#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/xor-queries-of-a-subarray/
# Author: Miao Zhang
# Date:   2021-04-22

class Solution:
    def xorQueries(self, arr: List[int], queries: List[List[int]]) -> List[int]:
        xors = [0 for _ in range(len(arr) + 1)]
        for i in range(len(arr)):
            xors[i + 1] = xors[i] ^ arr[i]
        res = []
        for s, e in queries:
            res.append(xors[e + 1] ^ xors[s])
        return res
