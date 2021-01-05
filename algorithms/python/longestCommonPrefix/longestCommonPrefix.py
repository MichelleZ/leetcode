#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/longest-common-prefix/
# Author: Miao Zhang
# Date:   2021-01-05

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        res = ''
        if len(strs) == 0:
            return res
        for each in zip(*strs):
            if len(set(each)) == 1:
                res += each[0]
            else:
                return res
        return res
