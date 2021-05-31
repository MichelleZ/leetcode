#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/decode-xored-array/
# Author: Miao Zhang
# Date:   2021-05-31

class Solution:
    def decode(self, encoded: List[int], first: int) -> List[int]:
        n = len(encoded) + 1
        res = [first] * n
        for i in range(n - 1):
            res[i + 1] = res[i] ^ encoded[i]
        return res
