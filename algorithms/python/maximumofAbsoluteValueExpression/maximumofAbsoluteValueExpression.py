#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-of-absolute-value-expression/
# Author: Miao Zhang
# Date:   2021-04-12

class Solution:
    def maxAbsValExpr(self, arr1: List[int], arr2: List[int]) -> int:
        A, B, C, D = [], [], [], []
        for i in range(len(arr1)):
            x, y = arr1[i], arr2[i]
            A.append(x + y + i)
            B.append(x + y - i)
            C.append(x - y + i)
            D.append(x - y - i)
        a = max(A) - min(A)
        b = max(B) - min(B)
        c = max(C) - min(C)
        d = max(D) - min(D)
        return max(a, b, c, d)
