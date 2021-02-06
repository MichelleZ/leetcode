#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/longest-absolute-file-path/
# Author: Miao Zhang
# Date:   2021-02-06

class Solution:
    def lengthLongestPath(self, input: str) -> int:
        # The depth of the directory, the current total string length
        stack = [(-1, 0)]
        res = 0
        for section in input.split('\n'):
            depth = section.count('\t')
            section = section.replace('\t', '')
            while stack and depth <= stack[-1][0]:
                stack.pop()
            if '.' not in section:
                stack.append((depth, len(section) + 1 + stack[-1][1]))
            else:
                res = max(res, len(section) + stack[-1][1])
        return res
