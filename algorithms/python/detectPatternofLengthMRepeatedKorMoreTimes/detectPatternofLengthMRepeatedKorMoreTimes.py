#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/detect-pattern-of-length-m-repeated-k-or-more-times/
# Author: Miao Zhang
# Date:   2021-05-16

class Solution:
    def containsPattern(self, arr: List[int], m: int, k: int) -> bool:
        n = len(arr)
        cnt = 0
        for i in range(0, n - m):
            if arr[i] == arr[i + m]:
                cnt += 1
                if cnt == (k - 1) * m:
                    return True
            else:
                cnt = 0
        return False
