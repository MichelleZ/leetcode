#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/longest-uncommon-subsequence-ii/
# Author: Miao Zhang
# Date:   2021-02-19

class Solution:
    def findLUSlength(self, strs: List[str]) -> int:
        res = -1
        n = len(strs)
        for i in range(n):
            is_flag = False
            for j in range(n):
                if i == j: continue
                if self.check(strs[i], strs[j]):
                    is_flag = True
            if not is_flag:
                res = max(res, len(strs[i]))
        return res
    
    def check(self, str1: str, str2: str) -> bool:
        i = 0
        for j in range(len(str2)):
            if str1[i] == str2[j]: i += 1
            if i == len(str1): break
        return i == len(str1)
