#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/beautiful-arrangement-ii/
# Author: Miao Zhang
# Date:   2021-02-27

class Solution:
    def constructArray(self, n: int, k: int) -> List[int]:
        res = []
        l, r = 1, n
        while l <= r:
            if k > 1:
                if k % 2 == 1:
                    res.append(l)
                    l += 1
                else:
                    res.append(r)
                    r -= 1
                k -= 1
            else:
                res.append(l)
                l += 1
        return res
