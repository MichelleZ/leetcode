#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/construct-k-palindrome-strings/
# Author: Miao Zhang
# Date:   2021-04-29

class Solution:
    def canConstruct(self, s: str, k: int) -> bool:
        if k > len(s): return False
        cnt = [0] * 26
        for c in s:
            cnt[ord(c) - ord('a')] ^= 1
        return k >= sum(cnt)
