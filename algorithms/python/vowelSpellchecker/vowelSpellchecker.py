#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/vowel-spellchecker/
# Author: Miao Zhang
# Date:   2021-03-29

class Solution:
    def spellchecker(self, wordlist: List[str], queries: List[str]) -> List[str]:
        words_org = set(wordlist)
        words_low = {}
        words_vow = {}
        for word in wordlist:
            wordlow = word.lower()
            words_low.setdefault(wordlow, word)
            words_vow.setdefault(self.replaceVowels(wordlow), word)
        
        def solve(query):
            if query in words_org:
                return query
            queryl = query.lower()
            if queryl in words_low:
                return words_low[queryl]
            queryv = self.replaceVowels(queryl)
            if queryv in words_vow:
                return words_vow[queryv]
            return ''

        return map(solve, queries)
        
    def replaceVowels(self, word):
        return "".join('*' if c in 'aeiou' else c for c in word)
    
