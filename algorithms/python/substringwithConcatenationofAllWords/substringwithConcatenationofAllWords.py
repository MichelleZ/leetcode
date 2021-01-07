#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/substring-with-concatenation-of-all-words/
# Author: Miao Zhang
# Date:   2021-01-07

class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        from collections import Counter
        if len(words) == 0:
            return []
        
        words_dict = Counter(words)
        
        n, lenOfWord, numsOfWord = len(s), len(words[0]), len(words)
        res = []
        
        for left in range(n - lenOfWord * numsOfWord + 1):
            right = 0
            cur_dict = Counter()
            
            while right < numsOfWord:
                word = s[left + lenOfWord * right: left + lenOfWord * right + lenOfWord]
                if word not in words:
                    break
                cur_dict[word] += 1
                if cur_dict[word] > words_dict[word]:
                    break
                right += 1
            
            if right == numsOfWord:
                res.append(left)

        return res
