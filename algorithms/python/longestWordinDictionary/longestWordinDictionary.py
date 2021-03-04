#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/longest-word-in-dictionary/
# Author: Miao Zhang
# Date:   2021-03-03

class Solution:
    def longestWord(self, words: List[str]) -> str:
        res = ''
        wordset = set(words)
        for word in words:
            if len(word) > len(res) or (len(word) == len(res) and word < res):
                if all(word[:k] in wordset for k in range(1, len(word))):
                    res = word
        return res
