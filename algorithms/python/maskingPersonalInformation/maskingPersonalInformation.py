#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/masking-personal-information/
# Author: Miao Zhang
# Date:   2021-03-16

class Solution:
    def maskPII(self, S: str) -> str:
        res = ''
        tmp = ''
        if '@' in S:
            idx = S.index('@')
            res = S[0:1].lower() + '*****' + S[idx - 1:].lower()
        else:
            for c in S:
                if '0' <= c <= '9': tmp += c
            n = len(tmp)
            if n > 10:
                res += '+' + '*' * (n - 10) + '-'
            res += '***-***-' + tmp[-4:]
        return res
