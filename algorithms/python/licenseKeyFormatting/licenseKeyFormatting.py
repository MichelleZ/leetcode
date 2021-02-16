#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/license-key-formatting/
# Author: Miao Zhang
# Date:   2021-02-15

class Solution:
    def licenseKeyFormatting(self, S: str, K: int) -> str:
        res = []
        s = ''.join(S.split('-')).upper()
        n = len(s)
        if n % K != 0:
            res.append(s[: n % K])
        for i in range(n % K, n, K):
            res.append(s[i : i + K])
        return '-'.join(res)
