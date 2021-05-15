#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/thousand-separator/
# Author: Miao Zhang
# Date:   2021-05-15

class Solution:
    def thousandSeparator(self, n: int) -> str:
        res = []
        cnt = 0
        while True:
            cur = n % 10
            n //= 10
            res.append(str(cur))
            cnt += 1
            if cnt % 3 == 0 and n > 0:
                res.append('.')
            if n == 0:
                break
        return ''.join(res[::-1])

