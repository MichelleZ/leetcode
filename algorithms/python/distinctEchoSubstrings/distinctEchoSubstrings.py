#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/distinct-echo-substrings/
# Author: Miao Zhang
# Date:   2021-04-23

class Solution:
    def distinctEchoSubstrings(self, text: str) -> int:
        n = len(text)
        s = set()
        for k in range(1, n // 2 + 1):
            i = 0
            while i + k <= n:
                if text[i: i + k] == text[i + k: i + 2 * k]:
                    s.add(text[i: i + 2 * k])
                i += 1
        return len(s)
