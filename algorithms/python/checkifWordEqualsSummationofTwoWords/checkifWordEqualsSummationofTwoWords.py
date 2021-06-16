#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/check-if-word-equals-summation-of-two-words/
# Author: Miao Zhang
# Date:   2021-06-16

class Solution:
    def isSumEqual(self, firstWord: str, secondWord: str, targetWord: str) -> bool:
        def transfer(s: str) -> int:
            res = 0
            for c in s:
                res *= 10
                res += ord(c) - ord('a')
            return res
        return transfer(firstWord) + transfer(secondWord) == transfer(targetWord)
