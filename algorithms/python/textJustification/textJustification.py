#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/text-justification/
# Author: Miao Zhang
# Date:   2021-01-13

class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        res = [] # result
        cur = [] # current line, words, len(cur) - 1 means space
        cnt = 0  # the size of words
        
        for w in words:
            #  the len of words + the len of spaces(at least one) + new word 
            if cnt + len(cur) + len(w) > maxWidth:
                # the len of total spaces
                for i in range(maxWidth - cnt):
                    cur[i % (len(cur) - 1 or 1)] += ' '
                res.append(''.join(cur))
                cur = []
                cnt = 0
            
            cur.append(w)
            cnt += len(w)
        for i in range(len(cur) - 1):
            cur[i] += ' '
        res.append(''.join(cur).ljust(maxWidth))
        return res
        
