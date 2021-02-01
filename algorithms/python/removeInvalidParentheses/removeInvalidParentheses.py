#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/remove-invalid-parentheses/
# Author: Miao Zhang
# Date:   2021-02-01

class Solution:
    def removeInvalidParentheses(self, s: str) -> List[str]:
        l = 0
        r = 0
        for c in s:
            if c == '(': l += 1
            if c == ')': 
                if l == 0:
                    r += 1
                else:
                    l -= 1
        res = []
        self.dfs(s, 0, l, r, res)
        return res
    
    def isValid(self, s: str) -> bool:
        cnt = 0
        for c in s:
            if c == '(':
                cnt += 1
            if c == ')':
                cnt -= 1
            if cnt < 0:
                return False
        return cnt == 0
    
    def dfs(self, s: str, start: int, l: int, r: int, res: List[str]) -> None:
        if l == 0 and r == 0:
            if self.isValid(s):
                res.append(s)
                return
        for i in range(start, len(s)):
            if i != start and s[i] == s[i - 1]: continue
            if r > 0 and s[i] == ')':
                self.dfs(s[:i] + s[i + 1:], i, l, r - 1, res)
            if l > 0 and s[i] == '(':
                self.dfs(s[:i] + s[i + 1:], i, l - 1, r, res)
