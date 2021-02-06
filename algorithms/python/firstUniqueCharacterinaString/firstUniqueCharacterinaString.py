#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/first-unique-character-in-a-string/
# Author: Miao Zhang
# Date:   2021-02-06

class Solution:
    def firstUniqChar(self, s: str) -> int:
        count = collections.Counter(s)
        for i in range(len(s)):
            if count[s[i]] == 1:
                return i
        return -1
