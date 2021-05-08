#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/
# Author: Miao Zhang
# Date:   2021-05-08

class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        s = sentence.split()
        for i, word in enumerate(s):
            if word.startswith(searchWord):
                return i + 1
        return -1
