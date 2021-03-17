#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/guess-the-word/
# Author: Miao Zhang
# Date:   2021-03-17

# """
# This is Master's API interface.
# You should not implement it, or speculate about its implementation
# """
# class Master:
#     def guess(self, word: str) -> int:

class Solution:
    def findSecretWord(self, wordlist: List[str], master: 'Master') -> None:
        
        def match(a, b):
            res = 0
            for i in range(len(a)):
                if a[i] == b[i]: res += 1
            return res
        
        cnt = 0
        i = 0
        while i < 10 and cnt < 6:
            guess = wordlist[random.randint(0, len(wordlist) - 1)]
            cnt = master.guess(guess)
            words = []
            for w in wordlist:
                if match(guess, w) == cnt:
                    words.append(w)
            wordlist = words
            i += 1
        
