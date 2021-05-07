#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/
# Author: Miao Zhang
# Date:   2021-05-07

class Solution:
    def countTriplets(self, arr: List[int]) -> int:
        n = len(arr)
        xors = [0] * (n + 1)
        for i in range(n):
            xors[i + 1] = xors[i] ^ arr[i]
        res = 0
        for i in range(n):
            for k in range(i + 1, n):
                if xors[k + 1] == xors[i]:
                    res += k - i
        return res
