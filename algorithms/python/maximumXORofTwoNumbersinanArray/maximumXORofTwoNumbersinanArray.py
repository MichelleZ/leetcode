#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
# Author: Miao Zhang
# Date:   2021-02-10

class Solution:
    def findMaximumXOR(self, nums: List[int]) -> int:
        res = mask = 0
        for i in range(31, -1, -1):
            mask += 1 << i
            prefixset = set([n & mask for n in nums])
            tmp = res | 1 << i
            for prefix in prefixset:
                if tmp ^ prefix in prefixset:
                    res = tmp
                    break
        return res
