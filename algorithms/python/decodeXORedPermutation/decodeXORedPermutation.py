#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/decode-xored-permutation/
# Author: Miao Zhang
# Date:   2021-06-02

class Solution:
    def decode(self, encoded: List[int]) -> List[int]:
        n = len(encoded) + 1
        perm = [0] * n
        for i in range(1, n + 1):
            perm[0] ^= i
        for i in range(1, n, 2):
            perm[0] ^= encoded[i]
        for i in range(1, n):
            perm[i] = perm[i - 1] ^ encoded[i - 1]
        return perm
