#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/binary-prefix-divisible-by-5/
# Author: Miao Zhang
# Date:   2021-04-02

class Solution:
    def prefixesDivBy5(self, A: List[int]) -> List[bool]:
        res = [False] * len(A)
        num = 0
        for i in range(len(A)):
            num = (num << 1 | A[i]) % 5
            res[i] = num == 0
        return res
