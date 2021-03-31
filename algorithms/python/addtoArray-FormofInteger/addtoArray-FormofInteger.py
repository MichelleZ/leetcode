#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/add-to-array-form-of-integer/
# Author: Miao Zhang
# Date:   2021-03-31

class Solution:
    def addToArrayForm(self, A: List[int], K: int) -> List[int]:
        res = []
        i = len(A) - 1
        while i >= 0 or K > 0:
            K += (A[i] if i >= 0 else 0)
            res.append(K % 10)
            K //= 10
            i -= 1
        res.reverse()
        return res
