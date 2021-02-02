#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/remove-duplicate-letters/
# Author: Miao Zhang
# Date:   2021-02-02

class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        from collections import Counter
        from collections import defaultdict
        count = Counter(s)
        stack = []
        visited = defaultdict(bool)
        for c in s:
            count[c] -= 1
            if visited[c]:
                continue
            while stack and count[stack[-1]] and stack[-1] > c:
                visited[stack[-1]] = False
                stack.pop()
            visited[c] = True
            stack.append(c)
        return ''.join(stack)
