#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/palindrome-partitioning/
# Author: Miao Zhang
# Date:   2021-01-20

class Solution:
    def partition(self, s: str) -> List[List[str]]:
        self.isPalindrome = lambda s: s == s[::-1]
        res = []
        self.dfs(s, res, [])
        return res
    
    def dfs(self, s: str, res: List[List[str]], path: List[str]) -> None:
        if not s:
            res.append(path)
            return
        for i in range(1, len(s) + 1):
            if self.isPalindrome(s[:i]):
                self.dfs(s[i:], res, path + [s[:i]])
