#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/
# Author: Miao Zhang
# Date:   2021-04-01

class Solution:
    def isValid(self, s: str) -> bool:
        q = deque()
        for i in range(len(s)):
            if s[i] != 'c':
                q.append(s[i])
            else:
                if len(q) >= 2 and q[-1] == 'b' and q[-2] == 'a':
                    q.pop()
                    q.pop()
                else:
                    return False
        return len(q) == 0
