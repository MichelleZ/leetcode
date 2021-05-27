#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/count-the-number-of-consistent-strings/
# Author: Miao Zhang
# Date:   2021-05-27

class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        return sum(all(c in allowed for c in w) for w in words)
