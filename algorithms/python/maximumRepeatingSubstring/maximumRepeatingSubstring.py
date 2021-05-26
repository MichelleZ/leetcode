#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-repeating-substring/
# Author: Miao Zhang
# Date:   2021-05-26

class Solution:
    def maxRepeating(self, sequence: str, word: str) -> int:
        s = word
        i = 1
        while True:
            if s not in sequence:
                return i - 1
            s += word
            i += 1
        return -1
