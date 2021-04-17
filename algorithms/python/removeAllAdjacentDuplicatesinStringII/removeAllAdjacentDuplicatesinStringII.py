#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/
# Author: Miao Zhang
# Date:   2021-04-17

class Solution:
    def removeDuplicates(self, s: str, k: int) -> str:
        stack = [['*', 0]]
        for c in s:
            if c != stack[-1][0]:
                stack.append([c, 1])
            else:
                stack[-1][1] += 1
                if stack[-1][1] == k:
                    stack.pop()
        res = ''
        for st in stack:
            res += st[0] * st[1]
        return res
