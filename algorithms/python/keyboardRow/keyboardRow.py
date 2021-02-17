#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/keyboard-row/
# Author: Miao Zhang
# Date:   2021-02-17

class Solution:
    def findWords(self, words: List[str]) -> List[str]:
        rows = ["qwertyuiop", "asdfghjkl", "zxcvbnm"]
        res = []
        for w in words:
            for r in rows:
                if self.check(w, r):
                    res.append(w)
                    break
        return res
    
    def check(self, word: str, row: str) -> bool:
        for w in word:
            if not w.lower() in row: return False
        return True
