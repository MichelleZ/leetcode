#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/count-good-triplets/
# Author: Miao Zhang
# Date:   2021-05-14

class Solution:
    def countGoodTriplets(self, arr: List[int], a: int, b: int, c: int) -> int:
        n = len(arr)
        res = 0
        for i in range(n):
            for j in range(i + 1, n):
                for k in range(j + 1, n):
                    if (abs(arr[i] - arr[j]) <= a and
                       abs(arr[j] - arr[k]) <= b and
                       abs(arr[i] - arr[k]) <= c):
                        res += 1
        return res
