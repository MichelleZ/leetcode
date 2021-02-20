#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/longest-uncommon-subsequence-i/
# Author: Miao Zhang
# Date:   2021-02-19

class Solution:
    def findLUSlength(self, a: str, b: str) -> int:
        return -1 if a == b else max(len(a), len(b))
