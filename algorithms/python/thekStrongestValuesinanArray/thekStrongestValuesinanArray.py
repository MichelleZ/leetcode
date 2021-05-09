#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/the-k-strongest-values-in-an-array/
# Author: Miao Zhang
# Date:   2021-05-09

class Solution:
    def getStrongest(self, arr: List[int], k: int) -> List[int]:
        n = len(arr)
        arr.sort()
        m = arr[(n - 1) // 2]
        res = []
        l, r = 0, n - 1
        while k > 0:
            if arr[r] - m >= m - arr[l]:
                res.append(arr[r])
                r -= 1
            else:
                res.append(arr[l])
                l += 1
            k -= 1
        return res
