#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/
# Author: Miao Zhang
# Date:   2021-04-01

class Solution:
    def minDominoRotations(self, A: List[int], B: List[int]) -> int:
        res = float('inf')
        for r in range(1, 7):
            flag = True
            cnta = 0
            cntb = 0
            for i in range(len(A)):
                if A[i] != r and B[i] != r:
                    flag = False
                    break
                elif A[i] == r and B[i] == r:
                    continue
                elif A[i] == r:
                    cnta += 1
                elif B[i] == r:
                    cntb += 1
            if flag: res = min(res, min(cnta, cntb))
        return -1 if res == float('inf') else res
