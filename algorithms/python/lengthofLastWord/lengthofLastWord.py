#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/length-of-last-word/
# Author: Miao Zhang
# Date:   2021-01-12

class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        if len(s) == 0:
            return 0
        t = s.strip().split(" ")
        return len(t[-1])
