#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/subarray-sums-divisible-by-k/
# Author: Miao Zhang
# Date:   2021-03-30

class Solution:
    def subarraysDivByK(self, A: List[int], K: int) -> int:
        record = {0: 1}
        sums = 0
        res = 0
        for a in A:
            sums += a
            key = sums % K
            cnt = record.get(key, 0)
            res += cnt
            record[key] = cnt + 1
        return res
