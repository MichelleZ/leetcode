#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/expressive-words/
# Author: Miao Zhang
# Date:   2021-03-12

class Solution:
    def expressiveWords(self, S: str, words: List[str]) -> int:
        res = 0
        m = len(S)
        n = len(words)
        for word in words:
            i = 0
            j = 0
            while i < m:
                if j < len(word) and S[i] == word[j]: j += 1
                elif i > 0 and S[i] == S[i - 1] and i + 1 < m and S[i] == S[i + 1]:
                    i += 1
                elif not (i > 1 and S[i] == S[i - 1] and S[i] == S[i - 2]):
                    break
                i += 1
            if i == m and j == len(word): res += 1
        return res
