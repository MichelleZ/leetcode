#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/lexicographical-numbers/
# Author: Miao Zhang
# Date:   2021-02-06

class Solution:
    def lexicalOrder(self, n: int) -> List[int]:
        res = []
        cur = 1
        for i in range(n):
            res.append(cur)
            if cur * 10 <= n:
                cur *= 10
            else:
                if cur >= n:
                    cur //= 10
                cur += 1
                while cur % 10 == 0:
                    cur //= 10
        return res
