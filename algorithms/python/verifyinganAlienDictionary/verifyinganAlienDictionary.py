#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/verifying-an-alien-dictionary/
# Author: Miao Zhang
# Date:   2021-03-28

class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        order_idx = {c: i for i, c in enumerate(order)}
        
        for i in range(len(words) - 1):
            word1 = words[i]
            word2 = words[i + 1]
            for k in range(min(len(word1), len(word2))):
                if word1[k] != word2[k]:
                    if order_idx[word1[k]] > order_idx[word2[k]]:
                        return False
                    break
            else:
                if len(word1) > len(word2):
                    return False
        
        return True
