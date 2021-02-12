#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/string-compression/
# Author: Miao Zhang
# Date:   2021-02-12

class Solution:
    def compress(self, chars: List[str]) -> int:
        n = len(chars)
        j = 0
        i = 1
        while i <= n:
            cnt = 1
            while i < n and chars[i] == chars[i - 1]:
                i += 1
                cnt += 1
            chars[j] = chars[i - 1]
            j += 1
            i += 1
            if cnt == 1: continue
            for c in str(cnt):
                chars[j] = c
                j += 1
        return j
