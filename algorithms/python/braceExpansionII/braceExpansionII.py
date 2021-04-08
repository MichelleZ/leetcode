#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/brace-expansion-ii/
# Author: Miao Zhang
# Date:   2021-04-08

class Solution:
    def braceExpansionII(self, expression: str) -> List[str]:
        res = []
        visited = set()
        stack = []
        stack.append(expression)
        while stack:
            s = stack.pop()
            if s.find('{') == -1:
                if s not in visited:
                    visited.add(s)
                    res.append(s)
                continue
            i, left, right = 0, 0, 0
            while s[i] != '}':
                if s[i] == '{': left = i
                i += 1
            right = i
            before = s[:left]
            after = s[right+1:]
            mid = s[left + 1: right]
            for c in mid.split(','):
                stack.append(before + c + after)
        res.sort()
        return res
