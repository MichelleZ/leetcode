#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-adjacent-swaps-to-reach-the-kth-smallest-number/
# Author: Miao Zhang
# Date:   2021-06-11

class Solution:
    def getMinSwaps(self, num: str, k: int) -> int:
        def nextPermutation(num: List[str]) -> None:
            i = len(num) - 2
            while i >= 0 and num[i] >= num[i + 1]:
                i -= 1
            if i < 0: return num.sort()
            j = len(num) - 1
            while j >= 0 and num[i] >= num[j]:
                j -= 1
            num[i], num[j] = num[j], num[i]
            num[i + 1:] = sorted(num[i + 1:])

        num = list(num)
        numk = num[:]
        for i in range(k):
            nextPermutation(numk)
        n = len(num)
        res = 0
        for i in range(n):
            if num[i] != numk[i]:
                for j in range(i + 1, n):
                    if num[j] == numk[i]:
                        for k in range(j - 1, i - 1, -1):
                            res += 1
                            num[k], num[k + 1] = num[k + 1], num[k]
                        break
        return res

