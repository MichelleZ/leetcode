#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/palindrome-pairs/
# Author: Miao Zhang
# Date:   2021-02-03

class Solution:
    def palindromePairs(self, words: List[str]) -> List[List[int]]:
        '''
        1 word is palindrome and "" in words
        2 reversed(word) in words
        3 word-> left, right, left is palindrome, reversed(right) in words
                              right is palindrome, reversed(left) in words
        '''
        wmap = {w: i for i, w in enumerate(words)}
        
        def isPalindrome(word):
            for i in range(len(word) // 2):
                if word[i] != word[len(word) - i - 1]:
                    return False
            return True
        
        res = set()
        for i, word in enumerate(words):
            if word and isPalindrome(word) and "" in wmap:
                j = wmap[""]
                res.add((i, j))
                res.add((j, i))
            
            rword = word[::-1]
            if word and rword in wmap:
                j = wmap[rword]
                if i != j:
                    res.add((i, j))
                    res.add((j, i))
            
            for j in range(1, len(word)):
                left, right = word[:j], word[j:]
                rleft, rright = left[::-1], right[::-1]
                if isPalindrome(left) and rright in wmap:
                    res.add((wmap[rright], i))
                if isPalindrome(right) and rleft in wmap:
                    res.add((i, wmap[rleft]))
        return list(res)
