#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-number-of-operations-to-reinitialize-a-permutation/
# Author: Miao Zhang
# Date:   2021-06-09

class Solution:
    def reinitializePermutation(self, n: int) -> int:
        perm = [i for i in range(n)]
        arr = [0 for _ in range(n)]
        res = 0
        flag = True
        while flag:
            flag = False
            for i in range(n):
                arr[i] = perm[n // 2 + (i - 1) // 2] if i & 1 else perm[i // 2]
                flag |= arr[i] != i
            res += 1
            perm, arr = arr, perm
        return res
